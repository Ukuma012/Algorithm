#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *right;
    struct TreeNode *left;
};

char startlog[15];
char dstlog[15];

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

void dfs(struct TreeNode *node, int n, char c) {
    if(node == NULL) {
        return;
    }

    if(c == 'L') {
        printf("%s\n", "left");
    } else if(c == 'R') {
        printf("%s\n", "right");
    }

    if(node->val == n) {
        printf("%s\n", "I found it!");
    }

    dfs(node->left, n, 'L');
    dfs(node->right, n, 'R');

    return;
}

int main(int argc, char *argv[]) {

    if(argc != 3) {
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

    dfs(root, dstValue, 'N');

    exit(0);
}