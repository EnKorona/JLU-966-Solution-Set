#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
    int a[20][10];
    double sum = 0.0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < 20; i++) {
        sum += a[i][0] + a[i][9];
    }
    for (int i = i; i < 9; i++) {
        sum += a[0][j] + a[19][j];
    }
    printf("%lf", sum / 56);
}