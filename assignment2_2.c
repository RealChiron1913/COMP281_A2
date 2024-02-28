#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// Define maximum length of a line and a word
#define MAX_LINE_LENGTH 100
#define MAX_WORD_LENGTH 30

// Define a struct to represent word counts
struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
};

// Main function
int main() {
        // Initialize variables
    char line[MAX_LINE_LENGTH];
    int num_words = 0; // number of distinct words
    int max_words = 10; // initial size of array
    struct WordCount *word_counts = malloc(max_words * sizeof(struct WordCount));

    // Read input line by line
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        // Tokenize the line into words
        char *token = strtok(line, " ");
        while (token != NULL) {
            // Remove non-alphabetical characters from the word
            for (int j = 0; j < strlen(token); j++) {
                if (token[j] < 'a' || token[j] > 'z') {
                    if (token[j] < 'A' || token[j] > 'Z') {
                        int n, m;
                        // Shift characters to the left to remove non-alphabetical characters
                        for (n = m = 0; token[n] != '\0'; n++) {
                            if (token[n] != token[j]) {
                                token[m++] = token[n];
                            }
                        }
                        token[m] = '\0';
                    }
                }
            }
            // Remove trailing punctuation from the word
            char *end = token + strlen(token) - 1;
            while (end > token && !((*end>='a' && *end<='z') || (*end>='A' && *end<='Z'))) {
                *end = '\0';
                end--;
            }
            // Convert the word to lowercase
            char *p = token;
            while (*p) {
                *p = tolower(*p);
                p++;
            }
            // Check if the word is already in the array
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            // Add the word to the array if it is not already present
            if (i == num_words) {
                if (num_words == max_words) {
                    // Increase the size of the array if necessary
                    max_words += 1;
                    word_counts = realloc(word_counts, max_words * sizeof(struct WordCount));
                }
                strncpy(word_counts[i].word, token, MAX_WORD_LENGTH);
                word_counts[i].count = 1;
                num_words++;
            }
            token = strtok(NULL, " ");
        }
    }
    // Sort the array of word counts alphabetically
    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(word_counts[i].word, word_counts[j].word) > 0) {
                struct WordCount temp = word_counts[i];
                word_counts[i] = word_counts[j];
                word_counts[j] = temp;
            }
        }
    }
    int i;
    for (i = 0; i < num_words; i++) {//print the word and its count
        if (strcmp(word_counts[i].word, "\n") != 0 && strcmp(word_counts[i].word, " ") != 0){
            printf("%s => %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
    free(word_counts);//free the memory
    return 0;
}
