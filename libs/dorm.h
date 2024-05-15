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
  char name[20]; // nama dorm dengan panjang 20 karakter
  unsigned short capacity; // kapasitas dorm diatur ke unsigned
  enum gender_t gender;
  unsigned short residents_num;
};

// membuat dorm baru
struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender);
// cetak detail dorm
void print_dorm(struct dorm_t *dorm, int tempshow);
// cetak detail lengkap dorm
void print_dorm_detail(struct dorm_t *dorm, int tempshow);

#endif
