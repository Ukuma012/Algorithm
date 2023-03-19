#include <stdio.h>

// rooms.length

int stack[1000];
int pointer = 0;

int main(int argc, char *argv[])
{
    // use stack
    init();

    printf("%s\n", "Hello World");
    return 0;
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