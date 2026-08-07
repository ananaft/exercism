#ifndef MATCHING_BRACKETS_H
#define MATCHING_BRACKETS_H

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

bool is_paired(const char *input);
const char *find_match(const char *current, const char *matches[], size_t size);
bool is_in_matches(const char *bracket, const char *matches[], size_t size);
char closing_match(const char bracket);
bool validate(const char *input, const char *matches[], size_t size);

#endif
