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

    char *s = argv[1];
    int i = 0;
    while(s[i] != '\0') {
        int h = hash(s[i]);
        table[h].key = h;
        table[h].index = i;
        i++;
    }

    for(int i = 0; i < 128; i++) {
        if(table[i].index == -1) {
            continue;
        }
        printf("%c %d\n", (char)i, table[i].index);
    }
    return 0;
}