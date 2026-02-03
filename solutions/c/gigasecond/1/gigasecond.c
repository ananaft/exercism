#include "gigasecond.h"
#include <stdio.h>

void gigasecond(time_t input, char *output, size_t size)
{
	input += GIGASECOND;
	struct tm *utc_time = gmtime(&input);
	strftime(output, size, "%Y-%m-%d %T", utc_time);
}
