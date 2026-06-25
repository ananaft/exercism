#include "saddle_points.h"

#include <stdio.h>

uint8_t find_row_max(const uint8_t *row, size_t length)
{
	uint8_t result = row[0];

	for (size_t i = 0; i < length; i++) {
		if (row[i] > result)
			result = row[i];
	}

	return result;
}

bool is_col_min(size_t rows, size_t cols, uint8_t matrix[rows][cols],
		size_t index, uint8_t value)
{
	for (size_t i = 0; i < rows; i++) {
		if (matrix[i][index] < value)
			return false;
	}

	return true;
}

saddle_points_t *saddle_points(size_t rows, size_t cols, uint8_t matrix[rows][cols])
{
	saddle_points_t *result = malloc(sizeof(saddle_points_t));
	if (result == NULL)
		return NULL;
	result->count = 0;
	result->points = NULL;

	for (size_t i = 0; i < rows; i++) {
		uint8_t row_max = find_row_max(matrix[i], cols);
		for (size_t j = 0; j < cols; j++) {
			if (matrix[i][j] == row_max) {
				if (is_col_min(rows, cols, matrix, j, matrix[i][j])) {
					result->points = realloc(result->points,
							(result->count + 1) * sizeof(saddle_point_t));
					result->points[result->count].row = i+1;
					result->points[result->count].column = j+1;
					result->count++;
				}
			}
		}
	}

	return result;
}

void free_saddle_points(saddle_points_t *saddle_points)
{
	if (saddle_points == NULL)
		return;

	free(saddle_points->points);
	free(saddle_points);
}
