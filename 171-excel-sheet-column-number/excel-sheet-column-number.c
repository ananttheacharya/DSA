int titleToNumber(char* columnTitle) {
    int result = 0;

    for (int i = 0; columnTitle[i] != '\0'; i++) {
        int value = columnTitle[i] - 'A' + 1;
        result = result * 26 + value;
    }

    return result;
}