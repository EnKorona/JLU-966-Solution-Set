
int getMax(int *arr, int n) {
    if (n == 1) return arr[0];
    int subMax = getMax(arr + 1, n - 1);
    return arr[0] > subMax ? arr[0] : subMax;
}