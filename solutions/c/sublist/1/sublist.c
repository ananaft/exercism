#include "sublist.h"

comparison_result_t check_lists(int *list_to_compare, int *base_list,
		size_t list_to_compare_element_count, size_t base_list_element_count)
{
	size_t compare_i = 0, base_i = 0, shift_i = 1, equal_elements = 0;


	if (list_to_compare_element_count == base_list_element_count) {
		for (; compare_i < list_to_compare_element_count; compare_i++, base_i++) {
			if (list_to_compare[compare_i] == base_list[base_i])
				equal_elements++;
		}
		if (equal_elements == list_to_compare_element_count)
			return EQUAL;
	} else if (list_to_compare_element_count < base_list_element_count) {
		while (base_i <= base_list_element_count - list_to_compare_element_count) {
			for (; compare_i < list_to_compare_element_count; compare_i++, base_i++) {
				if (list_to_compare[compare_i] == base_list[base_i])
					equal_elements++;
			}
			if (equal_elements == list_to_compare_element_count)
				return SUBLIST;
			compare_i = 0;
			base_i = 0 + shift_i++;
			equal_elements = 0;
		}
	} else {
		while (compare_i <= list_to_compare_element_count - base_list_element_count) {
			for (; base_i < base_list_element_count; base_i++, compare_i++) {
				if (base_list[base_i] == list_to_compare[compare_i])
					equal_elements++;
			}
			if (equal_elements == base_list_element_count)
				return SUPERLIST;
			base_i = 0;
			compare_i = 0 + shift_i++;
			equal_elements = 0;
		}
	}

	return UNEQUAL;
}
