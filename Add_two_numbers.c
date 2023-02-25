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

void insert(struct ListNode **, int);
void printList(struct ListNode *);

// @TODO まずは一行をlinke list にinsertする
int main(int argc, char *argv[])
{
    struct ListNode *header;
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
        printList(header);
        exit(0);
    }
    return 0;
}

void insert(struct ListNode **header, int value)
{
    struct ListNode *new;
    if ((new = malloc(sizeof(struct ListNode))) == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }
    new->val = value;
    if(*header == NULL) {
        *header = new;
    } else {
        new->next = *header;
        *header = new;
    }
}

void printList(struct ListNode *head)
{
    struct ListNode *temp = head;

    while(temp != NULL)
    {
         printf("%d->", temp->val);
         temp = temp->next;
    }
    printf("NULL\n");
}