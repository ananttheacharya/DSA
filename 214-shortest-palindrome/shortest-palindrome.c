char* shortestPalindrome(char* s) {
    int n = strlen(s);

    if (n == 0) {
        char* result = malloc(1);
        result[0] = '\0';
        return result;
    }

    

    int len = 2 * n + 1;

    char* combined = malloc((len + 1) * sizeof(char));

    for (int i = 0; i < n; i++) {
        combined[i] = s[i];
    }

    combined[n] = '#';

    for (int i = 0; i < n; i++) {
        combined[n + 1 + i] = s[n - 1 - i];
    }

    combined[len] = '\0';


    int* lps = calloc(len, sizeof(int));

    for (int i = 1; i < len; i++) {
        int j = lps[i - 1];

        while (j > 0 && combined[i] != combined[j]) {
            j = lps[j - 1];
        }

        if (combined[i] == combined[j]) {
            j++;
        }

        lps[i] = j;
    }


    int palPrefixLen = lps[len - 1];

    int suffixLen = n - palPrefixLen;

  
    char* result = malloc((n + suffixLen + 1) * sizeof(char));

   

    for (int i = 0; i < suffixLen; i++) {
        result[i] = s[n - 1 - i];
    }

    

    for (int i = 0; i < n; i++) {
        result[suffixLen + i] = s[i];
    }

    result[n + suffixLen] = '\0';

    free(combined);
    free(lps);

    return result;
}