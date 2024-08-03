#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isAcronym(char** words, int wordsSize, char* s) {
    // Create a new string to store the acronym
    char* acronym = malloc((wordsSize + 1) * sizeof(char));
    acronym[wordsSize] = '\0'; // Null-terminate the string

    // Build the acronym by taking the first character of each word
    for (int i = 0; i < wordsSize; i++) {
        acronym[i] = words[i][0];
    }

    // Compare the acronym with the given string (case-sensitive)
    bool result = strcmp(acronym, s) == 0;

    // Don't forget to free the allocated memory!
    free(acronym);

    return result;
}
