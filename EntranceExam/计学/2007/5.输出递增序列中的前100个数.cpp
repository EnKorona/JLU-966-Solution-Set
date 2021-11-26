
void outputArray() {
    int a[101];
    a[1] = 1;
    for (int k = 2, i = 1, j = 1; k <= 100; k++) {
        if (a[i] * 2 == a[j] * 3) {
            a[k] = a[i] * 2;
            i++;
            j++;
        } else if (a[i] * 2 < a[j] * 3) {
            a[k] = a[i] * 2;
            i++;
        } else {
            a[k] = a[j] * 3;
            j++;
        }
    }
    for (int i = 1; i <= 100; i++) printf("%d\n", a[i]);
    return;
}
