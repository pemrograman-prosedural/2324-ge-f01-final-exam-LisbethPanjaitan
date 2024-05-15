#include "dorm.h"
#include <stdio.h>
#include <string.h>

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender) {
    struct dorm_t temp;
    memset(temp.name, '\0', sizeof(temp.name));
    strcpy(temp.name, _name);
    temp.capacity = _capacity;
    temp.residents_num = 0;
    temp.gender = _gender;
    return temp;
}

void print_dorm_detail(struct dorm_t *dorm, int tempshow) {
    for (int j = 0; j < tempshow; j++) {
        printf("%s|%d|%s|%d\n", dorm[j].name, dorm[j].capacity,
               dorm[j].gender == GENDER_MALE ? "male" : "female",
               dorm[j].residents_num);
    }
}
