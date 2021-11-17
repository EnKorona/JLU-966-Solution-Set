/*
 * 1. 新建一个长度为m+1的数组，存放斐波那契每位的数值，将前k-1位赋值。
 * 2. 如果m<=k-1，则直接返回数组对应值。
 * 3. 如果m>k-1，则从第k项开始循环计算，每一项的值等于前k项的和，直至计算到第m项，返回该值。
 */

int F(int k, int m) {
    int fib[m + 1];
    for (int i = 0; i <= k - 2; i++) fib[i] = 0; // 对数组前k-1项赋值
    fib[k - 1] = 1;
    if (m <= k - 1) return fib[m];
    else {
        for (int i = k; i <= m; i++) { // 从第k项开始循环计算
            sum = 0;
            for (int j = i - k; j < i; j++) sum += fib[j]; // 求前k项的和
            fib[i] = sum;
        }
        return fib[m];
    }
