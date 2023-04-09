#include <stdio.h>
#include <stdlib.h>

#define valsize 7

struct TreeNode {
    int number;
    int val;
};

struct graph {
    struct TreeNode *nodes[valsize];
};

int main(int argc, char *argv[]) {
    printf("%s\n", "Hello World");
    exit(0);
}