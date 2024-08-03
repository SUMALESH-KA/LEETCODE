#include <string.h>

char* maximumOddBinaryNumber(char* s) {
    int ones = 0;
    int zeros = 0;
    int length = strlen(s);

    for (int i = 0; i < length; i++) {
        if (s[i] == '1') {
            ones++;
        } else {
            zeros++;
        }
    }

    // The largest odd binary number will have all '1's followed by all '0's,
    // but the last character must be '1'.
    for (int i = 0; i < ones - 1; i++) {
        s[i] = '1';
    }
    for (int i = ones - 1; i < length - 1; i++) {
        s[i] = '0';
    }
    s[length - 1] = '1';

    return s;
}
