#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define nodesize 5
#define edgesize 18
#define distanceThreshold 2

int edges[edgesize] = {0, 1, 2, 0, 4, 8, 1, 2, 3, 1, 4, 2, 2, 3, 1, 3, 4, 1};

int stack_pointer = 0;
int stack[1000];
int visited[1000];
int dst = 0;

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
};

void init(struct graph *g)
{
    for (int i = 0; i < nodesize; i++)
    {
        g->processed[i] = false;
        g->shortest[i] = -1;
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
        printf("%d %d(%d): ", g->processed[i], i, g->shortest[i]);
        while (p != NULL)
        {
            printf("%d(%d) ", p->val, p->weight);
            p = p->next;
        }
        printf("\n");
    }
}

void push(int val)
{
    stack[stack_pointer++] = val;
}

int pop()
{
    int n;
    n = stack[--stack_pointer];
    return n;
}

int find_shortest(struct graph *g)
{
    int shortest = INT16_MAX;
    int ans = 0;
    for (int i = 0; i < nodesize; i++)
    {
        if (g->processed[i] == true)
        {
            continue;
        }
        else
        {
            if (g->shortest[i] == -1)
            {
                continue;
            }
            else
            {
                if (shortest > g->shortest[i])
                {
                    shortest = g->shortest[i];
                    ans = i;
                }
            }
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{
    struct graph *g;
    if ((g = malloc(sizeof(struct graph))) == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    for (int i = 0; i < (sizeof(edges) / sizeof(int)); i += 3)
    {
        insert_edge(g, edges[i], edges[i + 1], edges[i + 2], false);
    }

    init(g);

    print_graph(g);

    exit(0);
}