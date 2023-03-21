#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// input: rooms.length

int stack[1000];
int pointer = 0;
int counter = 0;

bool check();
void push(int);
int pop();

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "argument failed\n");
        exit(1);
    }

    int roomlength = *argv[1] - 48;
    printf("%d\n", roomlength);

    while (counter != (roomlength-1))
    {
        int n;
        while ((n = getchar()) != EOF)
        {
            if (n == '\n')
            {
                break;
            }
            int item = n - 48;
            push(item);
        }
        if (check())
        {
            continue;
        } else {
            fprintf(stderr, "failed\n");
            exit(1);
        }
    }
    printf("%s\n", "success\n");
    return 0;
}

bool check()
{
    while (pointer != 0)
    {
        int n = pop();
        if (n == (counter + 1))
        {
            counter++;
            return true;
        }
    }
    return false;
}

void push(int x)
{
    stack[pointer++] = x;
}

int pop()
{
    int x;
    x = stack[--pointer];
    return x;
}