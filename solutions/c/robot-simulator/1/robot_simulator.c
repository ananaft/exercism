#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
	robot_position_t position = {.x = x, .y = y};
	robot_status_t robot = {.direction = direction, .position = position};

	return robot;
}

void robot_move(robot_status_t *robot, const char *commands)
{
	if (robot == NULL || commands == NULL) return;

	for (; *commands != '\0'; commands++) {
		switch (*commands) {
			case 'L':	turn_left(robot);
						break;
			case 'R':	turn_right(robot);
						break;
			case 'A': 	advance(robot);
					  	break;
			default:	return;
		}
	}
}

void turn_left(robot_status_t *robot)
{
	switch (robot->direction) {
		case DIRECTION_NORTH:	robot->direction = DIRECTION_WEST;
								break;
		default:				robot->direction -= 1;
								break;
	}
}

void turn_right(robot_status_t *robot)
{
	switch(robot->direction) {
		case DIRECTION_WEST:	robot->direction = DIRECTION_NORTH;
								break;
		default:				robot->direction += 1;
								break;
	}
}

void advance(robot_status_t *robot)
{
	switch(robot->direction) {
		case DIRECTION_NORTH:	robot->position.y += 1;
								break;
		case DIRECTION_EAST:	robot->position.x += 1;
								break;
		case DIRECTION_SOUTH:	robot->position.y -= 1;
								break;
		case DIRECTION_WEST:	robot->position.x -= 1;
								break;
		default:				return;
	}
}
