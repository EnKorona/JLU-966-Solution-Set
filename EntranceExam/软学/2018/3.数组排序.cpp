
int *sort(int A[], int m, int n) {
    int res[n] = {0};
    int i = m - 1, j = m, k = 0;
    while (i >= 0 && j < n - 1) {
        if (A[i] >= A[j]) {
            res[k++] = A[i--];
        } else {
            res[k++] = A[j++];
        }
    }
    while (i >= 0) res[k++] = A[i--];
    while (j <= n - 1) res[k++] = A[j++];
    return res;
}