#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

struct ListNode() {
int date;
ListNode *next;
}

bool isPrime(int n) {
    if (n < 0) n = -n;
    if (n < 2) return true;
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void deletePrime(ListNode *head) {
    ListNode *p = head->next;
    while (p->next != nullptr) {
        if (isPrime(p->data)) {
            p->next = p->next->next;
        }
    }
}

ListNode *insertionSort(ListNode *head) {
    ListNode *lastSorted = head->next;
    ListNode *curr = head->next;
    while (curr != nullptr) {
        if (lastSorted->val <= curr->val) {
            lastSorted = lastSorted->next;
        } else {
            ListNode *prev = head;
            while (prev->next->val >= curr->val) {
                prev = prev->next;
            }
            lastSorted->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
        }
        curr = lastSorted->next;
    }
    return head;
}

ListNode *getAns(ListNode *head) {
    deletePrime(head);
    return insertionSort(head);
}