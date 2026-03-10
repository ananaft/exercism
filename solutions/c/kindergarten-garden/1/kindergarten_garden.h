#ifndef KINDERGARTEN_GARDEN_H
#define KINDERGARTEN_GARDEN_H

#include <string.h>

typedef enum {
	CLOVER = 0, GRASS = 1,
	RADISHES = 2, VIOLETS = 3, 
} plant_t;

typedef enum {
	UNKNOWN = -1, ALICE = 0, BOB, CHARLIE, DAVID, EVE,
	FRED, GINNY, HARRIET, ILEANA, JOSEPH, KINCAID, LARRY
} name_id;

typedef struct {
	const char *name;
	name_id id;
} name_map_t;

typedef struct {
   plant_t plants[4];
} plants_t;

name_id get_name_id(const char *name, const name_map_t *map, size_t map_len);
plant_t get_plant(const char plant);
plants_t plants(const char *diagram, const char *student);

#endif
