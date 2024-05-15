#ifndef DORM_H
#define DORM_H 

#include "gender.h"
#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

struct dorm_t
{
  char name[20];
  unsigned short capacity;
  enum gender_t gender;
  unsigned short residents_num;
};

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender);
void print_dorm(struct dorm_t *dorm, int tempshow);
void print_dorm_detail(struct dorm_t *dorm, int tempshow);
#endif
