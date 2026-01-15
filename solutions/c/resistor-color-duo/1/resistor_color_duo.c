#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t colors[]) {
	char result[3]; 

	sprintf(result, "%d%d", colors[0], colors[1]);
	
	return (uint16_t) strtol(result, NULL, 0);
}
