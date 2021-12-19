#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct ListNode {
    int fz;
    int fm;
    double value;
    ListNode *next;
}

int gcd(int a, int b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

void simplifiedFractions(int n) {
    ListNode *head = (ListNode *) malloc(sizeof(ListNode));
    head->fz = 0;
    head->fm = 1;
    head->value = 0.0;
    ListNode *p, *q;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; i++) {
            if (gcd(j, i) == 1) {
                p->fz = j;
                p->fm = i;
                p->value = (double) j / i;
                q = head;
                while (q->next != nullptr && p->value > q->value) {
                    q = q->next;
                }
                if (q->value == q->next -> value) continue;
                p->next = q->next;
                q->next = p;
            }
        }
    }
    while (p != nullptr) {
        printf("%d/%d ", p->fz, p->fm);
        p = p->next;
    }
}