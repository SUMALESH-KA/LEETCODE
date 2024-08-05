char* convert(char* s, int numRows) {
    if (numRows == 1) {
        return s;
    }

    int len = strlen(s);
    char* res = malloc((len + 1) * sizeof(char));
    int index = 0;

    for (int r = 0; r < numRows; r++) {
        int increment = 2 * (numRows - 1);
        for (int i = r; i < len; i += increment) {
            res[index++] = s[i];
            if (r > 0 && r < numRows - 1 && (i + increment - 2 * r) < len) {
                res[index++] = s[i + increment - 2 * r];
            }
        }
    }
    res[index] = '\0';
    return res;
}