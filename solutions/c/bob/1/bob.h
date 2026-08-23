#ifndef BOB_H
#define BOB_H

#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
	bool is_question;
	bool is_caps;
	bool is_silence;
} Phrase;

char *hey_bob(char *greeting);

#endif
