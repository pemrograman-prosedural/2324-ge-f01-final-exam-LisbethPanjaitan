#include "student.h"
#include <stdio.h>
#include <string.h>

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender) {
    struct student_t temp;
    memset(temp.id, '\0', sizeof(temp.id));
    memset(temp.name, '\0', sizeof(temp.name));
    memset(temp.year, '\0', sizeof(temp.year));
    strcpy(temp.id, _id);
    strcpy(temp.name, _name);
    strcpy(temp.year, _year);
    temp.dorm = NULL;
    temp.gender = _gender;
    return temp;
}

void print_student_details(struct student_t *student, int tempallshow) {
    for (int j = 0; j < tempallshow; j++) {
        printf("%s|%s|%s|", student[j].id, student[j].name, student[j].year);
        printf(student[j].gender == GENDER_MALE ? "male|" : "female|");
        printf(student[j].dorm ? "%s\n" : "left\n", student[j].dorm->name);
    }
}

void assign_student(struct student_t *student, struct dorm_t *dorm, char *nim, char *ldorm, int size_student, int size_dorm) {
    for (int i = 0; i < size_student; i++) {
        if (strcmp(student[i].id, nim) == 0) {
            for (int j = 0; j < size_dorm; j++) {
                if (strcmp(dorm[j].name, ldorm) == 0 && dorm[j].capacity > dorm[j].residents_num) {
                    student[i].dorm = &dorm[j];
                    dorm[j].residents_num++;
                    return;
                }
            }
        }
    }
}

void leave_student(struct student_t *student, struct dorm_t *dorm, char *token, int temp_size_student, int temp_size_dorm) {
    for (int i = 0; i < temp_size_student; i++) {
        if (strcmp(student[i].id, token) == 0 && student[i].dorm) {
            for (int j = 0; j < temp_size_dorm; j++) {
                if (strcmp(dorm[j].name, student[i].dorm->name) == 0) {
                    dorm[j].residents_num--;
                    student[i].dorm = NULL;
                    return;
                }
            }
        }
    }
}
 
