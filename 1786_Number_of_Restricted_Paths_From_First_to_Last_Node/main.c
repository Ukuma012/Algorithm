#include <stdio.h>
// 入力を受ける
// まずはadjacency list of a given graphを作る

// graph
#define MAXV 20000 // 2 * 10^4

typedef struct {
    int y;
    int weight;
    struct edgenode *next;
} edgenode;

typedef struct {
    edgenode *edges[MAXV+1];
    int degree[MAXV+1];
    int nvertices;
    int nedges;
} graph;

int main(int argc, char *argv[]) {
    printf("%s\n", "Hello World");
    return 0;
}