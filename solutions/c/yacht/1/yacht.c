#include "yacht.h"

int score(dice_t dice, category_t category)
{
	int points = 0;
	int n_of_face[6] = { 0 };

	for (int i = 0; i < 5; i++) {
		n_of_face[dice.faces[i] - 1]++;
	}

	if (category >= 0 && category <= 5) {
		points = n_of_face[category] * (category + 1);
	}
	switch (category) {
		case FULL_HOUSE: {
							 int has_3 = 0;
							 int has_2 = 0;
							 for (int i = 0; i < 6; i++) {
								 if (n_of_face[i] == 3)
									 has_3 = i + 1;
								 if (n_of_face[i] == 2)
									 has_2 = i + 1;
							 }
							 if (has_3 && has_2) {
								 if (has_3 > has_2)
									 points = 16;
								 if (has_3 < has_2)
									 points = 19;
							 }
							 break;
						 }
		case FOUR_OF_A_KIND: {
								 int has_4 = 0;
								 for (int i = 0; i < 6; i++) {
									 if (n_of_face[i] >= 4)
										 has_4 = i + 1;
								 }
								 if (has_4)
									 points = has_4 * 4;
								 break;
							 }
		case LITTLE_STRAIGHT: {
								  int consecutive = 0;
								  for (int i = 0; i < 5; i++) {
									  if (n_of_face[i] >= 1) {
										  consecutive++;
									  } else {
										  consecutive = 0;
									  }
								  }
								  if (consecutive == 5)
									  points = 30;
								  break;
							  }
		case BIG_STRAIGHT: {
							   int consecutive = 0;
							   for (int i = 1; i < 6; i++) {
								   if (n_of_face[i] == 1) {
									   consecutive++;
								   } else {
									   consecutive = 0;
								   }
							   }
							   if (consecutive == 5)
								   points = 30;
							   break;
						   }
		case CHOICE: {
						 for (int i = 0; i < 6; i++) {
							 points += n_of_face[i] * (i + 1);
						 }
						 break;
					 }
		case YACHT: {
						int has_5 = 0;
						for (int i = 0; i < 5; i++) {
							if (n_of_face[i] == 5)
								has_5 = i + 1;
						}
						if (has_5)
							points = 50;
						break;
					}
		default:
			return points;
	}

	return points;
}
