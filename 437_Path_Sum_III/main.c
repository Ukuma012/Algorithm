#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int main(int argc, char *argv[]) {

    if(argc != 2) {
        fprintf(stderr, "argument!");
        exit(0);
    }

    int targetSum = *argv[1] - 48;

    printf("%d\n", targetSum);
    exit(0);
}