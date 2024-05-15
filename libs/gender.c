#include "gender.h"
#include <stdio.h>

void print_gender(enum gender_t gender ){
        switch(gender) {
            case GENDER_MALE:
                printf("Male\n");
                 break;
            case GENDER_FEMALE:
                printf("female\n");
                break;
            default;
                printf("invalid gender\n");
                break;
        
        }
}