#include <stdio.h>
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
    int count = 0;
    int previous;
    int current;
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

    // count ではない
    while (count != (3 - 1))
    {
        previous = 0;
        current = 1;
        if (intervals[previous].end < intervals[current].start)
        {
            previous++;
            current++;
            count++;
            continue;
        }
        else if (intervals[previous].end >= intervals[current].start && intervals[previous].end <= intervals[current].end) {
            intervals[previous].end = intervals[current].end;
            intervals[current].check = false;
            current++;
            count++;
            continue;
        } else if(intervals[previous].end >= intervals[current].end) {
            intervals[current].check = false;
            previous++;
            current++;
            count++;
            continue;
        }
    }

    for(int i = 0; i < 3; i++) {
        if(intervals[i].check == false) {
            continue;
        }

        printf("[%d %d]", intervals[i].start, intervals[i].end);
    }

    printf("\n");

    return 0;
}