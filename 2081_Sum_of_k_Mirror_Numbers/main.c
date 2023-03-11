#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// k = 2, n = 5

int main(int argc, char *argv[]) {
    int k, n;
    k = atoi(argv[1]);
    n = atoi(argv[2]);

    char s[100] = "1222341";
    int i = 0;
    int j = strlen(s) -1;
    while(1) {
        if(i == j) {
            break;
        }
        if(s[i++] == s[j--]) {
            printf("%s\n", "yes");
            continue;
        } else {
            printf("%s\n", "No");
            exit(1);
        }
    }

    printf("base is %d\n", k);
    printf("%d times\n", n);
    exit(1);
}