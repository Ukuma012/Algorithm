#include <stdio.h>
#include <stdlib.h>

// k = 2, n = 5

int main(int argc, char *argv[]) {
    int k, n;
    k = atoi(argv[1]);
    n = atoi(argv[2]);

    printf("base is %d\n", k);
    printf("%d times\n", n);
    exit(1);
}