#include "isogram.h"

bool is_isogram(const char phrase[])
{
	if (phrase == NULL) return false;
	if (*phrase == '\0') return true;
	const char *current = phrase;

	for (; *current != '\0'; current++) {
		if (isalpha((unsigned char) *current)) {
			for (phrase = current + 1; *phrase != '\0'; phrase++) {
				if (tolower((unsigned char) *current) == tolower((unsigned char) *phrase)) {
					return false;
				}
			}
		}
	}
	return true;
}
