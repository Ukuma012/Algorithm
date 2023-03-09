#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// #define MAXV 5
// #define MAXV 6
#define MAXV 7

#define MAXWEIGHT 100000
#define STACK_MAX 100000

int stack[STACK_MAX];
int n = 0;

// @TODO 入力を受け取るように
// int input[21] = {1, 2, 3, 1, 3, 3, 2, 3, 1, 1, 4, 2, 5, 2, 2, 3, 5, 1, 5, 4, 10};

// int input[27] = {1, 2, 5, 1, 5, 6, 2, 3, 3, 2, 4, 2, 3, 4, 4, 3, 6, 8, 4, 5, 3, 4, 6, 1, 5, 6, 9};

int input[24] = {1, 3, 1, 4, 1, 2, 7, 3, 4, 2, 5, 3, 5, 6, 1, 6, 7, 2, 7, 5, 3, 2, 6, 4};

struct edgenode
{
    int y;
    int weight;
    struct edgenode *next;
};

struct graph
{
    struct edgenode *edges[MAXV + 1];
    int shortestpath[MAXV + 1];
    bool finish[MAXV + 1];
};

void insert_edge(struct graph *g, int x, int y, int weight, bool directed);
void init_graph(struct graph *g);
void print_graph(struct graph *g);
void setshortest(struct graph *g, int);
int findshortest(struct graph *g);
void push(int);
int pop();

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

    setshortest(g, MAXV);
    for (int i = 1; i < MAXV; i++)
    {
        setshortest(g, findshortest(g));
    }
    print_graph(g);
    printf("\n");

    int seen[MAXV+1];
    int stack[STACK_MAX];
    



    return 0;
}

void push(int x)
{
    if (n >= STACK_MAX)
    {
        fprintf(stderr, "stack overflow\n");
        exit(1);
    }
    stack[n++] = x;
}

int pop()
{
    if (n <= 0)
    {
        fprintf(stderr, "no element\n");
        exit(1);
    }
    return stack[--n];
}

int findshortest(struct graph *g)
{
    int shortest = MAXWEIGHT;
    int j;
    for (int i = 1; i < MAXV + 1; i++)
    {
        int current;
        if (g->shortestpath[i] < 0 || g->finish[i] == true)
        {
            continue;
        }
        current = g->shortestpath[i];
        if (shortest > current)
        {
            shortest = current;
            j = i;
        }
    }
    return j;
}

void setshortest(struct graph *g, int target)
{

    struct edgenode *targetnode;
    if ((targetnode = malloc(sizeof(struct edgenode))) == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    targetnode = g->edges[target];
    while (targetnode != NULL)
    {
        int length = targetnode->weight + g->shortestpath[target];

        if (g->shortestpath[targetnode->y] == -1)
        {
            g->shortestpath[targetnode->y] = length;
        }
        else if (length < g->shortestpath[targetnode->y])
        {
            g->shortestpath[targetnode->y] = length;
        }
        targetnode = targetnode->next;
    }
    g->finish[target] = true;
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
        printf("%d %d %d: ", g->finish[i], g->shortestpath[i], i);
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
        g->shortestpath[i] = -1;
        g->finish[i] = false;
    }

    // MAXVのshortestpathは0
    g->shortestpath[MAXV] = 0;
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

    if (directed == false)
    {
        insert_edge(g, y, x, weight, true);
    }
}