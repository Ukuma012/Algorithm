#include <stdio.h>
#include <stdlib.h>

int answer = 0;

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

void insertleft(struct TreeNode *node, int value)
{
    struct TreeNode *new;
    if ((new = malloc(sizeof(struct TreeNode))) == NULL)
    {
        fprintf(stderr, "mlloc failed\n");
        exit(1);
    }

    new->left = NULL;
    new->right = NULL;
    new->val = value;

    node->left = new;
}

void insertright(struct TreeNode *node, int value)
{
    struct TreeNode *new;
    if ((new = malloc(sizeof(struct TreeNode))) == NULL)
    {
        fprintf(stderr, "mlloc failed\n");
        exit(1);
    }

    new->left = NULL;
    new->right = NULL;
    new->val = value;

    node->right = new;
}

void DFS(struct TreeNode* node, int targetsum) {
    if(node == NULL) {
        return;
    }

    if(node->val == targetsum) {
        answer++;
    }

    DFS(node->left, (targetsum - node->val));
    DFS(node->right, (targetsum - node->val));
}

void count(struct TreeNode* node, int targetSum) {
    if(node != NULL) {
        DFS(node, targetSum);
        count(node->left, targetSum);
        count(node->right, targetSum);
    }

    return;
}

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        fprintf(stderr, "argument!");
        exit(0);
    }

    int targetSum = atoi(argv[1]);
    // root = [10, 5, -3, 3, 2, null, 11, 3, -2, null, 1]
    // struct TreeNode *root = createNode(10);
    // insertleft(root, 5);
    // insertright(root, -3);
    // insertleft(root->left, 3);
    // insertright(root->left, 2);

    // insertright(root->right, 11);
    // insertleft(root->left->left, 3);
    // insertright(root->left->left, -2);

    // insertright(root->left->right, 1);

    // root = [5,4,8,11,null,13,4,7,2,null,null,5,1]
    struct TreeNode *root = createNode(5);
    insertleft(root, 4);
    insertright(root, 8);

    insertleft(root->left, 11);

    insertleft(root->right, 13);
    insertright(root->right, 4);

    insertleft(root->left->left, 7);
    insertright(root->left->left, 2);

    insertleft(root->right->right, 5);
    insertright(root->right->right, 1);

    count(root, targetSum);
    printf("%d\n", answer);


    exit(0);
}