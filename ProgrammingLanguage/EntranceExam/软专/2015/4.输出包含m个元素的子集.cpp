#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;

void subset(int s[], int n, int m) {
    int max = pow(2, n);
    int *flag = new int[n];
    memset(flag, 0, sizeof(flag));
    for (int i = 0; i < max; i++) {
        int cnt = 0;
        for (int j = n - 1; j > 0; j--) { // 将二进制标识数组加1
            if (flag[j] == 1) {
                flag[j] = 0;
            } else {
                flag[j] = 1;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (flag[i] == 1) cnt++;
        }
        if (cnt == m) {
            printf("{ ");
            for (int i = 0; i < n; i++) {
                if (flag[i] == 1) printf("%d ", s[i]);
            }
            printf("}\n");
        }
    }
}
