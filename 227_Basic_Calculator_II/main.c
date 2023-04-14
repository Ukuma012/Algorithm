#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define maxlength 300000
#define stack_size 1000

int pointer = 0;
int stack[stack_size];

void push(int val)
{
    stack[pointer++] = val;
}

int pop()
{
    int n;
    n = stack[--pointer];
    return n;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "argument");
        exit(1);
    }
    char *s = argv[1];
    for (int i = 0; i < maxlength; i++)
    {
        // + - * / と space
        if (s[i] == '\0')
        {
            break;
        }
        if (isdigit(s[i]) != 0)
        {
            push(s[i] - '0');
        }
        if (s[i] == '+')
        {
            printf("%s\n", "plus!");
        }
        printf("%c\n", s[i]);
    }

    printf("\n");

    for (int i = 0; i < pointer; i++)
    {
        printf("%d\n", stack[i]);
    }
    exit(0);
}