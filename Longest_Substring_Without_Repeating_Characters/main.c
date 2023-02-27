#include <stdio.h>

int main(int argc, char *argv[]) {
    char *s = argv[1];
    int i = 0;
    while(s[i] != '\0') {
        printf("%c\n", s[i]);
        i++;
    }
    return 0;
}