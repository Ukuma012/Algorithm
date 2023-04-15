#include <stdio.h>
#include <stdlib.h>

#define numsSize 7

int k = 2;
int nums[numsSize] = {2,1,1,1,3,4,1};

int non_inc_check(int i) {
    for(int j = i - 2; j < i; j++) {
        if(nums[j] < nums[j+1]) {
            return 0;
        }
    }
    return 1;
}

int non_dec_check(int i) {
    for(int h = i+1; h < i+k; h++) {
        if(nums[h] > nums[h+1]) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    for(int i = k; i < numsSize - k; i++) {
        if(non_inc_check(i) && non_dec_check(i)) {
            printf("%d ", i);
        }
    }
    exit(0);
}