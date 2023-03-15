#include <stdio.h>
#include <stdlib.h>

// breadth-first search
// Dynamic Programming

#define TABLE_SIZE 10000

int main(int argc, char *argv[]) {
    int j = 0;
    int n = 0;
    int square[100];
    int table[TABLE_SIZE];

    for(int i = 1; i < 100; i++) {
        square[j] = i*i;
        j++;
    }

    int m = atoi(argv[1]);
    for(int i = 0; i < m; i++) {
        table[i] = 0;
    }

    for(int i = 0; i < 100; i++) {
        if(square[i] <= m) {
            n++;
        } else {
            break;
        }
    }

    return 0;
}