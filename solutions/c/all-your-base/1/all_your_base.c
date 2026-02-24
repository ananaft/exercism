#include "all_your_base.h"

int32_t power(int8_t base, int8_t exp)
{
	if (exp == 0) return 1;
	if (exp < 0) return 1 / power(base, -exp);

	return base * power(base, exp - 1);
}

size_t rebase(int8_t digits[], int16_t input_base, int16_t output_base, size_t input_length)
{
	int32_t sum = 0;
	size_t output_length = 0;

	if (input_length == 0)
		return 0;
	if (input_base <= 1)
		return 0;
	if (output_base <= 1)
		return 0;

	for (size_t i = 1; i <= input_length; i++) {
		if (digits[input_length - i] < 0)
			return 0;
		if (digits[input_length - i] >= input_base)
			return 0;
		sum += digits[input_length - i] * power(input_base, i - 1);
	}
	do {
		digits[output_length] = sum % output_base; // will be reverse order
		sum /= output_base;
		output_length ++;
	} while (sum > 0);

	int8_t reversed[output_length];
	for (size_t i = 1; i <= output_length; i++) {
		reversed[i - 1] = digits[output_length - i];
	}
	for (size_t i = 0; i < output_length; i++) {
		digits[i] = reversed[i];
	}

	return output_length;
}
