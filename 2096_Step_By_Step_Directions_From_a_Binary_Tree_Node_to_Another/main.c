#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *right;
    struct TreeNode *left;
};

int start = 0;
int dst = 0;
char startlog[15];
char dstlog[15];
int startflag = 0;
int dstflag = 0;

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
        startlog[start++] = 'L';
    }
    else if (node->right && start_dfs(node->right, n))
    {
        startlog[start++] = 'R';
    }

    if (start != 0)
    {
        startlog[start] = 'e';
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
        dstlog[dst++] = 'L';
    }
    else if (node->right && dst_dfs(node->right, n))
    {
        dstlog[dst++] = 'R';
    }

    if (dst != 0)
    {
        dstlog[dst] = 'e';
        return true;
    }
    else
    {
        return false;
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

    start_dfs(root, startValue);
    dst_dfs(root, dstValue);

    // for(int i = 0; i < 15; i++) {
    //     if(startlog[i] == dstlog[i]) {
    //         continue;
    //     } else if(startlog[i] != dstlog[i] && startlog[i] == 'e') {
    //         for(int j = i; j < 15; j++) {
    //             if(dstlog[j] == 'e') {
    //                 break;
    //             }
    //             printf("%c", dstlog[j]);
    //         }
    //     } else if(startlog[i] != dstlog[i] && dstlog[i] == 'e') {
    //         for(int j = i; j < 15; j++) {
    //             if(startlog[j] == 'e') {
    //                 break;
    //             }
    //             printf("%s", "U");
    //         }
    //     } else if(startlog[i] != dstlog[i]) {
    //         for(int j = i; j < 15; j++) {
    //             if(startlog[j] == 'e') {
    //                 break;
    //             }
    //             printf("%s", "U");
    //         }
    //         for(int h = i; h < 15; h++) {
    //             if(dstlog[h] == 'e') {
    //                 break;
    //             }
    //             printf("%c", dstlog[h]);
    //         }
    //     }
    // }

    printf("\n");

    exit(0);
}