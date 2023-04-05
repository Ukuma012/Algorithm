#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define edgesSize 7
#define stackSize 1000

int input[edgesSize * 2] = {1, 2, 1, 3, 1, 7, 2, 4, 2, 6, 3, 5};
int t = 2;
int target = 4;

int pointer = 0;
int visited[edgesSize + 1];
int stack[stackSize];

struct edgenode
{
    int val;
    struct edgenode *next;
};

struct graph
{
    struct edgenode *edges[edgesSize + 1];
};

void push(int x)
{
    stack[pointer++] = x;
}

int pop()
{
    int n;
    n = stack[--pointer];
    return n;
}

void insert(struct graph *g, int x, int val, bool directed)
{
    struct edgenode *new;
    if ((new = malloc(sizeof(struct edgenode))) == NULL)
    {
        fprintf(stderr, "malloc faild\n");
        exit(1);
    }

    new->val = val;
    new->next = g->edges[x];
    g->edges[x] = new;

    if (directed == false)
    {
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
    for (i = 1; i < edgesSize + 1; i++)
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

int find(struct graph *g, int x)
{

    visited[x] = 1;
    struct edgenode *p;
    if ((p = malloc(sizeof(struct edgenode))) == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    p = g->edges[x];
    while (p != NULL)
    {
        if (visited[p->val] == 1)
        {
            p = p->next;
            continue;
        }
        else
        {
            push(p->val);
            p = p->next;
        }
    }

    while (!(pointer == 0))
    {
        int n = pop();
        if (n == target)
        {
            return 1;
        }
        else 
        {
            if(find(g, n) == 1) {
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

    for (int i = 0; i < (sizeof(input) / sizeof(int)); i += 2)
    {
        insert(g, input[i], input[i + 1], false);
    }

    print_graph(g);

    printf("%d\n", find(g, 1));

    exit(0);
}