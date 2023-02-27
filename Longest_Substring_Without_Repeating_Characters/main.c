#include <stdio.h>

int main(int argc, char *argv[]) {
    char *s = argv[1];
    int i = 0;
    int j = 0;
    while(s[i] != '\0') {
        printf("%d %c\n", j, s[i]);
        i++;
        j++;
    }
    return 0;
}