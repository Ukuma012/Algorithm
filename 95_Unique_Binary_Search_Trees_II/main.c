#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *root = NULL;

void insertkey(int key)
{
    struct TreeNode **node;
    node = &root;
    while (*node != NULL)
    {
        if ((*node)->val < key)
        {
            node = &(*node)->right;
        }
        else if ((*node)->val > key)
        {
            node = &(*node)->left;
        }
    }
    struct TreeNode *new;
    if ((new = malloc(sizeof(struct TreeNode))) == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    new->val = key;
    new->left = NULL;
    new->right = NULL;

    *node = new;
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    if ((root = malloc(sizeof(struct TreeNode))) == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }
    root->val = 1;
    root->left = NULL;
    root->right = NULL;
    exit(0);
}