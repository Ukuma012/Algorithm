#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *right;
    struct TreeNode *left;
};

int start = 14;
int dst = 14;
char startlog[15];
char dstlog[15];

struct TreeNode *createTree(int val)
{
    struct TreeNode *new;
    if ((new = malloc(sizeof(struct TreeNode))) == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    new->left = NULL;
    new->right = NULL;
    new->val = val;

    return new;
}

void insertRight(struct TreeNode *node, int val)
{
    struct TreeNode *p;
    if (((p = malloc(sizeof(struct TreeNode))) == NULL))
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    p->left = NULL;
    p->right = NULL;
    p->val = val;
    node->right = p;
}

void insertLeft(struct TreeNode *node, int val)
{
    struct TreeNode *p;
    if (((p = malloc(sizeof(struct TreeNode))) == NULL))
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    p->left = NULL;
    p->right = NULL;
    p->val = val;
    node->left = p;
}

bool start_dfs(struct TreeNode *node, int n)
{

    if (node->val == n)
    {
        return true;
    }

    if (node->left && start_dfs(node->left, n))
    {
        startlog[start--] = 'L';
    }
    else if (node->right && start_dfs(node->right, n))
    {
        startlog[start--] = 'R';
    }

    if (start != 14)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool dst_dfs(struct TreeNode *node, int n)
{

    if (node->val == n)
    {
        return true;
    }

    if (node->left && dst_dfs(node->left, n))
    {
        dstlog[dst--] = 'L';
    }
    else if (node->right && dst_dfs(node->right, n))
    {
        dstlog[dst--] = 'R';
    }

    if (dst != 14)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void init()
{
    for (int i = 0; i < 15; i++)
    {
        startlog[i] = 'N';
        dstlog[i] = 'N';
    }
}

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        fprintf(stderr, "start value, dst value!");
        exit(1);
    }

    int startValue = atoi(argv[1]);
    int dstValue = atoi(argv[2]);

    // root = [5,1,2,3,null,6,4]
    struct TreeNode *root = createTree(5);
    insertLeft(root, 1);
    insertRight(root, 2);
    insertLeft(root->left, 3);

    insertLeft(root->right, 6);
    insertRight(root->right, 4);

    init();

    start_dfs(root, startValue);
    dst_dfs(root, dstValue);

    int start = 0;
    int dst = 0;

    for (int i = 0; i < 15; i++)
    {
        if (startlog[i] != 'N')
        {
            start = i;
            break;
        }
        else
        {
            continue;
        }
    }

    for (int j = 0; j < 15; j++)
    {
        if (dstlog[j] != 'N')
        {
            dst = j;
            break;
        }
        else
        {
            continue;
        }
    }

    while (dst < 15 && start < 15 && startlog[start] == dstlog[dst])
    {
        start++;
        dst++;
    }

    for (int i = start; i < 15; i++)
    {
        printf("%c", 'U');
    }
    for (int j = dst; j < 15; j++)
    {
        printf("%c", dstlog[j]);
    }

    printf("\n");

    exit(0);
}