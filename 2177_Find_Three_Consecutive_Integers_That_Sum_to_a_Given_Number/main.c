#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int target = 3789;

    for (int i = 0; i < 10000; i++)
    {
        if ((i + (i + 1) + (i + 2)) == target)
        {
            printf("%d %d %d\n", i, i + 1, i + 2);
            break;
        }
        else
        {
            continue;
        }
    }
    exit(0);
}