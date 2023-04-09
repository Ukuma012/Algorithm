#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define valsize 7

int vals[valsize] = {1,2,3,4,10,-10,-20};
int edges[12] = {0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 3, 6};

struct node {
    int val;
    struct node *next;
};

struct graph {
    struct node *nodes[valsize];
};

void insert_edge(struct graph *g, int number, int edge, bool directed)
{
    struct node *p, *q, *new;

    if ((new = malloc(sizeof(struct node))) == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    };

    new->val = vals[edge];
    new->next = NULL;

    p = g->nodes[number];
    q = NULL;

    while(p != NULL && new->val < p->val) {
        q = p;
        p = p->next;
    }

    if(q == NULL) {
        new->next = g->nodes[number];
        g->nodes[number] = new;
    } else {
        new->next = q->next;
        q->next = new;
    }

    if (directed == false)
    {
        insert_edge(g, edge, number, true);
    }
}

void print_graph(struct graph *g) {
    struct node *p;
    if ((p = malloc(sizeof(struct node))) == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }
    for(int i = 0; i < valsize; i++) {
        p = g->nodes[i];
        while(p != NULL) {
            printf("%d ", p->val);
            p = p->next;
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {

    bool directed = false;

    struct graph *g;
    if ((g = malloc(sizeof(struct graph))) == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    for(int i = 0; i < (sizeof(edges) / sizeof(int)); i+=2) {
        insert_edge(g, edges[i], edges[i+1], directed);
    }

    print_graph(g);

    exit(0);
}