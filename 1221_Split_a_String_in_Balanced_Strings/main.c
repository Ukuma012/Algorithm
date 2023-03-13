#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int Rcount = 0;
    int Lcount = 0;
    int count = 0;
    int n = 0;
    char *s = argv[1];

    while(s[n] != '\0') {
        if(s[n] == 'R') {
            Rcount++;
        } else if(s[n] == 'L') {
            Lcount++;
        }

        if(Rcount == Lcount) {
            count++;
        }
        n++;
    }
    
    printf("%d\n", count);
    return 0;
}