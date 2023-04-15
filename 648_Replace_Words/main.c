#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dictionarySize 3

char *dictionary[dictionarySize] = {"cat", "bat", "rat"};
char sentence[] = "the cattle was rattled by the battery";

char *check(char *token, int tokensize)
{
    for (int i = 1; i < tokensize; i++)
    {
        char prefix[i + 1];
        strlcpy(prefix, token, sizeof(prefix));
        for (int j = 0; j < dictionarySize; j++)
        {
            if (strcmp(prefix, dictionary[j]) == 0)
            {
                return dictionary[j];
            }
        }
    }
    return token;
}

int main(int argc, char *argv[])
{
    char *delim = " ";
    char *token;

    token = strtok(sentence, delim);

    while (token != NULL)
    {
        int tokensize = strlen(token);
        char *word;
        word = check(token, tokensize);
        printf("%s\n", word);
        token = strtok(NULL, delim);
    }

    exit(0);
}