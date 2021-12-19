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

void simplifiedFractions() {
    ListNode *head = (ListNode *) malloc(sizeof(ListNode));
    head->fz = 0;
    head->fm = 1;
    head->value = 0;
    int fz, fm, gcd;
    ListNode *p, *q;
    for (int i = 0; i < 100; i++) {
        scanf("%d %d", &fz);
        scanf("%d %d", &fm);
        gcd = gcd(fz, fm);
        p->fz = fz / gcd;
        p->fm = fm / gcd;
        p->value = (double) fz / fm;
        q = head;
        while (q->next != nullptr && p->value > q->value) {
            q = q->next;
        }
        if (q->value == q->next->value) continue;
        p->next = q->next;
        q->next = p;
    }
    while (p != nullptr) {
        printf("%d/%d ", p->fz, p->fm);
        p = p->next;
    }
}