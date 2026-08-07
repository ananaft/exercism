#include "matching_brackets.h"

bool is_paired(const char *input)
{
	size_t length = strlen(input);
	if (length == 0)
		return true;

	const char *current = input;
	const char **matches = calloc(length, sizeof(char *));
	const char *match = NULL;
	size_t mcount = 0;

	while (*current) {
		switch (*current) {
			case '(': case '[': case '{':
				match = find_match(current, matches, length);
				if (match == NULL)
					return false;
				matches[mcount++] = current;
				matches[mcount++] = match;
				break;
			case ')': case ']': case '}':
				if (!is_in_matches(current, matches, length)) {
					return false;
				}
				break;
		}
		current++;
	}
	return validate(input, matches, length);
}

const char *find_match(const char *current, const char *matches[], size_t size)
{
	const char *search = current + 1;
	size_t skip = 0;

	while (*search != closing_match(*current) ||
			is_in_matches(search, matches, size) ||
			skip > 0) {
		if (*search == *current)
			skip++;
		if (*search == closing_match(*current))
			skip--;
		if (*search == '\0') {
			return NULL;
		}
		search++;
	}

	return search;
}

bool is_in_matches(const char *bracket, const char *matches[], size_t size)
{
	for (size_t i = 0; i < size; i++) {
		if (bracket == matches[i])
			return true;
	}

	return false;
}

char closing_match(const char bracket)
{
	switch (bracket) {
		case '(':
			return ')';
		case '[':
			return ']';
		case '{':
			return '}';
		default:
			return '\0';
	}
}

bool validate(const char *input, const char *matches[], size_t size)
{
	if (size < 3)
		return true;

	for (size_t i = 0; i < size; i += 2) {
		for (size_t j = i + 2; j < size; j += 2) {
			if (matches[i] - input < matches[j] - input &&
			 matches[i+1] - input < matches[j+1] - input &&
			 matches[i+1] - input > matches[j] - input) {
				return false;
			}
		}
	}
	return true;
}
