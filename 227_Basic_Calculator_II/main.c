#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "argument");
        exit(1);
    }
    char *s = argv[1];
    printf("%s\n", s);

    exit(0);
}