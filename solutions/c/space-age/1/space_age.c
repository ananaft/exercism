#include "space_age.h"
#include <math.h>

const double conversions[8] = {
	[MERCURY] = 0.2408467f,
	[VENUS] = 0.61519726f,
	[EARTH] = 1.0f,
	[MARS] = 1.8808158f,
	[JUPITER] = 11.862615f,
	[SATURN] = 29.447498f,
	[URANUS] = 84.016846f,
	[NEPTUNE] = 164.79132f
};

float age(planet_t planet, int64_t seconds)
{
	if (planet > 7 || planet < 0) {
		return -1.0f;
	}

	double minutes = (double) seconds / 60.0f;
	double hours = minutes / 60.0f;
	double days = hours / 24.0f;
	double years = (days / 365.0f) / conversions[planet];

	return (float) round(years * 100.0f) / 100.0f;
}
