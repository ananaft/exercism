#include "eliuds_eggs.h"

unsigned int egg_count(unsigned int number)
{
	unsigned int result = 0;

	for (unsigned int bit = 0; bit < sizeof(number) * 8; bit++) {
		if (number & 1 << bit) {
			result += 1;
		}
	}

	return result;
}
