#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* generateNode(int val) {
    struct TreeNode *new;
    if((new = malloc(sizeof(struct TreeNode))) == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    new->val = val;
    new->left = NULL;
    new->right = NULL;

    return new;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);



    printf("%d\n", n);
    exit(0);
}