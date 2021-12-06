

double similarSin(int x) {
    double ans = 0.0, single = x;
    int sign = 1, n = 1;
    while (single > 1e-5) {
        ans += sign * single;
        single = single * x * x / (n + 1) / (n + 2);
        n += 2;
        sign *= -1;
    }
    return ans;
}