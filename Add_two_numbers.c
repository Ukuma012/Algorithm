#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

// @TODO まずは一行をlinke list にinsertする
int main(int argc, char *argv[]) {
    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    printf("%s", "l1: ");
    while((linelen = getline(&line, &linecap, stdin)) > 0) {
        fwrite(line, linelen, 1, stdout);
        exit(0);
    }
    return 0;
}