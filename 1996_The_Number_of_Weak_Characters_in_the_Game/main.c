#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int attack;
    int defense;
} property;

int compar(const void *a, const void *b)
{
    if (((property *)a)->attack >= ((property *)b)->attack)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "argument!\n");
        exit(1);
    }

    int n = *argv[1] - 48;
    property properties[n];
    char str_attack[2046];
    char str_defense[2046];
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int c = 0;
        if (fgets(str_attack, 2046, stdin) != NULL)
        {
            c = atoi(str_attack);
        }
        properties[i].attack = c;

        int d = 0;
        if (fgets(str_defense, 2046, stdin) != NULL)
        {
            d = atoi(str_defense);
        }
        properties[i].defense = d;
    }

    qsort(properties, n, sizeof(property), compar);

    for (int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++) {
            if(properties[i].attack == properties[j].attack) {
                continue;
            }
            if(properties[i].defense < properties[j].defense) {
                count++;
            }
        }
    }
    printf("%d\n", count);
    exit(0);
}