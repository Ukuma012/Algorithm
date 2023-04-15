#include <stdio.h>
#include <stdlib.h>

#define arrsize 3

int arr[arrsize] = {6, 2, 4};

int main(int argc, char *argv[])
{
    int n = arrsize;
    int sum = 0;
    while (n > 1)
    {
        int min_product = INT16_MAX;
        int min_elm = -1;
        for (int i = 0; i < arrsize - 1; i++)
        {
            int x = arr[i] * arr[i + 1];
            if (x < min_product)
            {
                if (arr[i] < arr[i + 1])
                {
                    min_elm = i;
                }
                else
                {
                    min_elm = i + 1;
                }
                min_product = x;
            }
        }
        sum += min_product;
    }

    printf("%s\n", "Hello World");
    exit(0);
}