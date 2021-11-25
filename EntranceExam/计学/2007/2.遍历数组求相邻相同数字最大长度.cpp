/*
 * 1. 设置len表示当前平台长度，maxlen表示最大平台长度
 * 2. 遍历数组，若当前元素与前一个元素相同，则当前平台长度+1
 * 3. 若当前元素与前一个元素不同，则比较当前平台长度与maxlen，如果大于maxlen则更新maxlen
 * 4. 数组遍历结束后，比较最后一个平台与maxlen
 */

int tableLen(int A[], int n) {
    if (n == 0 || n == 1) return n;
    int len = 1, maxlen = 1;
    for (int i = 1; i < n; i++) {
        if (A[i] == A[i - 1]) len++;
        else {
            maxlen = len > maxlen ? len : maxlen;
            len = 1;
        }
    }
    if (len > maxlen) maxlen = len;
    return maxlen;
}