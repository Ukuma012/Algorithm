#include <stdio.h>
#include <stdlib.h>

// O(n) solution!!

int bucket[26];

int hash(char c) {
    int n = c - 97;
    return n;
}

int main(int argc, char *argv[]) {

    int n = hash('a');
    printf("%d\n", n);
    exit(0);
}