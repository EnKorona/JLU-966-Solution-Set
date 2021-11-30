

int *insert(int a[], int x, int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > x) {
            a[i + 1] = a[i];
        } else {
            a[i] = x;
            return a;
        }
    }
}