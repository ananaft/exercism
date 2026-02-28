#include "scrabble_score.h"

unsigned int values[ALPHABET_SIZE] = {
	1, 3, 3, 2, 1, 4, 2, 4, 1, 8,
	5, 1, 3, 1, 1, 3, 10, 1, 1, 1,
	1, 4, 4, 8, 4, 10
};

unsigned int score(const char *word)
{
	unsigned int points = 0;

	if (word == NULL)
		return 0;

	for (; *word != '\0' ; word++) {
		points += values[tolower(*word) - 'a'];
	}

	return points;
}
