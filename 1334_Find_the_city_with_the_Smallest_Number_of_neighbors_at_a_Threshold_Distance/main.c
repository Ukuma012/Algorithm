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
int count = 0;

struct node
{
    int val;
    int weight;
    struct node *next;
};

struct graph
{
    struct node *nodes[nodesize];
};

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

int dfs(struct graph *g, int x)
{
    visited[x] = 1;

    struct node *p;
    p = g->nodes[x];
    while (p != NULL)
    {
        if (visited[p->val] == 1)
        {
            p = p->next;
            continue;
        }
        push(p->val);
        p = p->next;
    }
    while (!(stack_pointer == 0))
    {
        int n = pop();
        dst += n;
        if (dst > distanceThreshold)
        {
            dst -= n;
            return 0;
        }
        else
        {
            if (dfs(g, n) == 1)
            {
                count++;
                return 1;
            }
        }
    }
    return 0;
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

    print_graph(g);

    dfs(g, 0);

    printf("%d\n", count);
    exit(0);
}