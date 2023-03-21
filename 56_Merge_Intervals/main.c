#include <stdio.h>

struct interval {
    int start;
    int end;
};

struct interval intervals[10000];

int main(int argc, char *argv[]) {
    intervals[0].start = 1;
    intervals[0].end = 3;

    printf("%d\n", intervals[0].start);
    return 0;
}