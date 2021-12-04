#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <alogrithm>

using namespace std;

struct ListNode {
    int data;
    ListNode *next;
};

void sort(ListNode *head) {
    ListNode *p = head->next, *q;
    while (p->next != nullptr) {
        q = p->next;
        while (q != nullptr) {
            if (p->data > q->data) {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}

ListNode *UnionSet(ListNode *p, ListNode *q) {
    sort(p);
    sort(q);
    ListNode *dummy = new ListNode();
    ListNode *k = dummy;
    p = p->next; // 移到第一个数据节点
    q = q->next;
    while (q != nullptr && p != nullptr) {
        if (q->data < p->data) {
            ListNode *cur = q;
            q = q->next;
            cur->next = k->next;
            k->next = cur;
            k = cur;
        } else {
            ListNode *cur = p;
            if (p->data == q->data) {
                q = q->data;
            }
            p = p->next;
            cur->next = k->next;
            k->next = cur;
            k = cur;
        }
        k->next = q != nullptr ? q : p;
    }
    return dummy;
}