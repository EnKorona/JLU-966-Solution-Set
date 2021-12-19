#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
char M1[3] = {'Y', 'N', '2'};
char M2[3] = {'y', 'n', '1'};

int sayByRobot(char x) {
    for (int i = 0; i < 3; i++) {
        if (x == M1[i]) return 1;
    }
    return 2;
}

bool judge(char str[]) {
    int robot = 1;
    if (sayByRobot(str[0]) != robot) return false; // 如果不是M1先说的话，则为false
    int len = strlen(str);
    for (int i = 1; i < len; i++) {
        if (str[i] == '2') {
            robot = 1;
        } else if (str[i] == '1') {
            robot = 2;
        } else if (sayByRobot(str[i]) != robot) {
            return false;
        }
    }
    if (str[len - 1] != '1' && str[len - 1] != '2') return false;
    return true;
}