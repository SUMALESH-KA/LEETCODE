#include <stdio.h>
#include <string.h>
#include <ctype.h>

int lengthOfLastWord(const char* s) {
    int length = strlen(s);
    int i = length - 1;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Calculate the length of the last word
    int count = 0;
    while (i >= 0 && isalpha(s[i])) {
        count++;
        i--;
    }

    return count;
}

int main() {
    const char* str1 = "Hello World";
    const char* str2 = "   fly me   to   the moon  ";
    const char* str3 = "luffy is still joyboy";
    const char* str4 = "a";
    const char* str5 = "    ";

    printf("Length of last word in \"%s\": %d\n", str1, lengthOfLastWord(str1)); // Output: 5
    printf("Length of last word in \"%s\": %d\n", str2, lengthOfLastWord(str2)); // Output: 4
    printf("Length of last word in \"%s\": %d\n", str3, lengthOfLastWord(str3)); // Output: 6
    printf("Length of last word in \"%s\": %d\n", str4, lengthOfLastWord(str4)); // Output: 1
    printf("Length of last word in \"%s\": %d\n", str5, lengthOfLastWord(str5)); // Output: 0

    return 0;
}
