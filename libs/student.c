#include "student.h"

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender)
{
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

void print_student(struct student_t *student, int tempshow)
{
    for (int j = 0; j < tempshow; j++)
    {
        printf("%s|%s|%s|", student[j].id, student[j].name, student[j].year);
        if (student[j].gender == GENDER_MALE)
        {
            printf("male\n");
        }
        else
        {
            printf("female\n");
        }
    }
}

void print_student_details(struct student_t *student, int tempallshow)
{
    for (int j = 0; j < tempallshow; j++)
    {
        printf("%s|%s|%s|", student[j].id, student[j].name, student[j].year);
        if (student[j].gender == GENDER_MALE)
        {
            printf("male|");
        }
        else
        {
            printf("female|");
        }
        if (student[j].dorm != NULL)
        {
            printf("%s\n", student[j].dorm->name);
        }
        else
        {
            printf("unassigned\n");
        }
    }
}

void assign_student(struct student_t *student, struct dorm_t *dorm, char *nim, char *ldorm, int size_student, int size_dorm)
{
    struct dorm_t *target_dorm = NULL;
    struct student_t *target_student = NULL;

    for (int i = 0; i < size_dorm; i++)
    {
        if (strcmp(dorm[i].name, ldorm) == 0)
        {
            target_dorm = &dorm[i];
            break;
        }
    }

    if (target_dorm == NULL)
        return;

    for (int i = 0; i < size_student; i++)
    {
        if (strcmp(student[i].id, nim) == 0)
        {
            target_student = &student[i];
            break;
        }
    }

    if (target_student == NULL || target_dorm->capacity <= target_dorm->residents_num)
        return;

    if (target_student->dorm != NULL)
    {
        leave_student(student, dorm, nim, size_student, size_dorm);
    }

    target_student->dorm = target_dorm;
    target_dorm->residents_num++;
}

void move_student(struct student_t *student, struct dorm_t *dorm, char *nim, char *ldorm, int size_student, int size_dorm)
{
    assign_student(student, dorm, nim, ldorm, size_student, size_dorm);
}

void leave_student(struct student_t *student, struct dorm_t *dorm, char *token, int temp_size_student, int temp_size_dorm)
{
    struct student_t *target_student = NULL;
    struct dorm_t *current_dorm = NULL;

    for (int i = 0; i < temp_size_student; i++)
    {
        if (strcmp(student[i].id, token) == 0)
        {
            target_student = &student[i];
            break;
        }
    }

    if (target_student == NULL || target_student->dorm == NULL)
        return;

    current_dorm = target_student->dorm;

    target_student->dorm = NULL;
    current_dorm->residents_num--;
}
