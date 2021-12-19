#include <stdio.h>
#include <iostream>

using namespace std;

struct Student {
    int number;
    char name[20];
    int score;
    struct Student *next;
}

Student build() {
    Student head = (Student *) malloc(sizeof(Student));
    Student p1 = head;
    FILE *fp;
    if ((fp = fopen("student2.txt", "r")) == nullptr) {
        printf("Open File Error!");
        return nullptr;
    }
    while (!feof(fp)) {
        Student p = (Student *) malloc(sizeof(Student));
        fscanf(fp, "%d %s %d", &p->number, p->name, &p->score);
        p1->next = p;
        p1 = p;
    }
    p1->next = nullptr;
    return head;
}

void sort(Student *head) {
    Student p = head->next;
    Student q;
    while (p != nullptr) {
        q = p->next;
        while (q != nullptr) {
            if (p->score > q->score) {
                Student *tmp;
                tmp = p;
                p = q;
                q = tmp;
                Student *tmpnext;
                tmp->next = p->next;
                p->next = q->next;
                q->next = tmp->next;
            }
            q = q->next;
        }
        p = p->next;
    }
}

Student merge(Student *head1, Student *head2) {
    Student p = head->next;
    Student q = head->next;
    Student newHead = (Student *) malloc(sizeof(Student));
    newHead->next = nullptr;
    Student k = newHead;
    while (p != nullptr && q != nullptr) {
        if (p->score <= q->score) {
            k->next = p;
            k = p;
            p = p->next;
        } else {
            k->next = q;
            k = q;
            q = q->next;
        }
    }
    if (q != nullptr) {
        k->next = q;
    }
    if (p != nullptr) {
        k->next = p;
    }
    return newHead;
}