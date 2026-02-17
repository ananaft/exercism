#include "protein_translation.h"

amino_acid_t parse_amino_acid(const char *amino_acid)
{
	if (strcmp(amino_acid, "AUG") == 0) return Methionine;
	if (strcmp(amino_acid, "UUU") == 0) return Phenylalanine;
	if (strcmp(amino_acid, "UUC") == 0) return Phenylalanine;
	if (strcmp(amino_acid, "UUA") == 0) return Leucine;
	if (strcmp(amino_acid, "UUG") == 0) return Leucine;
	if (strcmp(amino_acid, "UCU") == 0) return Serine;
	if (strcmp(amino_acid, "UCC") == 0) return Serine;
	if (strcmp(amino_acid, "UCA") == 0) return Serine;
	if (strcmp(amino_acid, "UCG") == 0) return Serine;
	if (strcmp(amino_acid, "UAU") == 0) return Tyrosine;
	if (strcmp(amino_acid, "UAC") == 0) return Tyrosine;
	if (strcmp(amino_acid, "UGU") == 0) return Cysteine;
	if (strcmp(amino_acid, "UGC") == 0) return Cysteine;
	if (strcmp(amino_acid, "UGG") == 0) return Tryptophan;
	if (strcmp(amino_acid, "UAA") == 0) return STOP;
	if (strcmp(amino_acid, "UAG") == 0) return STOP;
	if (strcmp(amino_acid, "UGA") == 0) return STOP;
	return INVALID;
}

protein_t protein(const char *const rna)
{
	const char *p = rna;
	protein_t protein = { .valid = true, .count = 0 };
	char amino[4] = "___";
	unsigned int counter = 0;

	while (*p != '\0') {
		amino[counter % 3] = *p;
		counter++;
		if (counter % 3 == 0) {
			switch (parse_amino_acid(amino)) {
				case Methionine:
					protein.amino_acids[protein.count] = Methionine;
					break;
				case Phenylalanine:
					protein.amino_acids[protein.count] = Phenylalanine;
					break;
				case Leucine:
					protein.amino_acids[protein.count] = Leucine;
					break;
				case Serine:
					protein.amino_acids[protein.count] = Serine;
					break;
				case Tyrosine:
					protein.amino_acids[protein.count] = Tyrosine;
					break;
				case Cysteine:
					protein.amino_acids[protein.count] = Cysteine;
					break;
				case Tryptophan:
					protein.amino_acids[protein.count] = Tryptophan;
					break;
				case STOP:
					return protein;
				case INVALID:
					protein.valid = false;
					return protein;
			}
			protein.count++;
		}
		p++;
	}

	if (strlen(rna) % 3 != 0) {
		protein.valid = false;
		return protein;
	}

	return protein;
}


