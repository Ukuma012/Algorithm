#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int i = 0;
int j = 0;

int check() {
    while(dictionary[0][i] != '\0') {
        if(sentence[j] != dictionary[0][i]) {
            while(sentence[j] != ' ') {
                printf("%c", sentence[j]);
                j++;
            }
            printf("%s", " ");
            j++;
            return false;
        }
        j++;
        i++;
    }
    return true;
}

int main(int argc, char *argv[]) {
    if(check() != false) {

    } 
    check();
    exit(0);
}