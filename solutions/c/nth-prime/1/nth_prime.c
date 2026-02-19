#include "nth_prime.h"

uint32_t nth(uint32_t n)
{
	uint32_t count = 2;
	uint64_t current_number = 3, current_prime = 3;
	bool is_prime;

	if (n == 0) return 0;
	if (n == 1) return 2;

	for (; count < n;) {
		current_number += 2;
		is_prime = true;
		for (uint64_t check = 3; check < current_number / 2; check += 2) {
			if (current_number % check == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime) {
			current_prime = current_number;
			count++;
		}
	}

	return current_prime;
}
