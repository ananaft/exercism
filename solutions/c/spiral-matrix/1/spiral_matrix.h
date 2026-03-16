#ifndef SPIRAL_MATRIX_H
#define SPIRAL_MATRIX_H

#include <stdlib.h>

typedef struct {
   int size;
   int **matrix;
} spiral_matrix_t;

typedef struct {
	int idx;
	int row_change[4];
	int col_change[4];
} direction_t;

spiral_matrix_t *spiral_matrix_create(int size);
void spiral_matrix_destroy(spiral_matrix_t *spiral_matrix);

#endif
