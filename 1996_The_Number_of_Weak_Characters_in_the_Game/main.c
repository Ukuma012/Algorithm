#include <stdio.h>
#include <stdlib.h>

struct property {
    int attack;
    int defense;
};

// stack

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "argument!\n");
        exit(1);
    }

    int n = *argv[1] - 48;
    struct property properties[n];
    char str_attack[2046];
    char str_defense[2046];

    for (int i = 0; i < n; i++)
    {
            int c = 0;
            if(fgets(str_attack, 2046, stdin) != NULL) {
                c = atoi(str_attack);
            }
            properties[i].attack = c;

            int d = 0;
            if(fgets(str_defense, 2046, stdin) != NULL) {
                d = atoi(str_defense);
            }
            properties[i].defense = d;
        }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", properties[i].attack);
        printf("%d ", properties[i].defense);
    }
    printf("\n");
    exit(0);
}