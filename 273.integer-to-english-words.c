#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Arrays of strings for one-digit and two-digit numbers
char* below_20[] = {"", "One ", "Two ", "Three ", "Four ", "Five ",
                    "Six ", "Seven ", "Eight ", "Nine ", "Ten ",
                    "Eleven ", "Twelve ", "Thirteen ", "Fourteen ",
                    "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ",
                    "Nineteen "};

char* tens[] = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ",
                "Sixty ", "Seventy ", "Eighty ", "Ninety "};

char* thousands[] = {"", "Thousand ", "Million ", "Billion "};

// Function to convert a number less than 1000 into words
char* numberToWordsLessThan1000(int num) {
    char* result = malloc(100 * sizeof(char));
    result[0] = '\0';

    if (num >= 100) {
        strcat(result, below_20[num / 100]);
        strcat(result, "Hundred ");
        num %= 100;
    }

    if (num >= 20) {
        strcat(result, tens[num / 10]);
        num %= 10;
    }

    if (num > 0) {
        strcat(result, below_20[num]);
    }

    return result;
}

// Function to convert a given number to words
char* numberToWords(int num) {
    if (num == 0) {
        return "Zero";
    }

    char* result = malloc(1000 * sizeof(char));
    result[0] = '\0';

    int i = 0;
    while (num > 0) {
        if (num % 1000 != 0) {
            char* temp = numberToWordsLessThan1000(num % 1000);
            strcat(temp, thousands[i]);
            strcat(temp, result);
            strcpy(result, temp);
            free(temp);
        }
        num /= 1000;
        i++;
    }

    // Remove trailing space
    result[strlen(result) - 1] = '\0';

    return result;
}