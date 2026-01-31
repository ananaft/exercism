#include "binary_search.h"
#include <stdio.h>

const int *binary_search(int value, const int *arr, size_t length)
{
	if (arr == NULL || length == 0) return NULL;

	size_t mid = length / 2;

	if (arr[mid] == value) {
		return &arr[mid];
	} else if (arr[mid] < value) {
		return binary_search(value, arr + mid + 1, length - mid -1);
	} else {
		return binary_search(value, arr, mid);
	}
}
