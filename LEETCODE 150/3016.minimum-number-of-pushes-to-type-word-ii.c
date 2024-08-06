int compare(const void *a, const void *b) {
    return (*(int *)b) - (*(int *)a);
}

int minimumPushes(char* word) {
    int hash[26] = {0};
    int n = strlen(word);

    // Count the frequency of each character
    for (int i = 0; i < n; i++) {
        hash[word[i] - 'a']++;
    }

    // Sort the frequencies in descending order
    qsort(hash, 26, sizeof(int), compare);

    int pushes = 0, multiplier = 1, count = 0;

    // Calculate the minimum pushes needed
    for (int i = 0; i < 26; i++) {
        if (hash[i] == 0) break; 
        
        pushes += hash[i] * multiplier;
        count++;
        
        if (count == 8) {
            multiplier++;
            count = 0;
        }
    }

    return pushes;
}
