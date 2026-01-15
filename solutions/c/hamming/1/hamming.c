#include "hamming.h"

int compute(const char *lhs, const char *rhs)
{
	int diffs = 0;

	if (strlen(lhs) != strlen(rhs)) return -1;

	for (; *lhs && *rhs; lhs++, rhs++) {
		if (*lhs != *rhs) diffs++;
	}

	return diffs;
}
