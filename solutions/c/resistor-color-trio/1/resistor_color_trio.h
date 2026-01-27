#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

typedef enum {
	BLACK = 0,
	BROWN,
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE,
	VIOLET,
	GREY,
	WHITE
} resistor_band_t;

typedef enum {
	OHMS = 0,
	KILOOHMS = 3,
	MEGAOHMS = 6,
	GIGAOHMS = 9
} unit_t;

typedef struct {
	int value;
	unit_t unit;
} resistor_value_t;

int value_to_power(int value, int base, int exp);
resistor_value_t color_code(resistor_band_t *colors);

#endif
