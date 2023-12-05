#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 30

// function to find the index of the given word in the words array
// returns -1 if the word is not found
int findWord(char** words, int count, char* word) {
    for (int i = 0; i < count; i++) {
        if (strcmp(words[i], word) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    int count = 0; // number of words
    int size = 2; // initial size of the words and occurrences arrays
    char** words = (char**) malloc(size * sizeof(char*));
    int* occurrences = (int*) calloc(size, sizeof(int));
    char word[MAX_WORD_LEN];
    scanf("%d", &n);
    while (n) {
        scanf("%s", word);
        int index = findWord(words, count, word);
        if (index != -1) {
            occurrences[index]++;
        } else {
            if (count == size) {
                size *= 2;
                words = (char**) realloc(words, size * sizeof(char*));
                occurrences = (int*) realloc(occurrences, size * sizeof(int));
            }
            words[count] = (char*) malloc((strlen(word) + 1) * sizeof(char));
            strcpy(words[count], word);
            occurrences[count] = 1;
            count++;
            n--;
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", words[i], occurrences[i]);
    }

    // free dynamically allocated memory
    for (int i = 0; i < count; i++) {
        free(words[i]);
    }
    free(words);
    free(occurrences);

    return 0;
}