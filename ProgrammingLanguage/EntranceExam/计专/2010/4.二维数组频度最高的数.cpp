#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

int getFrequency(int a[][5]) {
    map<int, int> mp;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            mp[a[i][j]]++;
        }
    }
    int max = 0, maxIndex;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second > max) {
            maxIndex = it->first;
            max = it->second;
        }
    }
    return maxIndex;
}