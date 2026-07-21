#include "acronym.h"

char *abbreviate(const char *phrase)
{
	if (phrase == NULL || strlen(phrase) == 0)
		return NULL;

	char *abbreviation = malloc(strlen(phrase) + 1);
	char *modified_phrase = malloc(strlen(phrase) + 1);
	if (modified_phrase == NULL)
		return NULL;
	char *p = modified_phrase;

	while(*phrase) {
		*p = (*phrase == '-') ? ' ' : *phrase;
		phrase++;
		p++;
	}
	*p = '\0';

	size_t char_count = 0;
	char *token = strtok(modified_phrase, " \t");
	while(token) {
		while (*token && !isalpha(*token))
			token++;
		if (*token) {
			char first_char = *token;
			abbreviation[char_count] = toupper(first_char);
			char_count++;
		}
		token = strtok(NULL, " \t");
	}
	abbreviation = realloc(abbreviation, char_count + 1);
	abbreviation[char_count] = '\0';

	return abbreviation;
}
