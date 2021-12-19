#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int *multiply(int a[], int b[]) {
    int *c = new int[100];
    memset(c, 0, sizeof(c));
    int sizea = a.size();
    int sizeb = b.size();
    for (int i = 0; i < sizea; i++) {
        for (int j = 0; j < sizeb; j++) {
            c[i + j] += a[i] * b[j];
        }
    }
    for (int i = 0; i < sizea + sizeb; i++) {
        if (c[i] >= 10) {
            c[i + 1] += c[i] / 10;
            c[i] = c[i] % 10;
        }
    }
    return c;
}