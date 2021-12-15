

void sort(int a[][N],int m,int n) {
    for (int i = 0; i < m * n - 1; i++) { //二维数组是按行优先一维连续存储，故当作一维数组进行冒泡排序
        for (int j = i + 1; j < m * n; j++) {
            if (a[0][i] > a[0][j]) {
                int tmp = a[0][i];
                a[0][i] = a[0][j];
                a[0][j] = tmp;
            }
        }
    }
}