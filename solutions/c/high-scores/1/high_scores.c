#include "high_scores.h"

int32_t latest(const int32_t *scores, size_t scores_len)
{
	return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len)
{
	int32_t max = *scores;
	const int32_t *end = scores + scores_len;

	for (scores++; scores < end; scores++) {
		if (*scores > max) max = *scores;
	}

	return max;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output)
{
	size_t n_of_scores = 3;
	if (scores_len < 3) n_of_scores = scores_len;
	const int32_t *end = scores + scores_len;

	for (; scores < end; scores++) {
		if (*scores > output[0]) {
			output[2] = output[1];
			output[1] = output[0];
			output[0] = *scores;
		} else if (*scores > output[1]) {
			output[2] = output[1];
			output[1] = *scores;
		} else if (*scores > output[2]) {
			output[2] = *scores;
		}
	}

	return n_of_scores;
}
