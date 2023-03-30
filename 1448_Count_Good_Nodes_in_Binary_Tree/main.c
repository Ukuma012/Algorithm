#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

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

int main(int argc, char *argv[]) {

    // root = [3 1 4 3 null 1 5]
    struct TreeNode *root;
    root = create(3);
    insertleft(root, 1);
    insertright(root, 4);
    insertleft(root->left, 3);
    insertleft(root->right, 1);
    insertright(root->right, 5);

    exit(0);
}