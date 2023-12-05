#include <stdio.h>
#include <string.h>

#define MAX_WORD_COUNT 100
#define MAX_WORD_LEN 30

int main() {
    char words[MAX_WORD_COUNT][MAX_WORD_LEN];
    int occurrences[MAX_WORD_COUNT];
    int count = 0;
    int n, i;
    char word[MAX_WORD_LEN];
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%s", word);
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(words[i], word) == 0) {
                occurrences[i]++;
                found = 1;
                break;
            }
        }
        if (!found && count < MAX_WORD_COUNT) {
            strcpy(words[count], word);
            occurrences[count] = 1;
            count++;
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", words[i], occurrences[i]);
    }

    return 0;
}