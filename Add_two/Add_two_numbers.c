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

struct ListNode
{
    int val;
    struct ListNode *next;
};

void insert(struct ListNode *, int);

int main(int argc, char *argv[])
{
    struct ListNode l1header, l2header;
    l1header.next = NULL;
    l2header.next = NULL;
    char *whitespace = " \t";
    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    char *value;

    printf("%s", "l1: ");
    int l1count = 0;
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
            insert(&l1header, val);
            l1count++;
        }
        printf("%d\n", l1count);
        struct ListNode *p;
        for (p = l1header.next; p != NULL; p = p->next)
        {
            // 1数字ごとに処理
            // 0をどう処理するか

            printf("%d\n", p->val);
        }
        free(p);
        break;
    }

    printf("%s", "l2: ");
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
            insert(&l2header, val);
        }
        struct ListNode *q;
        for (q = l2header.next; q != NULL; q = q->next)
        {
            // 1数字ごとに処理
            printf("%d\n", q->val);
        }
        free(q);
        break;
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