#include "square_root.h"

uint16_t square_root(uint16_t number)
{
	uint16_t result = 1;

	while (result * result != number) {
		result = (result + number / result) / 2;
	}
	return result;
}
