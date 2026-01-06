#include <stdlib.h>
#include <string.h>
#include "rna_transcription.h"

char *to_rna(const char *dna)
{
	char *rna = malloc(strlen(dna) + 1);
	const char *p1 = dna;
	char *p2 = rna;

	for (; *p1 != '\0'; p1++, p2++) {
		switch (*p1) {
			case 'G': *p2 = 'C'; break;
			case 'C': *p2 = 'G'; break;
			case 'T': *p2 = 'A'; break;
			case 'A': *p2 = 'U'; break;
			default: *p2 = '\0'; break;
		}
	}

	*p2 = '\0';

	return rna;
}
