#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int a[10][10];
    int num = 1;
    int row, column;
    for (int i = 0; i < 10; i++) {
        row = i, column = 0;
        while (row >= 0) {
            a[row--][column++] = num++;
        }
    }
    for (int i = 1; i < 10; i++) {
        row = 9, column = i;
        while (column <= 9) {
            a[row--][column++] = num++;
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
}