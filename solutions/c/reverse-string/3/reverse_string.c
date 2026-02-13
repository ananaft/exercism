#include "reverse_string.h"

char *reverse(const char *value)
{
	if (value == NULL) return NULL;
	size_t len = strlen(value) + 1;
	char *reverse_str = malloc(len);
	char *result = reverse_str;

	while (*value != '\0') value++;
	value--;
	for (unsigned int c = 0; c < len - 1; c++, value--, reverse_str++) {
		*reverse_str = *value;
	}
	*(++reverse_str) = '\0';

	return result;
}
