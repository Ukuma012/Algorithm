#include <stdio.h>
#include <stdlib.h>

int partition(int a[], int l, int r) {
    int i, j, pivot, t;

    i = l - 1;
    j = r;

    pivot = a[r];

    for(;;) {
        while(a[++i] < pivot) {
            ;
        }

        while(i < --j && pivot < a[j]) {
            ;
        }

        if(i >= j) {
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

int main(int argc, char *argv[])
{
    int nums[] = {3, 1, 6, 8};
    int queries[] = {1, 5};
    int numsSize = sizeof(nums) / sizeof(int);
    int queriesSize = sizeof(queries) / sizeof(int);


    // 配列のソート
    // targetを探す
    // マイナスとプラスで計算

    exit(0);
}