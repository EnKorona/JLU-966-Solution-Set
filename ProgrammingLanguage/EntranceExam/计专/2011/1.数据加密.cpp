

int encrypt(int n) {
    int a[4] = {0};
    int temp, ans = 0;
    for (int i = 0; i < 4; i++) {
        temp = a % 10;
        a[i] = (temp + 5) % 10;
        a /= 10;
    }
    temp = a[0];
    a[0] = a[3];
    a[3] = temp;
    temp = a[1];
    a[1] = a[2];
    a[2] = temp;
    for (int i = 0; i < 4; i++) {
        ans = ans * 10 + a[i];
    }
    return ans;
}