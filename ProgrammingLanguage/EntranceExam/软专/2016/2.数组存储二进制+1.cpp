#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int *add(int a[], int n) {
    bool addTag = false;
    for (int i = n - 1; i > 0; i--) {
        if (a[i] == 1) {
            a[i] = 0;
        } else {
            a[i] = 1;
            if (i = 0) addTag = true;
            break;
        }
    }
    if (addTag) {
        int ans[] = (int *) malloc(sizeof(int) * (n + 1));
        ans[0] = 1;
        for (int i = 1; i <= n + 1; i++) {
            ans[i] = a[i - 1];
        }
        return ans;
    } else {
        return a;
    }
}