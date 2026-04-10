#include "circular_buffer.h"

circular_buffer_t *new_circular_buffer(size_t capacity)
{
	circular_buffer_t *buffer = malloc(sizeof(circular_buffer_t));
	buffer->capacity = capacity;
	buffer->size = 0;
	buffer->head = 0;
	buffer->tail = 0;
	buffer->values = calloc(capacity ,sizeof(buffer_value_t));

	return buffer;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *value)
{
	if (buffer->size == 0) {
		errno = ENODATA;
		return EXIT_FAILURE;
	}
	*value = buffer->values[buffer->tail];
	buffer->tail++;
	buffer->tail %= buffer->capacity;
	buffer->size--;
	return EXIT_SUCCESS;
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value)
{
	if (buffer->size >= buffer->capacity) {
		errno = ENOBUFS;
		return EXIT_FAILURE;
	}
	buffer->values[buffer->head] = value;
	buffer->head++;
	buffer->head %= buffer->capacity;
	buffer->size++;
	return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value)
{
	if (buffer->size >= buffer->capacity) {
		buffer->values[buffer->tail] = value;
		buffer->tail++;
		buffer->tail %= buffer->capacity;
	} else {
		write(buffer, value);
	}
	return EXIT_SUCCESS;
}

void clear_buffer(circular_buffer_t *buffer)
{
	buffer->size = 0;
	buffer->head = 0;
	buffer->tail = 0;
}

void delete_buffer(circular_buffer_t *buffer)
{
	free(buffer->values);
	free(buffer);
}
