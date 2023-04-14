#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define maxlength 300000
#define stack_size 1000

int digit_pointer = 0;
int opt_pointer = 0;
int digit_stack[stack_size];
char opt_stack[stack_size];

void digit_push(int val)
{
    digit_stack[digit_pointer++] = val;
}

void opt_push(char opt)
{
    opt_stack[opt_pointer++] = opt;
}

int digit_pop()
{
    int n;
    n = digit_stack[--digit_pointer];
    return n;
}

char opt_pop()
{
    char c;
    c = opt_stack[--opt_pointer];
    return c;
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
            digit_push(s[i] - '0');
        }
        if (s[i] == '+')
        {
            opt_push(s[i]);
        }
        else if (s[i] == '-')
        {
            opt_push(s[i]);
        }
        else if (s[i] == '*')
        {
            opt_push(s[i]);
        }
        else if (s[i] == '/')
        {
            opt_push(s[i]);
        }
        printf("%c\n", s[i]);
    }

    printf("\n");

    for (int i = 0; i < digit_pointer; i++)
    {
        printf("%d\n", digit_stack[i]);
    }

    for (int i = 0; i < opt_pointer; i++)
    {
        printf("%c\n", opt_stack[i]);
    }
    exit(0);
}