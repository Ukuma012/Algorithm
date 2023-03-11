#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// k = 2, n = 5

int main(int argc, char *argv[])
{
    int count = 0;
    int target = 1;
    int n;
    n = atoi(argv[1]);

    while (count != n)
    {

        char s[4096];
        snprintf(s, 4096, "%d", target);

        int i = 0;
        int j = strlen(s) - 1;
        while (1)
        {
            if (i == j || i > j)
            {
                printf("%d\n", target);
                count++;
                break;
            }

            if (s[i++] == s[j--])
            {
                continue;
            }
            else
            {
                break;
            }
        }
        target++;
    }
    return 0;
}