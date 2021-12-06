

void divisorSum(int n) {
    if (n == 1) {
        printf("1 = 1\n");
        return;
    }
    int sum = 1;
    printf("1");
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            printf("+%d", i);
        }
    }
    printf("=%d\n", sum);
}