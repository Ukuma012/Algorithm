#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int tmp[1000];
int answer[1000];
int pointer = 0;

void stack_push(int val) {
    answer[pointer++] = val;
}

void push(int val) {
    if(tmp[val] == 0) {
        tmp[val]++;
       stack_push(val); 
    }
}

int check(int n, int bound)
{
    for (int i = 0; i < 100000; i++)
    {
        if (bound - 1 < pow(n, i))
        {
            return --i;
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    int x = 3;
    int y = 5;
    int bound = 15;

    int m, n;

    m = check(x, bound);
    n = check(y, bound);

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int p = pow(x, i) + pow(y, j);
            if(p <= bound) {
                push(p);
            }
        }
    }

    for(int k = 0; k < pointer; k++) {
        printf("%d ", answer[k]);
    }

    exit(0);
}