#include "spiral_matrix.h"

#include <stdio.h>

spiral_matrix_t *spiral_matrix_create(int size) {
	spiral_matrix_t *spiral_matrix = malloc(sizeof(spiral_matrix_t));
	if (spiral_matrix == NULL)
		return NULL;
	spiral_matrix->size = size;
	if (size < 1) {
		spiral_matrix->matrix = NULL;
	} else {
		spiral_matrix->matrix = malloc(size * sizeof(int *));
		for (int i = 0; i < size; i++) {
			spiral_matrix->matrix[i] = calloc(size, sizeof(int));
		}
	}
	
	direction_t direction = {
		.idx = 0, .row_change = {0, 1, 0, -1}, .col_change = {1, 0, -1 , 0}
	};

	for (int i = 0, r = 0, c = 0; i < size * size; i++) {
		spiral_matrix->matrix[r][c] = i + 1;
		r += direction.row_change[direction.idx];
		c += direction.col_change[direction.idx];
		if (
				r >= 0 && r < size &&
				c >= 0 && c < size &&
				spiral_matrix->matrix[r][c] == 0
		) {
			continue;
		} else {
			r -= direction.row_change[direction.idx];
			c -= direction.col_change[direction.idx];
			direction.idx = (direction.idx + 1) % 4;
			r += direction.row_change[direction.idx];
			c += direction.col_change[direction.idx];
		}
	}

	return spiral_matrix;
}

void spiral_matrix_destroy(spiral_matrix_t *spiral_matrix) {
	if (spiral_matrix == NULL) return;

	for (int i = 0; i < spiral_matrix->size; i++) {
		free(spiral_matrix->matrix[i]);
	}
	free(spiral_matrix->matrix);
	free(spiral_matrix);
}
