#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int count = 1;
int max = 0;

struct TreeNode *create(int val) {
    struct TreeNode *new;
    if((new = malloc(sizeof(struct TreeNode))) == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    new->val = val;
    new->right = NULL;
    new->left = NULL;

    return new;
}

void insertleft(struct TreeNode *node, int val) {
    struct TreeNode *p = create(val); 
    node->left = p;
}

void insertright(struct TreeNode *node, int val) {
    struct TreeNode *p = create(val);
    node->right = p;
}

void dfs(struct TreeNode *node, int max) {
    if(node == NULL) {
        return;
    }

    if(node->val >= max) {
        count++;
        max = node->val;
    }

    dfs(node->left, max);
    dfs(node->right, max);
}

int main(int argc, char *argv[]) {

    // root = [3 1 4 3 null 1 5]
    // struct TreeNode *root;
    // root = create(3);
    // insertleft(root, 1);
    // insertright(root, 4);
    // insertleft(root->left, 3);
    // insertleft(root->right, 1);
    // insertright(root->right, 5);

    // root = [3,3,null,4,2]
    struct TreeNode *root;
    root = create(3);
    insertleft(root, 3);
    insertleft(root->left, 4);
    insertright(root->left, 2);

    int max = root->val;
    if(root->left != NULL) {
        dfs(root->left, max);
    }

    if(root->right != NULL) {
        dfs(root->right, max);
    }

    printf("%d\n", count);

    exit(0);
}