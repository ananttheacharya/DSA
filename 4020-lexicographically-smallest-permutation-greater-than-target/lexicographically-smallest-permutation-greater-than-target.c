char* lexGreaterPermutation(char* s, char* target) {
    int n = strlen(s);
    int cnt[26] = {0};

    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }

    char *ans = malloc((n + 1) * sizeof(char));

    for (int i = 0; i < n; i++) {
        int x = target[i] - 'a';

        if (cnt[x] > 0) {
            cnt[x]--;
            ans[i] = target[i];
        } else {
            int j;

            for (j = x + 1; j < 26; j++) {
                if (cnt[j] > 0)
                    break;
            }

            if (j < 26) {
                ans[i] = 'a' + j;
                cnt[j]--;

                int pos = i + 1;

                for (int k = 0; k < 26; k++) {
                    while (cnt[k] > 0) {
                        ans[pos++] = 'a' + k;
                        cnt[k]--;
                    }
                }

                ans[n] = '\0';
                return ans;
            }

            for (j = i - 1; j >= 0; j--) {
                cnt[target[j] - 'a']++;

                int cur = target[j] - 'a';

                for (int k = cur + 1; k < 26; k++) {
                    if (cnt[k] > 0) {
                        ans[j] = 'a' + k;
                        cnt[k]--;

                        int pos = j + 1;

                        for (int p = 0; p < 26; p++) {
                            while (cnt[p] > 0) {
                                ans[pos++] = 'a' + p;
                                cnt[p]--;
                            }
                        }

                        ans[n] = '\0';
                        return ans;
                    }
                }
            }

            ans[0] = '\0';
            return ans;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        cnt[target[i] - 'a']++;

        int cur = target[i] - 'a';

        for (int j = cur + 1; j < 26; j++) {
            if (cnt[j] > 0) {
                ans[i] = 'a' + j;
                cnt[j]--;

                int pos = i + 1;

                for (int k = 0; k < 26; k++) {
                    while (cnt[k] > 0) {
                        ans[pos++] = 'a' + k;
                        cnt[k]--;
                    }
                }

                ans[n] = '\0';
                return ans;
            }
        }
    }

    ans[0] = '\0';
    return ans;
}