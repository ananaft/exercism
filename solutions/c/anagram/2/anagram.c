#include "anagram.h"

void find_anagrams(const char *subject, struct candidates *candidates)
{
	size_t size = strlen(subject);
	char formatted_subject[size+1];
	char lowercase_subject[size+1];
	format_word(subject, formatted_subject, lowercase_subject,
			size, compare_letters);

	for (size_t i = 0; i < candidates->count; i++) {
		const char *word = candidates->candidate[i].word;
		size = strlen(word);
		char formatted_word[size+1];
		char lowercase_word[size+1];
		format_word(word, formatted_word, lowercase_word,
				size, compare_letters);

		if (strcmp(lowercase_subject, lowercase_word) == 0)
			candidates->candidate[i].is_anagram = NOT_ANAGRAM;
		else if (strcmp(formatted_subject, formatted_word) == 0)
			candidates->candidate[i].is_anagram = IS_ANAGRAM;
		else
			candidates->candidate[i].is_anagram = NOT_ANAGRAM;
	}

	return;
}

void format_word(const char *original_word, char *formatted_word,
		char *lowercase_word, size_t size,
		int (*compare)(const void *, const void *))
{
	strcpy(formatted_word, original_word);
	for (size_t i = 0; i < size; i++) {
		formatted_word[i] = tolower(formatted_word[i]);
	}
	strcpy(lowercase_word, formatted_word);
	qsort(formatted_word, size, sizeof(char), compare);

	return;
}

int compare_letters(const void *p, const void *q)
{
	return *(const char *) p - *(const char *) q;
}
