#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void generate(int n) {
    vector << vector < int >> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j) a[i][j] = 1;
            else a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
        if (i >= n) break;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[n - 1][i]);
    }
}