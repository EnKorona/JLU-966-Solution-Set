
int xs(int n, k) {
    if (n == 0 & n == k) return 1;
    if (k == 0)return 2 * xs(n - 1, k);
    if (k == n) return 3 * xs(n - 1, k - 1);
    else return 2 * xs(n - 1, k) + 3 * xs(n - 1, k - 1);
}