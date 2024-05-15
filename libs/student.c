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
    printf("%d", tempshow);
    int j;
    for (j = 0; j < tempshow; j++)
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
    printf("%d", tempallshow);
    int j = 0;
    for (j = 0; j < tempallshow; j++)
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
    int i;
    int temp_dorm;
    for (i = 0; i < size_dorm; i++)
    {
        if (strcmp(dorm[i].name, ldorm) == 0)
        {
            temp_dorm = i;
        }
    }
    for (i = 0; i < size_student; i++)
    {
        if (strcmp(student[i].id, nim) == 0)
        {
            if (dorm[temp_dorm].capacity > dorm[temp_dorm].residents_num)
            {
                student[i].dorm = malloc(1 * sizeof(struct dorm_t));
                strcpy(student[i].dorm->name, ldorm);
                dorm[temp_dorm].residents_num++;
            }
        }
    }
}

void move_student(struct student_t *student, struct dorm_t *dorm, char *nim, char *ldorm, int size_student, int size_dorm)
{
    int i;
    int dorm_temp = 0;
    int student_temp = 0;;
    char dormname_temp[255];
    for (i = 0; i < size_dorm; i++)
    {
        if (strcmp(dorm[i].name, ldorm) == 0)
        {
            dorm_temp = i;
        }
    }
    for (i = 0; i < size_student; i++)
    {
        if (strcmp(student[i].id, nim) == 0)
        {
            student_temp = i;
        }
    }

    if (student[student_temp].dorm != NULL)
    {
        strcpy(dormname_temp, student[student_temp].dorm->name);
        for (i = 0; i < size_dorm; i++)
        {
            if (strcmp(dorm[i].name, dormname_temp) == 0)
            {
                dorm[i].residents_num--;
                printf("%s--", dorm[i].name);
            }
        }
    }
    else
    {
        student[student_temp].dorm = malloc(1 * sizeof(struct dorm_t));
    }
    strcpy(student[student_temp].dorm->name, ldorm);
    dorm[dorm_temp].residents_num++;
}

void leave_student(struct student_t *student, struct dorm_t *dorm, char *token, int temp_size_student, int temp_size_dorm)
{
    int i = 0;
    char temp_dorm[255];
    for (i = 0; i < temp_size_student; i++)
    {
        if (strcmp(student[i].id, token) == 0)
        {
            strcpy(temp_dorm, student[i].dorm->name);
            strcpy(student[i].dorm->name, "left");
        }
    }

    for (i = 0; i < temp_size_dorm; i++)
    {
        if (strcmp(dorm[i].name, temp_dorm) == 0)
        {
            dorm[i].residents_num--;
        }
    }
}