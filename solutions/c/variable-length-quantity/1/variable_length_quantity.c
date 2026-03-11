#include "variable_length_quantity.h"

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
	int output_len = 0;

	for (size_t i = 0; i < integers_len; i++) {
		uint8_t bytes_count = 0;
		for (int factor = 4; factor >= 0; factor--) {
			uint8_t encoded_byte = integers[i] >> (factor * 7) & 0x7f;
			if ((encoded_byte && factor) || (bytes_count && factor)) {
				encoded_byte |= 0x80;
				output[output_len] = encoded_byte;
				output_len++;
				bytes_count++;
			} else if (!factor) {
				output[output_len] = encoded_byte;
				output_len++;
			}
		}
	}
	return output_len;
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output)
{
	int output_len = 0;
	uint32_t decoded_int = 0;

	for (size_t i = 0; i < buffer_len; i++) {
		decoded_int = decoded_int | (bytes[i] & 0x7f);
		if (bytes[i] & 0x80) {
			decoded_int <<= 7;
		} else {
			output[output_len] = decoded_int;
			output_len++;
			decoded_int = 0;
		}
	}
	if (buffer_len > 0 && !output_len)
		return -1;
	return output_len;
}
