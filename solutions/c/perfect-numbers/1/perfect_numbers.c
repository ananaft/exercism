#include "perfect_numbers.h"

int classify_number(int number)
{
	int sum = 0;

	if (number <= 0) return ERROR;

	for (int i = 1; i <= number / 2; i++) {
		if (!(number % i)) sum+= i;
	}

	if (number == sum) return PERFECT_NUMBER;
	if (number < sum) return ABUNDANT_NUMBER;
	if (number > sum) return DEFICIENT_NUMBER;

	return ERROR;
}
