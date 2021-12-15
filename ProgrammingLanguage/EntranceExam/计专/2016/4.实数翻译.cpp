#include <cstring>
#include <math.h>
#include <iostream>

using namespace std;

bool judge(string str, double x) {
    double ans = 0.0;
    int point = 0;
    for (int i = 0; i < str.length(); i++) {
        if ((!(str[i] >= '0' && str[i] <= '9') || str[i] != '.')) {
            return false;
        } else if (str[i] >= '0' && str[i] <= '9') {
            ans = ans * 10 + str[i] - '0';
        }
        if (str[i] == '.') {
            point = str.length() - i - 1; // 从右向左第point位是小数点
        }
    }
    ans = ans / pow(10, point);
    return ans > x;
}