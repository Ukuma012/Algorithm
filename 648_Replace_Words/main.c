#include <stdio.h>
#include <stdlib.h>

#define dictionarySize 3
#define sentencelength 1000000

char *dictionary[dictionarySize] = {"cat", "bat", "rat"};
char *sentence = "the cattle was rattled by the battery";

int main(int argc, char *argv[]) {
    for(int i = 0; i < sentencelength; i++) {
        if(sentence[i] == '\0') {
            break;
        }
        if(sentence[i] == ' ') {
            printf("%s\n", "space");
        }
    }
    exit(0);
}