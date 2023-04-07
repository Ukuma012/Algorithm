#include <stdio.h>
#include <stdlib.h>

#define rowSumsize 2
#define colSumsize 2

int rowSum[rowSumsize] = {3, 8};
int colSum[colSumsize] = {4, 7};

int main(int argc, char *argv[])
{
    int answerSize = rowSumsize * colSumsize;
    int answer[answerSize];
    int n = 0;

    for(int row = 0; row < rowSumsize; row++) {
        for(int col = 0; col < colSumsize; col++) {
            if(rowSum[row] <= colSum[col]) {
                answer[n++] = rowSum[row];
                int rowtmp = rowSum[row];
                rowSum[row] -= rowtmp;
                colSum[col] -= rowtmp;
            } else {
                answer[n++] = colSum[col];
                int coltmp = colSum[col];
                rowSum[row] -= coltmp;
                colSum[col] -= coltmp;
            }
        }
    }

    for(int i = 0; i < answerSize; i++) {
        printf("%d ", answer[i]);
    }

    printf("\n");

    exit(0);
}