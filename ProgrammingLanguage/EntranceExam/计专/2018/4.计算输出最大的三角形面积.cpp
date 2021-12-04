#include <stdio.h>
#include <iostream>
#include <alogrithm>

using namespace std;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double area(int x1, int y1, int x2, int y2, int x3, int y3) {
    double a = dist(x1, y1, x2, y2);
    double b = dist(x1, y1, x3, y3);
    double c = dist(x2, y2, x3, y3);
    double s = (a + b + c) / 2;
    return (sqrt(s * (s - a) * (s - b) * (s - c)));
}

int getMax(int ax[], int ay[]) {
    double max = 0.0;
    for (int i = 0; i < 98; i++) {
        for (int j = i + 1; j < 99; j++) {
            for (int k = j + 1; k < 100; k++) {
                double a = area(x[i], y[i], x[j], y[j], x[k], y[k]);
                max = a > max ? a : max;
            }
        }
    }
    return max;
}

// 笨办法，可以用数组记录最大值，如果等于就往里加，出现了更大就把数组清空然后加入新的值。
void printMax(int ax[], int ay[], int max) {
    for (int i = 0; i < 98; i++) {
        for (int j = i + 1; j < 99; j++) {
            for (int k = j + 1; k < 100; k++) {
                double a = area(x[i], y[i], x[j], y[j], x[k], y[k]);
                if (a == max) {
                    printf("顶点坐标为：%d %d %d,最大面积为%d", i, j, k, max);
                }
            }
        }
    }
}