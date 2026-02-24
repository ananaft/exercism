#ifndef ALL_YOUR_BASE_H
#define ALL_YOUR_BASE_H

#include <stdint.h>
#include <stddef.h>

#define DIGITS_ARRAY_SIZE 64

int32_t power(int8_t base, int8_t exp);
size_t rebase(int8_t digits[], int16_t input_base, int16_t output_base, size_t input_length);

#endif
