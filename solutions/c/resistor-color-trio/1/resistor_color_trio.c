#include "resistor_color_trio.h"
#define RESISTOR_COUPLE (colors[0] * 10 + colors[1])
#define VALUE(x) (value_to_power(RESISTOR_COUPLE, 10, colors[2] - x))

int value_to_power(int value, int base, int exp)
{
	int result = value;

	if (exp > 0) {
		while (exp > 0) {
			if (exp % 2 == 1) {
				result *= base;
			}
			base *= base;
			exp /= 2;
		}
	} else if (exp < 0) {
		while (exp < 0) {
			result /= base;
			exp++;
		}
	}

	return result;
}

resistor_value_t color_code(resistor_band_t *colors)
{
	resistor_value_t result;

	if (colors[2] >= 8) {
		result.unit = GIGAOHMS;
		result.value = VALUE(9);
	} else if (colors[2] >= 5) {
		result.unit = MEGAOHMS;
		result.value = VALUE(6);
	} else if (colors[2] >= 2) {
		result.unit = KILOOHMS;
		result.value = VALUE(3);
	} else {
		result.unit = OHMS;
		result.value = VALUE(0);
	}

	return result;
}
