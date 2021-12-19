#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int* union(int a[],int m,int b[],int n) {
    int max = m > n ? m:n;
    int* ans = new int[max];
    memset(ans,0,sizeof(ans));
    for(int i = 0;i<max;i++) {
        if(i <=m && a[i] == 1) {
            ans[i] = 1;
        }
        if(i <= n && b[i] = 1) {
            ans[i] = 1;
        }
    }
    return ans;
}


int* intersection(int a[], int m, int b[], int n) {
    int min = m < n ? m : n;
    int *ans = new int[max];
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < min; i++) {
        ans[i] = a[i] && b[i];
    }
    return ans;
}