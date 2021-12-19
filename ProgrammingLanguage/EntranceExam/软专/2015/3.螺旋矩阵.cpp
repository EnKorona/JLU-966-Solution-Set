#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int **circleMatrix() {
    int a[10][10];
    memset(a, 0, sizeof(a));
    int cnt = 1;
    int row = 0, col = -1;
    for (int i = 0; i <= n / 2; i++) {
        while (col + 1 < n && a[row][col + 1] == 0) {
            col++;
            a[row][col] = cnt++;
        }
        while (row + 1 < n && a[row + 1][col] == 0) {
            row++;
            a[row][col] = cnt++;
        }
        while (col - 1 >= 0 && a[row][col - 1] == 0) {
            col--;
            a[row][col] = cnt++;
        }
        while (row - 1 >= 0 && a[row - 1][col] == 0) {
            row--;
            a[row][col] = cnt++;
        }
    }
    return a;
}