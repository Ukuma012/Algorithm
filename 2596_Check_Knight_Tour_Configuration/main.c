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
            if (fgets(str, BUF, stdin) != NULL)
            {
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

    int row = 0;
    int col = 0;
    int current = grid[row][col];

    while (current != (n * n - 1))
    {
        if (grid[row += 1][col += 2] == (current + 1))
        {
            current++;
            continue;
        }
        else if (grid[row += 2][col += 1] == (current + 1))
        {
            printf("%d %d\n", row, col);
            current++;
            continue;
        }
        else if (grid[row -= 1][col += 2] == (current + 1))
        {
            current++;
            continue;
        }
        else if (grid[row -= 2][col += 1] == (current + 1))
        {
            current++;
            continue;
        }
        else if (grid[row += 2][col -= 1] == (current + 1))
        {
            current++;
            continue;
        }
        else if (grid[row += 1][col -= 2] == (current + 1))
        {
            current++;
            continue;
        }
        else if (grid[row -= 1][col -= 2] == (current + 1))
        {
            current++;
            continue;
        }
        else if (grid[row -= 2][col -= 1] == (current + 1))
        {
            current++;
            continue;
        }

        printf("%s\n", "Failed!");
        exit(0);
    }

    printf("%s\n", "Succeeded");

    return 0;
}