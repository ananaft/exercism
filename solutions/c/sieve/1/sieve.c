#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
	uint32_t size = 0;
	if (limit < 2) return size;

	*primes = 2;
	size++;
	if (limit >= 3) {
		primes++;
		*primes = 3;
		size++;
	} else {
		return size;
	}

	for (uint32_t current = *primes;;) {
		if (size >= max_primes) return size;
		int is_prime = 1;
		current += 2;
		if (current > limit) return size;
		for (uint32_t check = 3; check < current / 2; check += 2) {
			if (current % check == 0) {
				is_prime = 0;
				break;
			}
		}
		if (is_prime) {
			primes++;
			*primes = current;
			size++;
		}
	}

	return size;
}
