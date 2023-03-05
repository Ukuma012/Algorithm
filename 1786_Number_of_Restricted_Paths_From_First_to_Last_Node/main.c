#include <stdio.h>
#include <stdlib.h>

// まずはadjacency list of a given graphを作る

// graph
#define MAXV 20000 // 2 * 10^4

// @TODO 入力を受け取るように
int input[21] = {1, 2, 3, 1, 3, 3, 2, 3, 1, 1, 4, 2, 5, 2, 2, 3, 5, 1, 5, 4, 10};

typedef struct
{
    int y;
    int weight;
    struct edgenode *next;
} edgenode;

typedef struct
{
    edgenode *edges[MAXV + 1];
    int degree[MAXV + 1];
    int nvertices;
    int nedges;
} graph;

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    if (n > MAXV)
    {
        fprintf(stderr, "too many nodes\n");
        exit(1);
    }

    for(int j = 0; j < 21; j++) {
        printf("%d ", input[j]);
    }


    return 0;
}