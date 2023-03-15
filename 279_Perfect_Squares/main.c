#include <stdio.h>
#include <stdlib.h>

// breadth-first search
// Dynamic Programming

#define TABLE_SIZE 10000

int main(int argc, char *argv[])
{
    int j = 0;
    int n = 0;
    int square[100];

    // いくつ入れたか
    int table[TABLE_SIZE + 1];

    int total;

    for (int i = 1; i < 100; i++)
    {
        square[j] = i * i;
        j++;
    }

    int m = atoi(argv[1]);
    for (int i = 0; i <= m; i++)
    {
        table[i] = i;
    }

    for (int i = 0; i < 100; i++)
    {
        if (square[i] <= m)
        {
            n++;
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        // If we use square[i], how many would we put in?
        for (j = 1; j <= m; j++)
        {
            int index = j - square[i];
            if (index < 0)
            {
                continue;
            }
            else if (index == 0)
            {
                total = 1;
            }
            else
            {
                total = 1 + table[index];
            }

            if(total < table[j]) {
                table[j] = total;
            }

        }
    }
    printf("%d\n", table[m]);
    return 0;
}