#include "nucleotide_count.h"

char *count(const char *dna_strand)
{
	if (dna_strand == NULL) return NULL;
	unsigned int a_count = 0;
	unsigned int c_count = 0;
	unsigned int g_count = 0;
	unsigned int t_count = 0;
	char *result = malloc(BUFFER_SIZE);

	for (; *dna_strand != '\0'; dna_strand++) {
		if (isspace(*dna_strand)) continue;
		switch (*dna_strand) {
			case 'A':
				a_count++;
				break;
			case 'C':
				c_count++;
				break;
			case 'G':
				g_count++;
				break;
			case 'T':
				t_count++;
				break;
			default:
				free(result);
				result = malloc(1);
				result[0] = '\0';
				return result;
		}
	}
	sprintf(result, "A:%u C:%u G:%u T:%u", a_count, c_count, g_count, t_count);

	return result;
}
