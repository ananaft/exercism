#include "roman_numerals.h"

char *to_roman_numeral(unsigned int number)
{
	char *result = calloc(20, sizeof(char));
	unsigned int increments[] = {
		1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
	};
	char *letters[] = {
		"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
	};
	unsigned int remainder = number;

	while (remainder > 0) {
		for (size_t i = 0; i < INCREMENTS; i++) {
			if (remainder < increments[i])
				continue;
			while (remainder >= increments[i]) {
				remainder -= increments[i];
				strcat(result, letters[i]);
			}
		}
	}

	return result;
}
