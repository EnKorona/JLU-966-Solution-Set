
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

double calc(int n) {
    if (n == 0) return 0;
    return n * 1.0 / ((n - 1) * factorial(n + 2)) + calc(n - 1);
}