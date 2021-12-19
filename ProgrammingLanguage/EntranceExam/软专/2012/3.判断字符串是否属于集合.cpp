#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
    char arr[100];
    scanf("%s", arr);
    int len = strlen(arr);
    if (arr[0] != 'a' || arr[len - 1] != 'd') {
        printf("N\n");
        continue;
    }
    int num = 0;
    while (arr[k] == 'a') {
        num++;
    }
    while (arr[k] == 'b') {
        num++;
    }
    while (arr[k] == 'c') {
        num++;
    }
    while (arr[k] == 'd') {
        num++;
    }
    if (num == len) {
        printf("Y\n");
    } else {
        printf("N\n");
    }
    return 0;
}