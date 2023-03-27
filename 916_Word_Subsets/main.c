#include <stdio.h>
#include <stdlib.h>

#define words1_max 6
#define words2_max 2

char *words1[] = {"amazon","apple","facebook","google","leetcode"}; 
char *words2[] = {"l","e"};
int table1[26];
int table2[26];

int hash(char c) {
    int n = c - 'a';
    return n;
}

void init() {
    for(int i = 0; i < 26; i++) {
        table1[i] = 0;
    }
}

int main(int argc, char *argv[]) {
    init();

    for(int i = 0; i < words2_max; i++) {
        char *s = words2[i];
        for(int j = 0; j < 10; j++){
            if(s[j] == '\0') {
                break;
            }
            int n = hash(s[j]);
            table2[n]++;
        }
    }
    
    for(int i = 0; i < words1_max; i++) {
        init();
        char *s = words1[i];
        for(int j = 0; j < 10; j++){
            if(s[j] == '\0') {
                break;
            }
            int n = hash(s[j]);
            table1[n]++;
        }

        int flag = 0;
        for(int h = 0; h < 26; h++) {
            if(table2[h] == 0) {
                continue;
            }
            if(table1[h] < table2[h]) {
                flag++;
                break;
            }
        }
        if(flag == 0) {
            printf("%s\n", s);
        }
    }

    exit(0);
}
