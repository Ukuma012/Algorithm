#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define nodesize 7
#define roadssize 30

int roads[roadssize] = {0, 6, 7, 0, 1, 2, 1, 2, 3, 1, 3, 3, 6, 3, 3, 3, 5, 1, 6, 5, 1, 2, 5, 1, 0, 4, 5, 4, 6, 2};

int target = 7;
struct node
{
    int val;
    int weight;
    struct node *next;
};

struct graph
{
    struct node *nodes[nodesize];
    bool processed[nodesize];
    int shortest[nodesize];
    int ways[nodesize];
};

void graph_init(struct graph *g)
{
    for (int i = 0; i < nodesize; i++)
    {
        g->nodes[i] = NULL;
        g->processed[i] = false;
        g->shortest[i] = -1;
        g->ways[i] = 0;
    }
}

int find_shortest(struct graph *g)
{
    int min = 0;
    for (int i = 0; i < nodesize; i++)
    {
        if (g->processed[i] == true || g->shortest[i] == -1)
        {
            continue;
        }
        if (g->shortest[i] < min)
        {
            min = g->shortest[i];
        }
    }
    return min;
}

void dijkstra(struct graph *g, int x)
{
    g->processed[x] = true;
    struct node *p;
    if ((p = malloc(sizeof(struct node))) == NULL)
    {
        fpritnf(stderr, "malloc failed\n");
        exit(1);
    }
    p = g->nodes[x];
    while (p != NULL)
    {
        int n = g->shortest[x] + p->weight;
        if (g->shortest[p->val] == -1)
        {
            g->shortest[p->val] = n;
            g->ways[p->val] = g->ways[x];
        }
        else if (n <= g->shortest[p->val])
        {
            g->shortest[p->val] = n;
            g->ways[p->val] += g->ways[x];
        }
        p = p->next;
    }
}

void insert_edge(struct graph *g, int from_edge, int to_edge, int weight, bool directed)
{
    struct node *new;

    if ((new = malloc(sizeof(struct node))) == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    };

    new->val = to_edge;
    new->weight = weight;

    new->next = g->nodes[from_edge];
    g->nodes[from_edge] = new;

    if (directed == false)
    {
        insert_edge(g, to_edge, from_edge, weight, true);
    }
}

void print_graph(struct graph *g)
{
    struct node *p;
    if ((p = malloc(sizeof(struct node))) == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }
    for (int i = 0; i < nodesize; i++)
    {
        p = g->nodes[i];
        printf("%d: ", i);
        while (p != NULL)
        {
            printf("%d(%d) ", p->val, p->weight);
            p = p->next;
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    struct graph *g;
    if ((g = malloc(sizeof(struct graph))) == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    graph_init(g);

    for (int i = 0; i < roadssize; i += 3)
    {
        insert_edge(g, roads[i], roads[i + 1], roads[i + 2], false);
    }

    print_graph(g);

    exit(0);
}