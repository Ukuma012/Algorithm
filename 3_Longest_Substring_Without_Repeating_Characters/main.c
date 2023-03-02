#include <stdio.h>

// keyequal

#define EMPTY (int) -1;

// hashはASCIIへの変換 128個
#define BUCKET_SIZE 128

// SCIIの128個hash tableを用意すればいい
// charに対応するkeyを探索、登録されていなければindexを登録
//　                    　登録されていればindexを更新
typedef struct bucket {
    int key;
    int index;
} BUCKET;
BUCKET table[BUCKET_SIZE];

void init() {
    int i;
    for(i = 0; i < BUCKET_SIZE; i++) {
        table[i].index = EMPTY;
    }
}

int hash(char key) {
    int ascii = (int) key;
    return ascii;
}

int main(int argc, char *argv[]) {

    init();

    int count = 0;
    char *s = argv[1];
    int i = 0;
    int j = 0;
    while(s[j] != '\0') {
        int h = hash(s[j]);
        if(table[h].index == -1) {
            table[h].key = h;
            table[h].index = j;

            if((j - i + 1) > count) {
                count = j - i + 1;
            }
        } else {
            i = table[h].index + 1;
            table[h].index = j; 
        }
        j++;
    }

    printf("%d\n", count);
    return 0;
}