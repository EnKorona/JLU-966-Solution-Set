#include <stdio.h>
#include <map>

using namespace std;

void printArray(int A[]) {
    map<int, int> mp;
    for (int i = 0; i < 200; i++) {
        mp[A[i]]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        printf("%d 出现的次数是 %d\n", it->first, it->second);
    }
}