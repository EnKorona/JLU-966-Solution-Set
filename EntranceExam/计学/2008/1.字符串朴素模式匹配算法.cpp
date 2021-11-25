/*
 * 1. 主串S，子串T，分别求出两个字符串的长度
 * 2. 从S的第一个字符开始，将T字符串与S顺次比较
 * 3. 如果匹配失败则将S回溯到下一个字符，将T从这个位置重新开始顺次比较
 */

int indexSubString(string S, string T) {
    int sLen = S.length();
    int tLen = T.length();
    if (tLen > sLen) return -1;
    int i = 0, j = 0;
    while (i < sLen && j < tLen) {
        if (S[i] == T[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == tLen) return i - tLen + 1;
    return -1;
}