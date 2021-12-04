#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
struct Teacher {
    int id;
    int gender;
    char name[20];
    int year;
    Teacher *next;
}

struct Teacher *create(Teacher *head) {
    FILE *file;
    Teacher *q = head;
    if ((file = fopen("input.txt", "r")) == NULL) {
        printf("File Open Error!");
        exit(0);
    }
    while (!feof(file)) {
        Teacher *p = new Teacher();
        fscanf(file, "%d %d %s %d", &p->id, &p->gender, p->name, &p->year);
        q->next = p;
        q = p;
    }
    fclose(file);
    return head;
}

struct Teacher *insert(Teacher *head) {
    Teacher *temp = new Teacher();
    scanf("%d %d %s %d", &temp->id, &temp->gender, temp->name, &temp->year);
    Teacher q = head;
    while (q->next != nullptr && q->next->id < temp->id) {
        q = q->next;
    }
    temp->next = q->next;
    q->next = temp;
    return head;
}