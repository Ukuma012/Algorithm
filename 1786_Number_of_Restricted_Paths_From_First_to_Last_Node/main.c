#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//@TODO shortest pathを見つける

#define MAXV 5
// #define MAXV 6

// @TODO 入力を受け取るように
int input[21] = {1, 2, 3, 1, 3, 3, 2, 3, 1, 1, 4, 2, 5, 2, 2, 3, 5, 1, 5, 4, 10};

// int input[27] = {1, 2, 5, 1, 5, 6, 2, 3, 3, 2, 4, 2, 3, 4, 4, 3, 6, 8, 4, 5, 3, 4, 6, 1, 5, 6, 9};

struct edgenode
{
    int y;
    int weight;
    struct edgenode *next;
};

struct graph
{
    struct edgenode *edges[MAXV + 1];
};

void insert_edge(struct graph *g, int x, int y, int weight, bool directed);
void init_graph(struct graph *g);
void print_graph(struct graph *g);

int main(int argc, char *argv[])
{
    bool directed = false;

    struct graph *g;
    if ((g = malloc(sizeof(struct graph))) == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    init_graph(g);

    for (int j = 0; j < (sizeof(input) / sizeof(int)); j += 3)
    {
        insert_edge(g, input[j], input[j + 1], input[j + 2], directed);
    }

    print_graph(g);

    return 0;
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
    for (i = 1; i < MAXV + 1; i++)
    {
        printf("%d: ", i);
        p = g->edges[i];
        while (p != NULL)
        {
            printf("%d(%d) ", p->y, p->weight);
            p = p->next;
        }
        printf("\n");
    }
}

void init_graph(struct graph *g)
{
    int i;
    for (i = 1; i <= MAXV; i++)
    {
        g->edges[i] = NULL;
    }
}

void insert_edge(struct graph *g, int x, int y, int weight, bool directed)
{
    struct edgenode *p;
    if ((p = malloc(sizeof(struct edgenode))) == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    };

    p->y = y;
    p->weight = weight;
    p->next = g->edges[x];

    g->edges[x] = p;

    if(directed == false) {
    insert_edge(g, y, x, weight, true);
    }
}