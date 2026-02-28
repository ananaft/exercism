#include "scrabble_score.h"

const char *scrabble_values[VALUES_SIZE] = {
	"aeioulnrst",
	"dg",
	"bcmp",
	"fhvwy",
	"k",
	"",
	"",
	"jx",
	"",
	"qz"
};

unsigned int score_char(const char letter)
{
	for (unsigned int i = 0; i < VALUES_SIZE; i++) {
		for (const char *p = scrabble_values[i]; *p != '\0'; p++) {
			if (tolower(letter) == *p)
				return i + 1;
		}
	}
	return 0;
}

unsigned int score(const char *word)
{
	unsigned int points = 0;

	if (word == NULL)
		return 0;

	for (; *word != '\0' ; word++) {
		points += score_char(*word);
	}

	return points;
}
