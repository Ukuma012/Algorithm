#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if(argc != 2) {
       fprintf(stderr, "argument!\n");
       exit(1); 
    }
    printf("%s\n", "Hello World");
    exit(0);
}