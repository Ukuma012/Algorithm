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

// @TODO 関数にまとめる
// @TODO l2を実装

struct ListNode
{
    int val;
    struct ListNode *next;
};

void insert(struct ListNode *, int);

int main(int argc, char *argv[])
{
    struct ListNode header;
    header.next = NULL;
    char *whitespace = " \t";
    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    char *value;

    printf("%s", "l1: ");
    while ((linelen = getline(&line, &linecap, stdin)) > 0)
    {
        while ((value = strsep(&line, whitespace)) != NULL)
        {
            if (*value == '\0')
            {
                continue;
            }

            // insert
            // 数値に変換
            int val = *value - '0';
            insert(&header, val);
        }
        struct ListNode *p;
        for (p = header.next; p != NULL; p = p->next)
        {
            printf("%d\n", p->val);
        }
        exit(0);
    }
    return 0;
}

void insert(struct ListNode *head, int val)
{
    struct ListNode *new;
    if ((new = malloc(sizeof(struct ListNode))) == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }
    new->val = val;
    new->next = (*head).next;
    (*head).next = new;
}