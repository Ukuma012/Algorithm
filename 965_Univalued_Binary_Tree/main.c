#include <stdio.h>

// HEAPでやる
#define MAX_HEAP 100
int heap[MAX_HEAP + 1];
int heap_pointer = 1;

int main(int argc, char *argv[]) {
    for(int i = 1; i < argc; i++) {
        if(*argv[i] == 'n') {
            heap[heap_pointer++] = -1;
            continue;
        }
        heap[heap_pointer++] = *argv[i] - '0'; 
    }

    return 0;
}