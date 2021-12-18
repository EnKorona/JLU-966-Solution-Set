#include <stdio.h>
#include <iostream>
#include <alogrithm>
#include <math.h>

using namespace std;

struct Point {
    double x;
    double y;
}

double dist(Point p1, Point p2) {
    return sqrt(pow(p1->x - p2->x) + pow(p1->y - p2->y));
}

double area(Point p1, Point p2, Point p3) {
    double a = dist(p1, p2);
    double b = dist(p2, p3);
    double c = dist(p1, p3);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

bool isInTriangle(Point p1, Point p2, Point p3, Point o) {
    double s1 = area(p1, p2, o);
    double s2 = area(p2, p3, o);
    double s3 = area(p3, p1, o);
    double s = area(p1, p2, p3);
    return s1 + s2 + s3 == s;
}

int main() {
    Point p1, p2, p3, o;
    scanf("%lf %lf", &p1->x, &p1->y);
    scanf("%lf %lf", &p2->x, &p2->y);
    scanf("%lf %lf", &p3->x, &p3->y);
    scanf("%lf %lf", &o->x, &o->y);
    if (isInTriangle(p1, p2, p3, 0)) {
        printf("o在三角形内");
    } else {
        printf("o不在三角形内");
    }
    return;
}