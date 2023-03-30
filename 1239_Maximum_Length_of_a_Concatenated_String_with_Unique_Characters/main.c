#include <stdio.h>
#include <stdlib.h>

#define arr_size 3

int main(int argc, char *argv[]) {
    char *arr[arr_size] = {"un", "iq", "ue"};

    for(int i = 0; i < arr_size; i++) {
        char *s = arr[i];
        for(int j = 0; j < 26; j++) {
            if(s[j] == '\0') {
                break;
            }
            printf("%c\n", s[j]);
        }
    }

    exit(0);
}