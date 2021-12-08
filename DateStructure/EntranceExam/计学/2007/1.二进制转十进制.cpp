
int binaryToDecimal(char *s) {
    int res = 0, i = 0;
    while (s[i] != '*') {
        res = res * 2 + s[i] - '0';
        i++;
    }
    return res;
}