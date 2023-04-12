#include <stdio.h>
#include <stdlib.h>

#define numsSize 5
int nums[numsSize] = {1, 3, 8, 48, 10};

int main(int argc, char *argv[])
{
    int max = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int count = 0;
        for (int j = 0; j < numsSize; j++)
        {
            if (i == j)
            {
                continue;
            }
            if ((nums[i] & nums[j]) == 0)
            {
                printf("%d %d\n", nums[i], nums[j]);
                count++;
                if (max < count)
                {
                    max = count;
                }
            }
        }
    }
    printf("%d\n", max);
    exit(0);
}
