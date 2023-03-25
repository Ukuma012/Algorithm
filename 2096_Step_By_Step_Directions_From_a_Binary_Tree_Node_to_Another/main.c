#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *right;
    struct TreeNode *left;
};

struct TreeNode* createTree(int val) {
    struct TreeNode *new;
    if((new = malloc(sizeof(struct TreeNode))) == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    new->left = NULL;
    new->right = NULL;
    new->val = val;

    return new;
}

void insertRight(struct TreeNode *node, int val) {
    struct TreeNode *p;
    if(((p = malloc(sizeof(struct TreeNode))) == NULL)) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    p->left = NULL;
    p->right = NULL;
    p->val = val;
    node->right = p;
}

void insertLeft(struct TreeNode *node, int val) {
    struct TreeNode *p;
    if(((p = malloc(sizeof(struct TreeNode))) == NULL)) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    p->left = NULL;
    p->right = NULL;
    p->val = val;
    node->left = p;
}

int main(int argc, char *argv[]) {
    // root = [5,1,2,3,null,6,4]
    struct TreeNode *root = createTree(5);
    insertLeft(root, 1);
    insertRight(root, 2);
    insertLeft(root->left, 3);

    insertLeft(root->right, 6);
    insertRight(root->right, 4);

    printf("%d\n", root->val);
    printf("%d\n", root->right->right->val);
    exit(0);
}