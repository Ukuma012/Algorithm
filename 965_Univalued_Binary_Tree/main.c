#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *root;

void insert(int );
void print_tree(struct TreeNode *);

int main(int argc, char *argv[]) {
    printf("%s\n", "Hello");
    insert(1);
    insert(2);
    insert(3); // 表示されない！
    // root = NULL;
    // for(int i = 1; i < argc; i++) {
    //     int n = *argv[i] - '0';
    //     insert(n);
    // }
    // printf("%s\n", "Hi");
    print_tree(root);
    printf("%s\n", "Can you see me?");
    return 0;
}

void print_tree(struct TreeNode *p) {
    if(p == NULL) {
        exit(0);
    }
    printf("%d\n", p->value);
    print_tree(p->left);
    print_tree(p->right);
}

void insert(int n) {
    struct TreeNode **p;
    p = &root;
    
    // Bug Here!

    while(*p != NULL) {
        if((*p)->left == NULL) {
            p = &(*p)->left;
        } else if((*p)->right == NULL) {
            p = &(*p)->right;
        }
    }
    
    struct TreeNode *new;
    if((new = malloc(sizeof(struct TreeNode))) == NULL) {
      fprintf(stderr, "malloc failed\n");
      exit(1);  
    }

    new->value = n;
    new->left = NULL;
    new->right = NULL;
    *p = new;
}