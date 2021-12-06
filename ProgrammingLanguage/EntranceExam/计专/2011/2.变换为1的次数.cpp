

int timesToZero(int n) {
    int step = 1;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
        step++;
    }
    return step;
}