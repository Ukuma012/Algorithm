#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define edgesSize 7

int input[edgesSize * 2] = {1, 2, 1, 3, 1, 7, 2, 4, 2, 6, 3, 5};

struct edgenode {
    int val;
    struct edgenode *next;
};

struct graph {
    struct edgenode *edges[edgesSize+1];
};

void insert(struct graph *g, int x, int val, bool directed) {
    struct edgenode *new;
    if((new = malloc(sizeof(struct edgenode))) == NULL) {
        fprintf(stderr, "malloc faild\n");
        exit(1);
    }

    new->val = val;
    new->next = g->edges[x];
    g->edges[x] = new;

    if(directed == false) {
        insert(g, val, x, true);
    }
}

void print_graph(struct graph *g)
{
    int i;
    struct edgenode *p;
    if ((p = malloc(sizeof(struct edgenode))) == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }
    for (i = 1; i < edgesSize+1; i++)
    {
        printf("%d: ", i);
        p = g->edges[i];
        while (p != NULL)
        {
            printf("%d ", p->val);
            p = p->next;
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {

    struct graph *g;
    if((g = malloc(sizeof(struct graph))) == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    for(int i = 0; i < (sizeof(input) / sizeof(int)); i += 2) {
        insert(g, input[i], input[i+1], false);
    }

    print_graph(g);

    exit(0);
}