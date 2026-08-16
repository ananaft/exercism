#include "anagram.h"

void find_anagrams(const char *subject, struct candidates *candidates)
{
	char formatted_subject[strlen(subject)+1];
	strcpy(formatted_subject, subject);
	for (size_t i = 0; i < strlen(formatted_subject); i++) {
		formatted_subject[i] = tolower(formatted_subject[i]);
	}
	char lowercase_subject[strlen(formatted_subject)+1];
	strcpy(lowercase_subject, formatted_subject);
	qsort(formatted_subject, strlen(formatted_subject),
			sizeof(char), compare_letters);

	for (size_t i = 0; i < candidates->count; i++) {
		const char *word = candidates->candidate[i].word;
		char formatted_word[strlen(word)+1];
		strcpy(formatted_word, word);
		for (size_t i = 0; i < strlen(formatted_word); i++) {
			formatted_word[i] = tolower(formatted_word[i]);
		}
		char lowercase_word[strlen(formatted_word)+1];
		strcpy(lowercase_word, formatted_word);
		qsort(formatted_word, strlen(formatted_word),
				sizeof(char), compare_letters);
		if (strcmp(lowercase_subject, lowercase_word) == 0)
			candidates->candidate[i].is_anagram = NOT_ANAGRAM;
		else if (strcmp(formatted_subject, formatted_word) == 0)
			candidates->candidate[i].is_anagram = IS_ANAGRAM;
		else
			candidates->candidate[i].is_anagram = NOT_ANAGRAM;
	}

	return;
}

int compare_letters(const void *p, const void *q)
{
	return *(const char *) p - *(const char *) q;
}
