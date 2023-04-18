#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n = 11;
int x = 3;

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

bool check(struct TreeNode *root, int x)
{
    if (x == root->val)
    {
        return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    struct TreeNode *root = createNode(1);
    struct TreeNode *node2 = createNode(2);
    struct TreeNode *node3 = createNode(3);
    struct TreeNode *node4 = createNode(4);
    struct TreeNode *node5 = createNode(5);
    struct TreeNode *node6 = createNode(6);
    struct TreeNode *node7 = createNode(7);
    struct TreeNode *node8 = createNode(8);
    struct TreeNode *node9 = createNode(9);
    struct TreeNode *node10 = createNode(10);
    struct TreeNode *node11 = createNode(11);

    root->left = node2;
    root->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->left = node6;
    node3->right = node7;

    node4->left = node8;
    node4->right = node9;

    node5->left = node10;
    node5->right = node11;

    if (!check(root, 1))
    {
        printf("%s\n", "false");
    }

    exit(0);
}