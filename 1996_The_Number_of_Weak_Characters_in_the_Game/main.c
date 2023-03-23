#include <stdio.h>
#include <stdlib.h>

struct property {
    int attack;
    int defence;
};

// stack

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "argument!\n");
        exit(1);
    }

    int n = *argv[1] - 48;
    int properties[n];
    char str[2046];

    for (int i = 0; i < (2 * n); i++)
    {
        int c = 0;
        if (fgets(str, 2046, stdin) != NULL)
        {
            c = atoi(str);
        }
        properties[i] = c;
    }

    for (int i = 0; i < (2 * n); i++)
    {
        printf("%d ", properties[i]);
    }
    printf("\n");
    exit(0);
}