#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// #define quantitiesSize 2
#define quantitiesSize 3

// int n = 6;
// int quantities[quantitiesSize] = {11, 6};

int n = 7;
int quantities[quantitiesSize] = {15, 10, 10};

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

int binary_search(int low, int high)
{
    int left = low;
    int right = high;
    int mid = (left + right) / 2;

    if ((left + 1 == right) && !canDistribute(left) && canDistribute(right))
    {
        return right;
    }

    if (canDistribute(mid))
    {
        return binary_search(left, mid);
    }
    else
    {
        return binary_search(mid, right);
    }
}

int main(int argc, char *argv[])
{
    int ans = binary_search(1, 10);
    printf("%d\n", ans);
    exit(0);
}