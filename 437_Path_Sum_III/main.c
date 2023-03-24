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

void insertleft(struct TreeNode* node, int value) {
    struct TreeNode *new;
    if ((new = malloc(sizeof(struct TreeNode))) == NULL) {
        fprintf(stderr, "mlloc failed\n");
        exit(1);
    }

    new->left = NULL;
    new->right = NULL;
    new->val = value;

    node->left = new;
}

void insertright(struct TreeNode* node, int value) {
    struct TreeNode *new;
    if ((new = malloc(sizeof(struct TreeNode))) == NULL) {
        fprintf(stderr, "mlloc failed\n");
        exit(1);
    }

    new->left = NULL;
    new->right = NULL;
    new->val = value;

    node->right = new;
}

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        fprintf(stderr, "argument!");
        exit(0);
    }

    int targetSum = *argv[1] - 48;
    // root = [10, 5, -3, 3, 2, null, 11, 3, -2, null, 1]
    struct TreeNode* root = createNode(10);
    insertleft(root, 5);
    insertright(root, -3);
    insertleft(root->left, 3);
    insertright(root->left, 2);

    insertright(root->right, 11);
    insertleft(root->left->left, 3);
    insertright(root->left->left, -2);

    insertright(root->left->right, 1);


    printf("%d\n", root->left->val);
    printf("%d\n", root->right->val);
    printf("%d\n", root->right->right->val);
    printf("%d\n", root->left->right->val);
    exit(0);
}