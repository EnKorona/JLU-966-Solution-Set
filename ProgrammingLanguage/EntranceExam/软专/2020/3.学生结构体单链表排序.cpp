#include <stdio.h>
#include <iostream>

using namespace std;

struct Student {
    int number;
    char name[20];
    int score;
    struct Student *next;
}

void insertionSort(Student *head) {
    if (head == nullptr) return head;
    Student *dummyHead = new Student();
    dummyHead->next = head;
    Student *lastSorted = head;
    Student *cur = head->next;
    while (cur != nullptr) {
        if (lastSorted->score <= cur->score) {
            lastSorted = lastSorted->next;
        } else {
            Student *pre = dummyHead;
            while (pre->next->score <= cur->score) {
                pre = pre->next;
            }
            lastSorted->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
        }
        cur = lastSorted->next;
    }
    return dummyHead->next;
}