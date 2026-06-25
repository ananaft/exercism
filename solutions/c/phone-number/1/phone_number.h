#ifndef PHONE_NUMBER_H
#define PHONE_NUMBER_H

#define OUTPUT_LEN 10
#define CLEAN_LEN 11

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

char *clean(const char *input);
uint8_t validate(const char *input);
char *phone_number_clean(const char *input);

#endif
