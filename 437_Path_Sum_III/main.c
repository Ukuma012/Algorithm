#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int value)
{
    struct TreeNode *p;
    if ((p = malloc(sizeof(struct TreeNode))) == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    p->val = value;
    p->left = NULL;
    p->right = NULL;

    return p;
}

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        fprintf(stderr, "argument!");
        exit(0);
    }

    int targetSum = *argv[1] - 48;

    printf("%d\n", targetSum);
    exit(0);
}