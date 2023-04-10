#include <stdio.h>
#include <stdlib.h>

#define nodesize 100

struct node
{
    int val;
    int weight;
    struct node *next;
};

struct graph
{
    struct node *nodes[nodesize];
};

int main(int argc, char *argv[])
{
    printf("%s\n", "Hello World");
    exit(0);
}