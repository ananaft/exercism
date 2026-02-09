#ifndef SUM_OF_MULTIPLES_H
#define SUM_OF_MULTIPLES_H

#include <stddef.h>
#include <stdlib.h>

typedef struct {
	unsigned int *data;
	size_t length;
	size_t capacity;
} dynamic_array_t;

void init_array(dynamic_array_t *arr);
void append_array(dynamic_array_t *arr, unsigned int value);
unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit);

#endif
