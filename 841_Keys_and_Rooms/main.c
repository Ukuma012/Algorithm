#include <stdio.h>
#include <stdlib.h>

// input: rooms.length

int stack[1000];
int pointer = 0;

int main(int argc, char *argv[])
{
    int c;
    if((c = getchar()) == EOF) {
        fprintf(stderr, "getchar failed\n");
        exit(1);
    }
    int roomlength = c - 48;
    printf("%d\n", roomlength);

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