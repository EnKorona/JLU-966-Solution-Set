#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Student{
    int number;
    char name[20];
    int score;
    int gender;
    struct Student* next;
};

struct Student* create() {
    Student* head,*p;
    head = (struct Student*) malloc (sizeof (struct Student));

}

int output(struct Student* head) {
    FILE* fp;
    if((fp = fopen("student.txt","w")) == nullptr) {
        printf("Open File Error!");
        return -1;
    }
    struct Student* p = head;
    while(p != nullptr) {
        fprintf(fp,"%d ",p -> number);
        fprintf(fp,"%s ",p -> name);
        fprintf(fp,"%d ",p -> score);
        fprintf(fp,"%d\n",p -> gender);
        p = p -> next;
    }
    fclose(fp);
    return 0;
}