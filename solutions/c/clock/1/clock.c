#include "clock.h"

clock_t clock_create(int hour, int minute)
{
	clock_t clock;
	int actual_hour = (hour + minute / 60) % 24;
	int actual_minute = minute % 60;
	if (actual_minute < 0) {
		actual_hour -= 1;
		actual_minute += 60;
	}
	if (actual_hour < 0) {
		actual_hour += 24;
	}

	snprintf(clock.text, MAX_STR_LEN, "%c%c:%c%c",
			'0' + actual_hour / 10, '0' + actual_hour % 10,
			'0' + actual_minute / 10, '0' + actual_minute % 10);
	return clock;
}

clock_t clock_add(clock_t clock, int minute_add)
{
	int new_hour;
	int new_minute;

	sscanf(clock.text, "%02d:%02d", &new_hour, &new_minute);
	new_minute += minute_add;
	new_hour = (new_hour + new_minute / 60) % 24;
	new_minute %= 60;

	snprintf(clock.text, MAX_STR_LEN, "%c%c:%c%c",
			'0' + new_hour / 10, '0' + new_hour % 10,
			'0' + new_minute / 10, '0' + new_minute % 10);
	return clock;
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
	int new_hour;
	int new_minute;

	sscanf(clock.text, "%02d:%02d", &new_hour, &new_minute);
	printf("Clock minutes: %d", new_minute);
	printf("Minute subtract: %d", minute_subtract);
	new_minute -= minute_subtract;
	if (new_minute < 0) {
		new_hour += new_minute / 60;
		new_minute %= 60;
		if (new_minute < 0) {
			new_minute += 60;
			new_hour -= 1;
		}
		if (new_hour < 0) {
			new_hour = new_hour % 24 ? new_hour + 24 : 0;
		}
	}

	snprintf(clock.text, MAX_STR_LEN, "%c%c:%c%c",
			'0' + new_hour / 10, '0' + new_hour % 10,
			'0' + new_minute / 10, '0' + new_minute % 10);
	return clock;
}

bool clock_is_equal(clock_t a, clock_t b)
{
	int a_hour;
	int a_minute;
	int b_hour;
	int b_minute;

	sscanf(a.text, "%02d:%02d", &a_hour, &a_minute);
	sscanf(b.text, "%02d:%02d", &b_hour, &b_minute);

	return a_hour == b_hour && a_minute == b_minute;
}
