#include "rational_numbers.h"

rational_t add(rational_t r1, rational_t r2)
{
	rational_t result;

	result.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
	result.denominator = r1.denominator * r2.denominator;

	result = fix_sign(result);
	result = reduce(result);
	return result;
}

rational_t subtract(rational_t r1, rational_t r2)
{
	rational_t result;

	result.numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
	result.denominator = r1.denominator * r2.denominator;

	result = fix_sign(result);
	result = reduce(result);
	return result;
}

rational_t multiply(rational_t r1, rational_t r2)
{
	rational_t result;

	result.numerator = r1.numerator * r2.numerator;
	result.denominator = r1.denominator * r2.denominator;

	result = fix_sign(result);
	result = reduce(result);
	return result;
}

rational_t divide(rational_t r1, rational_t r2)
{
	rational_t result;

	result.numerator = r1.numerator * r2.denominator;
	result.denominator = r2.numerator * r1.denominator;

	result = fix_sign(result);
	result = reduce(result);
	return result;
}

rational_t absolute(rational_t r)
{
	rational_t result;

	result.numerator = abs(r.numerator);
	result.denominator = abs(r.denominator);

	result = fix_sign(result);
	result = reduce(result);
	return result;
}

rational_t exp_rational(rational_t base, int exp)
{
	rational_t result;

	if (exp < 0) {
		result.numerator = (int) pow(base.denominator, abs(exp));
		result.denominator = (int) pow(base.numerator, abs(exp));
	} else {
		result.numerator = (int) pow(base.numerator, exp);
		result.denominator = (int) pow(base.denominator, exp);
	}

	result = fix_sign(result);
	result = reduce(result);
	return result;
}

float exp_real(int base, rational_t exp)
{
	return powf(powf(base, exp.numerator), 1.0f / exp.denominator);
}

rational_t reduce(rational_t r)
{
	int a = abs(r.numerator);
	int b = abs(r.denominator);
	int new_a = a;
	int new_b = b;

	while (b != 0) {
		new_a = b;
		new_b = a % b;
		a = new_a;
		b = new_b;
	}

	rational_t result;
	result.numerator = r.numerator / a;
	result.denominator = r.denominator / a;
	result = fix_sign(result);

	return result;
}

rational_t fix_sign(rational_t r)
{
	rational_t result = r;
	if (result.numerator < 0 && result.denominator < 0) {
		result.numerator = abs(result.numerator);
		result.denominator = abs(result.denominator);
	} else if (result.denominator < 0) {
		result.numerator = -result.numerator;
		result.denominator = abs(result.denominator);
	}
	return result;
}
