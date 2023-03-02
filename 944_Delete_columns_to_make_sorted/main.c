#include <stdio.h>

int minDeletionSize(char **strs, int strsSize) {
    int count = 0;
    for(int i = 1, j = 2; j < strsSize+1; i++, j++) {
        int h = 0;
        char *s1 = strs[i];
        char *s2 = strs[j];
        while(s1[h] != '\0') {
            if(s1[h] > s2[h]) {
                count++;
                h++;
                continue;
            }
            h++;
        }
    }
    return count;
}

int main(int argc, char **strs) {
    int result = 0;
    int strsSize = argc - 1;

    result = minDeletionSize(strs, strsSize);
    printf("%d\n", result);
    return 0;
}

