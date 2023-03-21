#include <stdio.h>

// stack
char stack[100];
int pointer = 0;

void push(char);
char pop();

int main(int argc, char *argv[])
{
    int result = 0;
    int count = 0;
    char *s = argv[1];
    for (int i = 0; i < 100; i++)
    {
        if (s[i] == '(')
        {
            push(s[i]);
            count = 0;
        }
        else if (s[i] == ')')
        {
            pop();
            count++;
            if (count > result)
            {
                result = count;
            }
        }
        if (s[i] == '\0')
        {
            break;
        }
    }
    printf("%d\n", result);

    return 0;
}

void push(char x)
{
    stack[pointer++] = x;
}

char pop()
{
    char n;
    n = stack[--pointer];
    return n;
}