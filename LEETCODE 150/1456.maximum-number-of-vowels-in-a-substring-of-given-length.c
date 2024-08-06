int isVowel(char ch)
{
    char vowels[] = "aeiouAEIOU";
    return (strchr(vowels, ch) != NULL);
}

int maxVowels(char* s, int k) {
    if (k > strlen(s)) {
        return 0;
    }
    
    int max_vowel = 0;
    for (int i = 0; i < k; i++) {
        if (isVowel(s[i])) {
            max_vowel++;
        }
    }
    
    int l = 0;
    int r = k - 1;
    int count = max_vowel;
    while (r < strlen(s) - 1) {
        if (isVowel(s[l])) {
            count--;
        }
        l++;
        r++;
        if (isVowel(s[r])) {
            count++;
        }
        if (count > max_vowel) {
            max_vowel = count;
        }
    }

    return max_vowel;
