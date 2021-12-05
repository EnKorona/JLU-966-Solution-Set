#include <stdio.h>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void func() {
    int prime[1000];
    int ans[1000];
    int n = 0;
    for (int i = 2; i <= 2000; i++) {
        if (isPrime(i)) {
            prime[n++] = i;
        }
    }
    for (int i = 0; i < k - 1; i++) {
        ans[i] = prime[i + 1] - prime[i];
        printf("%d ", ans[i]);
    }
}