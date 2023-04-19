#include <stdio.h>
#include <stdlib.h>

int partition(int a[], int l, int r)
{
    int i, j, pivot, t;

    i = l - 1;
    j = r;

    pivot = a[r];

    for (;;)
    {
        while (a[++i] < pivot)
        {
            ;
        }

        while (i < --j && pivot < a[j])
        {
            ;
        }

        if (i >= j)
        {
            break;
        }

        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    t = a[i];
    a[i] = a[r];
    a[r] = t;
    return i;
}

void quick_sort_l(int a[], int l, int r)
{
    int v;
    if (l >= r)
    {
        return;
    }

    v = partition(a, l, r);

    quick_sort_l(a, l, v - 1);
    quick_sort_l(a, v + 1, r);
}

void quick_sort(int a[], int n)
{
    quick_sort_l(a, 0, n - 1);
}

int binary_serch(int a[], int low, int high, int target)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main(int argc, char *argv[])
{
    // int nums[] = {3, 1, 6, 8};
    int nums[] = {2, 9, 6, 3};
    int queries[] = {10};
    int numsSize = sizeof(nums) / sizeof(int);
    int queriesSize = sizeof(queries) / sizeof(int);

    // 配列のソート
    quick_sort(nums, numsSize);
    // targetを探す
    for (int i = 0; i < queriesSize; i++)
    {
        int leftsum = 0;
        int rightsum = 0;
        int ans = 0;;
        int n = binary_serch(nums, 0, numsSize - 1, queries[i]);
        for(int h = 0; h < n; h++) {
            leftsum += (queries[i] - nums[h]);
        }
        for(int j = n; j < numsSize; j++) {
            rightsum += (nums[j] - queries[i]);
        }

        ans = leftsum + rightsum;
        printf("%d\n", ans);
    }

    exit(0);
}