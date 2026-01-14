#include "dnd_character.h"

int ability(void)
{
	srand(time(NULL));

	int rolls[ABILITY_ROLLS] = {
		(rand() % 6) + 1,
		(rand() % 6) + 1,
		(rand() % 6) + 1,
		(rand() % 6) + 1
	};
	int min = rolls[0];
	int sum = 0;

	for (int i = 0; i < ABILITY_ROLLS; i++) {
		if (rolls[i] < min) min = rolls[i];
		sum += rolls[i];
	}

	return sum - min;
}

int modifier(int score)
{
	return (int) floor((score - 10.0f) / 2.0f);
}

dnd_character_t make_dnd_character(void)
{
	dnd_character_t character = {
		.strength = ability(),
		.dexterity = ability(),
		.constitution = ability(),
		.intelligence = ability(),
		.wisdom = ability(),
		.charisma = ability(),
		.hitpoints = 10
	};
	character.hitpoints += modifier(character.constitution);

	return character;
}
