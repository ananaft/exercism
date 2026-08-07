#include "matching_brackets.h"

bool is_paired(const char *input)
{
	if (input == NULL || strlen(input) == 0)
		return true;

	char stack[strlen(input)];
	int idx = 0;

	for (; *input != '\0'; input++) {
		if (IS_OPEN_BRACKET(*input)) {
			stack[idx] = *input;
			idx++;
		} else if (IS_CLOSING_BRACKET(*input)) {
			if (*input == closing_match(stack[idx-1])) {
				stack[idx-1] = '\0';
				idx--;
			} else {
				return false;
			}
		}
	}
	
	if (idx > 0 || stack[idx]) {
		return false;
	} else {
		return true;
	}
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
