int isSubstring(char *s, char *word) {
    int s1_len, s2_len;
    s1_len = strlen(s);
    s2_len = strlen(word);

    for (int i = 0; i <= s2_len - s1_len; i++) {
        int j;
        for (j = 0; j < s1_len; j++) {
            if (s[j] != word[i + j]) {
                break;
            }
        }

        if (j == s1_len) {
            return 1;
        }
    }
    return 0;
}

int numOfStrings(char **patterns, int patternsSize, char *word) {
    int count = 0;
    for (int i = 0; i < patternsSize; i++) {
        if (isSubstring(patterns[i], word)) {
            count++;
        }
    }
    return count;
}