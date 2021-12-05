#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

double f(double x) {
    return x * x * x - x * x - 1;
}

double getSimilar(double a, double b) {
    double mid = (a + b) / 2;
    while (fabs(f(mid)) > 1e-4) {
        if (f(mid) * f(a) > 0) a = mid;
        else b = mid;
        mid = (a + b) / 2;
    }
    return mid;
}