#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define quantitiesSize 2

int n = 6;
int quantities[quantitiesSize] = {11, 6};

bool canDistribute(int k)
{
    int max = n * k;
    int products = 0;
    for (int i = 0; i < quantitiesSize; i++)
    {
        products += quantities[i];
    }

    if (max < products)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < 10; i++)
    {
        printf("%d\n", canDistribute(i));
    }
    exit(0);
}