

int getOdd(int S) {
    int base = 1;
    int ans = 0;
    while (S != 0) {
        int last = S % 10;
        if (last % 2 == 1) {
            ans += ans * base;
            base *= 10;
        }
        S /= 10;
    }
    return ans;
}