#include <stdio.h>
#include <stdlib.h>

// HEAPでやる
#define MAX_HEAP 100
int heap[MAX_HEAP + 1];
int heap_pointer = 1;

int main(int argc, char *argv[])
{

    for (int i = 1; i < argc; i++)
    {
        if (*argv[i] == 'n')
        {
            heap[heap_pointer++] = -1;
            continue;
        }
        heap[heap_pointer++] = *argv[i] - '0';
    }

    int root = heap[1];
    for (int j = 2; j < argc; j++)
    {
        if (heap[j] == -1)
        {
            continue;
        }

        if (heap[j] != root)
        {
            printf("%s\n", "false");
            exit(0);
        }
    }

    printf("%s\n", "true");
    return 0;
}
