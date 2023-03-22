#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *s = argv[1];
    int lcount = 0;
    int count = 0;
    int max = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (s[i] == '\0')
        {
            break;
        }
        if (lcount % 2 == 0)
        {
            if (s[i] == '*')
            {
                count++;
                if (count > max)
                {
                    max = count;
                }
            }
        }

        if (s[i] == '|')
        {
            lcount++;
        }
    }

    printf("%d\n", max);

    exit(0);
}