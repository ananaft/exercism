#ifndef PHONE_NUMBER_H
#define PHONE_NUMBER_H

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define OUTPUT_LEN 10
#define CLEAN_LEN 11

typedef enum {
	INVALID = 0,
	VALID_10 = 1,
	VALID_11 = 2,
} validation_t;

char *clean(const char *input);
uint8_t validate(const char *input);
char *phone_number_clean(const char *input);

#endif
