#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dictionarySize 3

char *dictionary[dictionarySize] = {"cat", "bat", "rat"};
char sentence[] = "the cattle was rattled by the battery";

int main(int argc, char *argv[]) {
    char *delim = " ";
    char *token;

    token = strtok(sentence, delim);

    while(token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delim);
    }

    exit(0);
}