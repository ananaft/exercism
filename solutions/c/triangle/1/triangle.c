#include "triangle.h"

bool is_triangle(triangle_t sides)
{
	if (sides.a + sides.b + sides.c == 0.0) return false;

	if (sides.a + sides.b > sides.c &&
		sides.a + sides.c > sides.b &&
		sides.b + sides.c > sides.a)
	return true;

	return false;
}

bool is_equilateral(triangle_t sides)
{
	if (!is_triangle(sides)) return false;
	if (sides.a - sides.b == 0.0 && sides.a - sides.c == 0.0) {
		return true;
	} else {
		return false;
	}
}

bool is_isosceles(triangle_t sides)
{
	if (!is_triangle(sides)) return false;
	if (sides.a - sides.b == 0.0 || sides.a - sides.c == 0.0 || sides.b - sides.c == 0.0) {
		return true;
	} else {
		return false;
	}
}

bool is_scalene(triangle_t sides)
{
	if (!is_triangle(sides)) return false;
	if (sides.a - sides.b != 0.0 && sides.a - sides.c != 0.0 && sides.b - sides.c != 0.0) {
		return true;
	} else {
		return false;
	}
}
