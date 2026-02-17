#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE sizeof("A:9999 C:9999 G:9999 T:9999")

char *count(const char *dna_strand);

#endif
