#include <stdio.h>
#include <stdlib.h>

#define BUF 256

// ./main (number of col)
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "number of col need\n");
        exit(1);
    }
    int n = *argv[1] - 48;
    int grid[n][n];
    char str[BUF];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
                int c = 0;
                if(fgets(str, BUF, stdin) != NULL) {
                    c = atoi(str);
                }
                grid[i][j] = c;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%2d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}