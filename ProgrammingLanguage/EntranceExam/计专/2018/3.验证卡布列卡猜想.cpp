

bool verify() {
    int n, max, min;
    int num[4];
    scanf("%d", &n);
    while (n != 6174) {
        for (int i = 0; i < 4; i++) {
            a[i] = n % 10;
            n /= 10;
        }
        min = max = 0;
        sort(a, a + 4);
        for (int i = 0; i < 4; i++) {
            min = min * 10 + a[i];
            max = max * 10 + a[3 - i];
        }
        n = max - min;
        printf("max:%d min:%d n:%d\n", max, min, n);
    }
}