#include <stdio.h>
#include <stdlib.h>

#define dictionarySize 3
#define sentencelength 1000000

char *dictionary[dictionarySize] = {"cat", "bat", "rat"};
char *sentence = "the cattle was rattled by the battery";

char table[26];

void init() {
    for(int i = 0; i < 26; i++) {
        table[i] = 0;
    }
}

int hash(char c) {
    int n = c - 'a';
    return n;
}

int main(int argc, char *argv[]) {

    int i = 0;
    int j = 0;
    while(dictionary[0][i] != '\0') {
        if(sentence[j] != dictionary[0][i]) {
            while(sentence[j] != ' ') {
                printf("%c", sentence[j]);
                j++;
            }
            break;
        }
        j++;
        i++;
    }
    exit(0);
}