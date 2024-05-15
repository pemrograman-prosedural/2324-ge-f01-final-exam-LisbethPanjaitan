#include <stdio.h>
#include <string.h>
#include "libs/student.h"
#include "libs/dorm.h"
#include "libs/gender.h"


#define MAX_STUDENTS 100
#define MAX_DORMS 100

struct student_t students[MAX_STUDENTS];
struct dorm_t dorms[MAX_DORMS];
int student_count = 0;
int dorm_count = 0;
int running = 1;

void process_command(char *command) {
    if (strncmp(command, "student-add#", 12) == 0) {
        char id[20], name[50], year[5], gender[10];
        enum gender_t gender_enum;
        sscanf(command + 12, "%[^#]#%[^#]#%[^#]#%s", id, name, year, gender);
        gender_enum = (strcmp(gender, "male") == 0) ? GENDER_MALE : GENDER_FEMALE;
        students[student_count++] = create_student(id, name, year, gender_enum);
    } else if (strncmp(command, "dorm-add#", 9) == 0) {
        char name[20], gender[10];
        unsigned short capacity;
        enum gender_t gender_enum;
        sscanf(command + 9, "%[^#]#%hu#%s", name, &capacity, gender);
        gender_enum = (strcmp(gender, "male") == 0) ? GENDER_MALE : GENDER_FEMALE;
        dorms[dorm_count++] = create_dorm(name, capacity, gender_enum);
    } else if (strncmp(command, "assign-student#", 15) == 0) {
        char id[20], dorm[20];
        sscanf(command + 15, "%[^#]#%s", id, dorm);
        assign_student(students, dorms, id, dorm, student_count, dorm_count);
    } else if (strncmp(command, "student-leave#", 14) == 0) {
        char id[20];
        sscanf(command + 14, "%s", id);
        leave_student(students, dorms, id, student_count, dorm_count);
    } else if (strcmp(command, "student-print-all-detail") == 0) {
        print_student_details(students, student_count);
    } else if (strcmp(command, "dorm-print-all-detail") == 0) {
        print_dorm_detail(dorms, dorm_count);
    }
}

int main() {
    char command[100];

    while (running && fgets(command, sizeof(command), stdin)) {
        command[strcspn(command, "\n")] = '\0'; // Remove newline character if present
        process_command(command);
    }

    return 0;
}
