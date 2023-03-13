#include <stdio.h>

// patern[0] -> pattern[1]'s first 
// patern[1] -> pattern[0]'s last

int main(int argc, char *argv[]) {
    int n = 0;
    int lastpos0 = 0;
    int firstpos1 = 0;
    char *text = argv[1];
    char *pattern = argv[2];

    while(text[n] != '\0') {
        if(text[n] == pattern[0]) {
            lastpos0 = n;
        }
        n++;
    }

    printf("%d\n", lastpos0);

    return 0;
}