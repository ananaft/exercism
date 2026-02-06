#include "allergies.h"

bool is_allergic_to(allergen_t allergy, int score)
{
	return score & 1 << allergy;
}

allergen_list_t get_allergens(int score)
{
	allergen_list_t allergy_list = {.count = 0, .allergens = { false }};

	for (int i = 0; i <= 7; i++) {
		if (score & 1 << i) {
			allergy_list.count++;
			allergy_list.allergens[i] = true;
		}
	}
	return allergy_list;
}
