#include "bob.h"

char *hey_bob(char *greeting)
{
	Phrase phrase_type = {
		.is_question = false, .is_caps = false, .is_silence = true
	};
	size_t phrase_length = strlen(greeting);
	char *answer;
	size_t letters = 0;
	size_t caps_letters = 0;
	char last_letter;

	for (size_t i = 0; i < phrase_length; i++) {
		if (isalpha(greeting[i])) {
			phrase_type.is_silence = false;
			last_letter = greeting[i];
			letters++;
			if (isupper(greeting[i]))
				caps_letters++;
		} else if (isgraph(greeting[i])) {
			phrase_type.is_silence = false;
			last_letter = greeting[i];
		}
	}
	if (letters && letters == caps_letters)
		phrase_type.is_caps = true;
	if (last_letter == '?')
		phrase_type.is_question = true;

	if (phrase_type.is_silence) {
		answer = "Fine. Be that way!";
	} else if (phrase_type.is_caps && phrase_type.is_question) {
		answer = "Calm down, I know what I'm doing!";
	} else if (phrase_type.is_caps) {
		answer = "Whoa, chill out!";
	} else if (phrase_type.is_question) {
		answer = "Sure.";
	} else {
		answer = "Whatever.";
	}

	return answer;
}
