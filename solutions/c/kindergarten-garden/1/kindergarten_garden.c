#include "kindergarten_garden.h"

static const name_map_t name_map[] = {
	{"Alice", ALICE},
	{"Bob", BOB},
	{"Charlie", CHARLIE},
	{"David", DAVID},
	{"Eve", EVE},
	{"Fred", FRED},
	{"Ginny", GINNY},
	{"Harriet", HARRIET},
	{"Ileana", ILEANA},
	{"Joseph", JOSEPH},
	{"Kincaid", KINCAID},
	{"Larry", LARRY}
};

name_id get_name_id(const char *name, const name_map_t *map, size_t map_len)
{
	for (size_t i = 0; i < map_len; i++) {
		if (strcmp(name, map[i].name) == 0)
			return map[i].id;
	}
	return UNKNOWN;
}

plant_t get_plant(const char plant)
{
	switch (plant) {
		case 'C':
			return CLOVER;
			break;
		case 'G':
			return GRASS;
			break;
		case 'R':
			return RADISHES;
			break;
		case 'V':
			return VIOLETS;
			break;
		default:
			return -1;
			break;
	}
}

plants_t plants(const char *diagram, const char *student)
{
	plants_t plants;
	name_id id = get_name_id(student, name_map,
			sizeof(name_map) / sizeof(name_map[0]));
	const char *newline = strchr(diagram, '\n');

	plants.plants[0] = get_plant(diagram[id * 2]);
	plants.plants[1] = get_plant(diagram[id * 2 + 1]);
	plants.plants[2] = get_plant(newline[id * 2 + 1]);
	plants.plants[3] = get_plant(newline[id * 2 + 2]);

	return plants;
}
