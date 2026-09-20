int reverseDegree(char* s) {
    int sum = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        int reversePos = 'z' - s[i] + 1;
        int position = i + 1;

        sum += reversePos * position;
    }

    return sum;
}