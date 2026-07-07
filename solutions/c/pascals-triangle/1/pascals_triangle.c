#include "pascals_triangle.h"

void free_triangle(uint8_t **triangle, size_t rows)
{
	if (triangle == NULL)
		return;

	for (size_t i = 0; i < rows; i++) {
		free(triangle[i]);
	}
	free(triangle);

	return;
}

uint8_t **create_triangle(size_t rows)
{
	if (rows == 0) {
		uint8_t **triangle = malloc(sizeof(uint8_t *));
		triangle[0] = malloc(sizeof(uint8_t));
		triangle[0][0] = 0;
		return triangle;
	}

	uint8_t **triangle = malloc(rows * sizeof(uint8_t *));
	for (size_t i = 0; i < rows; i++) {
		triangle[i] = malloc(rows * sizeof(uint8_t));
	}

	size_t row_size = 1;
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < rows; j++) {
			if (j >= row_size) {
				triangle[i][j] = 0;
			} else if (j == 0 || j == row_size -1) {
				triangle[i][j] = 1;
			} else {
				triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
			}
		}
		row_size++;
	}

	return triangle;
}
