#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);

    printf("%d\n", n);
    exit(0);
}