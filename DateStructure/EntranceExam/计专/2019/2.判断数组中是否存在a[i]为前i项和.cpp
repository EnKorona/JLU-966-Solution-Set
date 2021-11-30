bool judge(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == sum) return true;
        sum += a[i];
    }
    return false;
}