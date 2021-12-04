

void count() {
    int jc = 1; //等比例扩大三倍，可省去小数计算
    int jm = 9;
    int jw = 15;
    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 33; j++) {
            int k = 100 - i - j;
            if (i * jw + j * jm + k * jz == 300) {
                prinf("鸡翁%d只，鸡母%d只，鸡雏%d只\n", i, j, k);
            }
        }
    }
}