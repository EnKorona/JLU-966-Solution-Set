

void getFactors(int n) {
    if (n == 1) printf("0\n");
    bool sign = false;
    printf("%d = ", n);
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            if (!sign) {
                printf("%d", i);
                sign = true;
            } else {
                printf("* %d", i);
            }
            n /= i;
        }
    }
}