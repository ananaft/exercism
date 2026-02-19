#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
	uint64_t possible_factor = 2;
	uint8_t count = 0;
	uint64_t remainder = n;

	if (n < 2) return count;

	while (possible_factor <= remainder) {
		if (remainder % possible_factor == 0) {
			factors[count] = possible_factor;
			remainder /= possible_factor;
			count++;
		} else {
			possible_factor++;
		}
	}

	return count; 
}
