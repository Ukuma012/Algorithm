#include <stdio.h>
#include <stdlib.h>

// input: rooms.length

int stack[1000];
int pointer = 0;
int counter = 0;

void check();
void push(int );
int pop();

int main(int argc, char *argv[])
{
    int room = 0;
    int c;
    if((c = getchar()) == EOF) {
        fprintf(stderr, "getchar failed\n");
        exit(1);
    }
    int roomlength = c - 48;
    printf("%d\n", roomlength);
    push(1);
    check();

    return 0;
}

void check() {
    while(pointer != 0) {
        int n = pop();
        if(n == ++counter) {
            printf("%s\n", "Success from check\n");
            exit(0);
        }
    }
    printf("%s\n", "Failed\n");
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