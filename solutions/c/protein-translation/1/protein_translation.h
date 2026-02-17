#ifndef PROTEIN_TRANSLATION_H
#define PROTEIN_TRANSLATION_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#define MAX_AMINO_ACIDS 10

typedef enum {
	INVALID = -2,
	STOP = -1,
	Methionine = 0,
	Phenylalanine,
	Leucine,
	Serine,
	Tyrosine,
	Cysteine,
	Tryptophan,
} amino_acid_t;

typedef struct {
   bool valid;
   size_t count;
   amino_acid_t amino_acids[MAX_AMINO_ACIDS];
} protein_t;

amino_acid_t parse_amino_acid(const char *amino_acid);
protein_t protein(const char *const rna);

#endif
