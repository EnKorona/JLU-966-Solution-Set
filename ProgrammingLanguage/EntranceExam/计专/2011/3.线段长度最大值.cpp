#include <stdio.h>
#include <math.h>

double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void getMax(int row[], int column[]) {
    double max = 0.0;
    for (int i = 0; i < 99; i++) {
        for (int j = i + 1; j < 100; j++) {
            double dist = dist(x[i], y[i], x[j], y[j]);
            max = max > dist ? max : dist;
        }
    }
    return max;
}