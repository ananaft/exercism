#include "pangram.h"

bool is_pangram(const char *sentence)
{
	bool alphabet[26] = { false };

	if (sentence == NULL) return false;
	for (; *sentence != '\0'; sentence++) {
		if (isalpha((unsigned char) *sentence)) {
			alphabet[tolower((unsigned char) *sentence) - 'a'] = true;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == false) return false;
	}

	return true;
}
