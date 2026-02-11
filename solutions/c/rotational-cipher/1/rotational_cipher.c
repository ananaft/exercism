#include "rotational_cipher.h"

char *rotate(const char *text, int shift_key)
{
	size_t len = strlen(text) + 1;
	char *rotation = malloc(len);
	if (rotation == NULL) return NULL;
	char *result = rotation;

	for (; *text != '\0'; text++, rotation++) {
		if (*text >= 'A' && *text <= 'Z') {
			if (*text + shift_key > 'Z') {
				*rotation = *text + shift_key - 26;
			} else {
				*rotation = *text + shift_key;
			}
		} else if (*text >= 'a' && *text <= 'z') {
			if (*text + shift_key > 'z') {
				*rotation = *text + shift_key - 26;
			} else {
				*rotation = *text + shift_key;
			}
		} else {
			*rotation = *text;
		}
	}
	*rotation = '\0';

	return result;
}
