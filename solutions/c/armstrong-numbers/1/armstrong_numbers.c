#include "armstrong_numbers.h"

int determine_digits(const int *number)
{
	float divisor = 1.0f;
	int digits = 0;

	while (*number / divisor >= 1) {
		divisor *= 10.0f;
		digits++;
	}
	return digits;
}

int power(int base, int exp)
{
	if (exp == 0) return 1;
	return base * power(base, exp - 1);
}

bool is_armstrong_number(int candidate)
{
	if (candidate == 0) return true;
	int number = candidate;
	int digits = determine_digits(&number);
	int result = 0;

	while (number) {
		result += power((number % 10), digits);
		number /= 10;
	}
	return result == candidate;
}
