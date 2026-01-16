#include "binary.h"
// #include <stdio.h>

int convert(const char *input)
{
	const char *first_char = input;
	int factor = 0;
	int result = 0;

	if (*input == '\0') return INVALID;

	while (*input != '\0') {
		if (*input != '0' && *input != '1') return INVALID;
		input++; 
	}
	input--;

	while (input >= first_char) {
		result += (*input - '0') << factor;
		factor++;
		input--;
	} 

	return result;
}
