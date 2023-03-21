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
        int row1, row2, row3, row4, row5, row6, row7, row8;
        int col1, col2, col3, col4, col5, col6, col7, col8;
        row1 = row2 = row3 = row4 = row5 = row6 = row7 = row8 = row;
        col1 = col2 = col3 = col4 = col5 = col6 = col7 = col8 = col;

        if (grid[row1 += 1][col1 += 2] == (current + 1))
        {
            current++;
            row = row1;
            col = col1;
            continue;
        }
        else if (grid[row2 += 2][col2 += 1] == (current + 1))
        {
            current++;
            row = row2;
            col = col2;
            continue;
        }
        else if (grid[row3 -= 1][col3 += 2] == (current + 1))
        {
            current++;
            row = row3;
            col = col3;
            continue;
        }
        else if (grid[row4 -= 2][col4 += 1] == (current + 1))
        {
            current++;
            row = row4;
            col = col4;
            continue;
        }
        else if (grid[row5 += 2][col5 -= 1] == (current + 1))
        {
            current++;
            row = row5;
            col = col5;
            continue;
        }
        else if (grid[row6 += 1][col6 -= 2] == (current + 1))
        {
            current++;
            row = row6;
            col = col6;
            continue;
        }
        else if (grid[row7 -= 1][col7 -= 2] == (current + 1))
        {
            current++;
            row = row7;
            col = col7;
            continue;
        }
        else if (grid[row8 -= 2][col8 -= 1] == (current + 1))
        {
            current++;
            row = row8;
            col = col8;
            continue;
        }
        printf("%s\n", "Failed!");
        exit(0);
    }

    printf("%s\n", "Succeeded");

    return 0;
}