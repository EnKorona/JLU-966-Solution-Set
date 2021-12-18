#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;

bool appeared(int f[], int size, int n) {
    bool visit[] = new bool[size];
    memset(visit, false, sizeof(bool) * size);
    for (int i = 0; i < size; i++) {
        int num = 0;
        for (int j = 0; j < n; j++) {
            num = num * 2 + f[(i + j) % size];
        }
        if (visit[num]) {
            return false;
        } else {
            visit[num] = true;
        }
    }
    return true;
}

void fun(int n) {
    const int size = pow(2, n);
    int *f = new int[size];
    memset(f, 0, sizeof(int) * size);
    while (1) {
        int j = 0;
        while (f[j] == 1) {
            f[j++] = 0;
        }
        f[j] = 1;
        if (appeared(f, size, n)) {
            for (int i = 0; i < size; i++) {
                printf("%d ", f[i]);
            }
            return;
        }
    }
}