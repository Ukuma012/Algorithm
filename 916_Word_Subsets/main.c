#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// O(n) solution!!

struct bucket {
    int val;
    bool set;
};

struct bucket buckets[26];

int hash(char c)
{
    int n = c - 97;
    return n;
}

void bucket_init()
{
    for (int i = 0; i < 26; i++)
    {
        buckets[i].set = false;
        buckets[i].val = 0;
    }
}

int main(int argc, char *argv[])
{
    bucket_init();
    char *words1[5] = {"amazon", "apple", "facebook", "google", "leetcode"};
    char *words2[2] = {"e", "o"};

    for(int i = 0; i < 2; i++) {
        char *c = words2[i];
        for(int j = 0; j < 10; j++) {
            if(c[j] == '\0') {
                break;
            }
            int n = hash(c[j]);
            buckets[n].val++; 
            if(buckets[n].set == false) {
                buckets[n].set = true;
            }
        }
    }

    for(int i = 0; i < 26; i++) {
        printf("%d ", buckets[i].val);
    }
    exit(0);
}