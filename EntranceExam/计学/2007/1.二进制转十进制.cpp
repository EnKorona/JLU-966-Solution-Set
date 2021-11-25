/*
 * 1. 主串S，子串T，分别求出两个字符串的长度
 * 2. 从S的第一个字符开始，将T字符串与S顺次比较
 * 3. 如果匹配失败则将S回溯到下一个字符，将T从这个位置重新开始顺次比较
 */

int binaryToDecimal(char *s) {
    int res = 0, i = 0;
    while (s[i] != '*') {
        res = res * 2 + s[i] - '0';
        i++;
    }
    return res;
}