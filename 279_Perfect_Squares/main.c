#include <stdio.h>
#include <stdlib.h>

// breadth-first search
// Dynamic Programming

#define TABLE_SIZE 10000

int main(int argc, char *argv[]) {
    int j = 0;
    int square[100];
    for(int i = 1; i <= 100; i++) {
        square[j] = i*i;
        j++;
    }


    // int n = atoi(argv[1]);
    // printf("%d\n", n);
    return 0;
}