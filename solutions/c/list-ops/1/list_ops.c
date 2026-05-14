#include "list_ops.h"

list_t *new_list(size_t length, list_element_t elements[])
{
	list_t *list = malloc(sizeof(list_t) + length * sizeof(list_element_t));
	if (list == NULL)
		return NULL;

	list->length = length;
	if (elements != NULL)
		memcpy(list->elements, elements, length * sizeof(list_element_t));

	return list;
}

list_t *append_list(list_t *list1, list_t *list2)
{
	size_t new_length = list1->length + list2->length;
	list_t *result_list = malloc(sizeof(list_t) +
			new_length * sizeof(list_element_t));
	if (result_list == NULL)
		return NULL;

	result_list->length = new_length;
	memcpy(result_list->elements, list1->elements,
			list1->length * sizeof(list_element_t));
	memcpy(result_list->elements + list1->length, list2->elements,
			list2->length * sizeof(list_element_t));

	return result_list;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t))
{
	list_t *filtered_list = malloc(sizeof(list_t) +
			list->length * sizeof(list_element_t));
	if (filtered_list == NULL)
		return NULL;

	filtered_list->length = 0;
	for (size_t i = 0; i < list->length; i++) {
		if (filter(list->elements[i])) {
			filtered_list->elements[filtered_list->length] = list->elements[i];
			filtered_list->length++;
		}
	}

	list_t *shrunk = realloc(filtered_list, sizeof(list_t) +
			filtered_list->length * sizeof(list_element_t));
	if (shrunk != NULL)
		filtered_list = shrunk;

	return filtered_list;
}

size_t length_list(list_t *list) {
	return list->length;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
	list_t *mapped_list = malloc(sizeof(list_t) +
			list->length * sizeof(list_element_t));
	if (mapped_list == NULL)
		return NULL;

	mapped_list->length = list->length;
	if (list->length > 0) {
		for (size_t i = 0; i < list->length; i++) {
			mapped_list->elements[i] = map(list->elements[i]);
		}
	}

	return mapped_list;
}

list_element_t foldl_list(list_t *list, list_element_t initial,
		list_element_t (*foldl)(list_element_t, list_element_t))
{
	if (list->length == 0)
		return initial;

	list_element_t result = initial;
	for (size_t i = 0; i < list->length; i++) {
		result = foldl(list->elements[i], result);
	}

	return result;
}

list_element_t foldr_list(list_t *list, list_element_t initial,
		list_element_t (*foldr)(list_element_t, list_element_t))
{
	if (list->length == 0)
		return initial;

	list_element_t result = initial;
	for (size_t i = list->length; i-- > 0; ) {
		result = foldr(list->elements[i], result);
	}

	return result;
}

list_t *reverse_list(list_t *list)
{
	list_t *reversed_list = malloc(sizeof(list_t) +
			list->length * sizeof(list_element_t));
	reversed_list->length = list->length;

	if (list->length < 2) {
		for (size_t i = 0; i < list->length; i++) {
			reversed_list->elements[i] = list->elements[i];
		}
	} else {
		size_t index = 0;
		for (size_t i = list->length; i-- > 0; ) {
			reversed_list->elements[index] = list->elements[i];
			index++;
		}
	}

	return reversed_list;
}

void delete_list(list_t *list)
{
	free(list);
	return;
}
