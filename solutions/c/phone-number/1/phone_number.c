#include "phone_number.h"

char *clean(const char *input)
{
	char *output = malloc(CLEAN_LEN+1);

	uint8_t counter = 0;
	for (; *input != '\0'; input++) {
		if (*input >= '0' && *input <= '9') {
			if (counter >= CLEAN_LEN) {
				free(output);
				output = NULL;
				return output;
			} else {
				output[counter] = *input;
				counter++;
			}
		}
	}
	output[counter] = '\0';

	return output;
}

uint8_t validate(const char *input)
{
	if (input == NULL)
		return 0;
	if (strlen(input) == OUTPUT_LEN &&
			input[0] >= '2' &&
			input[3] >= '2') {
		return 1;
	}
	if (strlen(input) == CLEAN_LEN &&
			input[0] == '1' &&
			input[1] >= '2'&&
			input[4] >= '2') {
		return 2;
	}
	return 0;
}

char *phone_number_clean(const char *input) {
	char *output = malloc(OUTPUT_LEN+1);
	strcpy(output, "0000000000");
	char *cleaned_input = clean(input);

	if (validate(cleaned_input) == 1) {
		strncpy(output, cleaned_input, OUTPUT_LEN);
	} else if (validate(cleaned_input) == 2) {
		strncpy(output, &cleaned_input[1], OUTPUT_LEN);
	}

	free(cleaned_input);
	cleaned_input = NULL;

	return output;
}
