#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	uint8_t row;
	uint8_t column;
} saddle_point_t;

typedef struct {
	size_t count;
	saddle_point_t *points;
} saddle_points_t;

uint8_t find_row_max(const uint8_t *row, size_t length);
bool is_col_min(size_t rows, size_t cols, uint8_t matrix[rows][cols],
		size_t index, uint8_t value);
saddle_points_t *saddle_points(size_t rows, size_t cols, uint8_t matrix[rows][cols]);
void free_saddle_points(saddle_points_t *saddle_points);

#endif
