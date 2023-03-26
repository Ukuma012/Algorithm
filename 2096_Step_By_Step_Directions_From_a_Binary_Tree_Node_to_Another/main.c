#include <stdio.h>
#include <stdlib.h>

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

void start_dfs(struct TreeNode *node, int n, char c)
{
    if (startflag == 0)
    {
        if (node == NULL)
        {
            return;
        }

        if (c == 'L')
        {
            startlog[start++] = 'L';
        }
        else if (c == 'R')
        {
            startlog[start++] = 'R';
        }

        if (node->val == n)
        {
            // printf("%s\n", "[start]I found it!");
            startlog[start] = 'e';
            startflag = 1;
        }

        start_dfs(node->left, n, 'L');
        start_dfs(node->right, n, 'R');
    }
    else
    {
        return;
    }
    return;
}

void dst_dfs(struct TreeNode *node, int n, char c)
{
    if (dstflag == 0)
    {
        if (node == NULL)
        {
            return;
        }

        if (c == 'L')
        {
            dstlog[dst++] = 'L';
        }
        else if (c == 'R')
        {
            dstlog[dst++] = 'R';
        }

        if (node->val == n)
        {
            // printf("%s\n", "[dst]I found it!");
            dstlog[dst] = 'e';
            dstflag = 1;
        }

        dst_dfs(node->left, n, 'L');
        dst_dfs(node->right, n, 'R');
    }
    else
    {
        return;
    }
    return;
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

    start_dfs(root, startValue, 'N');
    dst_dfs(root, dstValue, 'N');

    for(int i = 0; i < 15; i++) {
        if(startlog[i] == dstlog[i]) {
            continue;
        } else if(startlog[i] != dstlog[i] && startlog[i] == 'e') {
            for(int j = i; j < 15; j++) {
                if(dstlog[j] == 'e') {
                    break;
                }
                printf("%c", dstlog[j]);
            }
        } else if(startlog[i] != dstlog[i] && dstlog[i] == 'e') {
            for(int j = i; j < 15; j++) {
                if(startlog[j] == 'e') {
                    break;
                }
                printf("%s", "U");
            }
        } else if(startlog[i] != dstlog[i]) {
            for(int j = i; j < 15; j++) {
                if(startlog[j] == 'e') {
                    break;
                }
                printf("%s", "U");
            }
            for(int h = i; h < 15; h++) {
                if(dstlog[h] == 'e') {
                    break;
                }
                printf("%c", dstlog[h]);
            }
        }
    }

    printf("\n");
    
    exit(0);
}