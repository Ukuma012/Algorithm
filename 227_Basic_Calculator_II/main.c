#include <stdio.h>
#include <stdlib.h>

#define maxlength 300000

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "argument");
        exit(1);
    }
    char *s = argv[1];
    for (int i = 0; i < maxlength; i++)
    {
        // + - * / と space
        if (s[i] == '\0')
        {
            break;
        }
        if (s[i] == '+')
        {
            printf("%s\n", "plus");
        }
        printf("%c\n", s[i]);
    }
    exit(0);
}