#include <stdio.h>
#include <stdlib.h>

#define BUF 256

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        fprintf(stderr, "argument!\n");
        exit(1);
    }

    int n = *argv[1] - 48;
    int nums1[n];
    int nums2[n];
    char str1[BUF];
    char str2[BUF];
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        if (fgets(str1, BUF, stdin) != NULL)
        {
            c = atoi(str1);
        }
        nums1[i] = c;
    }
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        if (fgets(str2, BUF, stdin) != NULL)
        {
            c = atoi(str2);
        }
        nums2[i] = c;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums1[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums2[i]);
    }
    printf("\n");
    exit(0);
}