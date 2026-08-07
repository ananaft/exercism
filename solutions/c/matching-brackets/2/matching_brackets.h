#ifndef MATCHING_BRACKETS_H
#define MATCHING_BRACKETS_H

#include <stdbool.h>
#include <string.h>

#define IS_OPEN_BRACKET(x) ((x) == '(' || (x) == '[' || (x) == '{')
#define IS_CLOSING_BRACKET(x) ((x) == ')' || (x) == ']' || (x) == '}')

bool is_paired(const char *input);
char closing_match(const char bracket);

#endif
