#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct interval
{
    int start;
    int end;
    bool check;
};

struct interval intervals[10000];

// sorting on start

int main(int argc, char *argv[])
{
    if(argc != 2) {
        fprintf(stderr, "number!\n");
        exit(1);
    }
    int number = *argv[1] - 48;
    
    int previous = 0;;
    int current = 1;
    intervals[0].start = 1;
    intervals[0].end = 3;
    intervals[0].check = true;
    intervals[1].start = 2;
    intervals[1].end = 6;
    intervals[1].check = true;
    intervals[2].start = 8;
    intervals[2].end = 10;
    intervals[2].check = true;
    intervals[3].start = 15;
    intervals[3].end = 18;
    intervals[3].check = true;

    // intervals[0].start = 1;
    // intervals[0].end = 4;
    // intervals[0].check = true;
    // intervals[1].start = 4;
    // intervals[1].end = 8;
    // intervals[1].check = true;

    while (current != number)
    {
        if (intervals[previous].end < intervals[current].start)
        {
            previous++;
            current++;
        }
        else if (intervals[previous].end >= intervals[current].start && intervals[previous].end <= intervals[current].end) {
            intervals[previous].end = intervals[current].end;
            intervals[current].check = false;
            current++;
        } else if(intervals[previous].end >= intervals[current].end) {
            intervals[current].check = false;
            current++;
        }
    }

    for(int i = 0; i < number; i++) {
        if(intervals[i].check == false) {
            continue;
        }

        printf("[%d %d]", intervals[i].start, intervals[i].end);
    }

    printf("\n");

    return 0;
}