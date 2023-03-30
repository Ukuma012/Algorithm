#include <stdio.h>
#include <stdlib.h>

#define arr_size 1

int table[26];
int count;

void init()
{
    for (int i = 0; i < 26; i++)
    {
        table[i] = 0;
    }
    count = 0;
}

int hash(char s)
{
    int n = s - 'a';
    return n;
}

int main(int argc, char *argv[])
{
    int max = 0;
    char *arr[arr_size] = {"abcdefghijklmnopqrstuvwxyz"};

    for (int i = 0; i < arr_size; i++)
    {
        for (int h = i; h < arr_size; h++)
        {
            char *s = arr[h];
            for (int j = 0; j < 26; j++)
            {
                if (s[j] == '\0')
                {
                    break;
                }
                int n = hash(s[j]);
                if (table[n] == 0)
                {
                    table[n]++;
                    count++;
                    if (max < count)
                    {
                        max = count;
                    }
                }
                else if (table[n] > 0)
                {
                    init();
                    break;
                }
            }
        }
    }

    printf("%d\n", max);

    exit(0);
}