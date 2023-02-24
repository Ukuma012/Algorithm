#include <stdio.h>
#include <string.h>

// @TODO linkedlist

struct ListNode {
    int val;
    struct ListNode *next;
};

int main(int argc, char *argv[]) {
    int c;
    char l1[100];
    char l2[100];
    int i = 0;
    int j = 0;
    printf("%s", "l1: ");
    while((c = getchar()) != EOF) {
        if(c == '\n') {
            break;
        }
        if(c == ' ' || c == '\t') {
            continue;
        }
        l1[i] = c;
        i++;
    }
    printf("%s", "l2: ");
    while((c = getchar()) != EOF) {
        if(c == '\n') {
            break;
        }
        if(c == ' ' || c == '\t') {
            continue;
        }
        l2[j] = c;
        j++;
    }


    return 0;
}