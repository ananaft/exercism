#include "luhn.h"

bool luhn(const char *num)
{
	int num_length = 0;
	const char *start = num;
	int is_second_digit = 1;
	int digit_sum = 0;

	if (num == NULL) return false;
	for (; *num != '\0'; num++) {
		if (isdigit(*num)) {
			num_length++;
		} else if (isspace(*num)) {
			continue;
		} else {
			return false;
		}
	}
	if (num_length <= 1) return false;

	for (num--; num >= start; num--) {
		int num_as_int = *num - '0';
		if (isdigit(*num)) {
			if (is_second_digit % 2) {
				digit_sum += num_as_int;
			} else {
				digit_sum += num_as_int * 2 > 9 ? num_as_int * 2 - 9 : num_as_int * 2;
			}
			is_second_digit++;
		}
	}
	if (digit_sum % 10) {
		return false;
	} else {
		return true;
	}
}
