#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *right;
    struct TreeNode *left;
};

struct TreeNode *createNode(int val)
{
    struct TreeNode *new;
    if ((new = malloc(sizeof(struct TreeNode))) == NULL)
    {
        fprintf(stderr, "malloc faild\n");
        exit(1);
    }

    new->val = val;
    new->left = NULL;
    new->right = NULL;

    return new;
}

int main(int argc, char *argv[])
{
    printf("%s\n", "Hello");
    exit(0);
}