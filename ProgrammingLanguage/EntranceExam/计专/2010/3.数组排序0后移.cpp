#include <stdio.h>
#include <algorithm>

using namespace std;

void sort(int a[]) {
    int left = 0, right = 0, zeroNum = 0;
    while (right < 100) {
        if (a[right++] == 0) {
            zeroNum++;
        } else {
            a[left++] = a[right++];
        }
    }
    for (int i = left; i < 100; i++) {
        a[i] = 0;
    }
    for (int i = 0; i < 100; i++) {
        printf("%d ", a[i]);
    }
}
