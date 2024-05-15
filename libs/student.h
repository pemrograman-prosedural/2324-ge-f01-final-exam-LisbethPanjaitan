#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"

struct student_t {
    char id[12];
    char name[40];
    char year[5];
    enum gender_t gender;
    struct dorm_t *dorm;
};

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender);
void print_student_details(struct student_t *student, int tempallshow);
void assign_student(struct student_t *student, struct dorm_t *dorm, char *nim, char *ldorm, int size_student, int size_dorm);
void leave_student(struct student_t *student, struct dorm_t *dorm, char *token, int temp_size_student, int temp_size_dorm);

#endif
