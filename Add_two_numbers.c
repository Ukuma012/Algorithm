#include <stdio.h>
#include <string.h>

// @TODO use linkedlist
// input: 2 4 3\n
//        5 6 4\n
//
// l1: 2 4 3 -> 342
// l2: 5 6 4 -> 465
// add: 342+465 = 807
// then: 807 -> 7 0 8

struct ListNode {
    int val;
    struct ListNode *next;
};

int main(int argc, char *argv[]) {
    int c;
    struct ListNode l1_header, l2_header;
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

        // ListNode
        struct ListNode *p;
        if((p = malloc(sizeof(struct ListNode))) == NULL) {
            fprintf(stderr, "malloc failed\n");
            exit(1);
        }
    }

    printf("%s", "l2: ");
    while((c = getchar()) != EOF) {
        if(c == '\n') {
            break;
        }
        if(c == ' ' || c == '\t') {
            continue;
        }

        // ListNode
    }
    return 0;
}