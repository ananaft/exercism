#ifndef SCRABBLE_SCORE_H
#define SCRABBLE_SCORE_H

#include <string.h>
#include <ctype.h>
#define VALUES_SIZE 10

unsigned int score_char(const char letter);
unsigned int score(const char *word);

#endif
