#include "grade_school.h"

void init_roster(roster_t *roster)
{
	roster->count = 0;
}

bool is_duplicate_name(roster_t *roster, const char *name)
{
	for (size_t i = 0; i < roster->count; i++) {
		if (strcmp(roster->students[i].name, name) == 0)
			return true;
	}
	return false;
}

uint8_t compare_students(roster_t *roster, student_t new_student)
{
	for (size_t i = 0; i < roster->count; i++) {
		if (new_student.grade < roster->students[i].grade)
			return i;
		if (new_student.grade == roster->students[i].grade) {
			int cmp = strcmp(new_student.name, roster->students[i].name);
			if (cmp < 0)
				return i;
		}
	}
	return roster->count;
}

uint8_t add_student(roster_t *roster, const char *student, uint8_t grade)
{
	if (is_duplicate_name(roster, student))
		return 0;
	student_t new_student = { .grade = grade };
	strncpy(new_student.name, student, MAX_NAME_LENGTH -1);
	new_student.name[MAX_NAME_LENGTH - 1] = '\0';
	uint8_t position = compare_students(roster, new_student);

	if (position >= MAX_STUDENTS)
		return 0;
	memmove(&roster->students[position + 1], &roster->students[position],
			(roster->count - position) * sizeof(student_t));
	roster->students[position] = new_student;
	roster->count++;

	return roster->count;
}

roster_t get_grade(roster_t *roster, uint8_t grade)
{
	roster_t result_roster;
	init_roster(&result_roster);

	for (size_t i = 0; i < roster->count; i++) {
		if (roster->students[i].grade == grade) {
			result_roster.students[result_roster.count] = roster->students[i];
			result_roster.count++;
		}
	}

	return result_roster;
}
