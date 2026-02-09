#include "sum_of_multiples.h"

void init_array(dynamic_array_t *arr)
{
	arr->data = NULL;
	arr->length = 0;
	arr->capacity = 0;
}

void append_array(dynamic_array_t *arr, unsigned int value)
{
	if (arr->length == arr->capacity) {
		size_t new_capacity = arr->capacity == 0 ? 4 : arr->capacity * 2;
		unsigned int *new_data = realloc(
				arr->data, new_capacity * sizeof(unsigned int)
		);
		if (new_data == NULL) exit(EXIT_FAILURE);
		arr->data = new_data;
		arr->capacity = new_capacity;
	}
	
	arr->data[arr->length++] = value;
}

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit)
{
	unsigned int sum = 0;
	dynamic_array_t multiples;
	init_array(&multiples);

	for (size_t i = 0; i < number_of_factors; i++) {
		if (factors[i] == 0) continue;
		for (int f = 1; factors[i] * f < limit; f++) {
			append_array(&multiples, factors[i] * f);
		}
	}
	if (multiples.length == 0) return sum;

	for (size_t current = 0; current < multiples.length - 1; current++) {
		for (size_t i = current + 1; i < multiples.length; i++) {
			if (multiples.data[current] == multiples.data[i]) {
				multiples.data[i] = 0;
			}
		}
	}

	for (size_t i = 0; i < multiples.length; i++) {
		sum += multiples.data[i];
	}
	return sum;
}
