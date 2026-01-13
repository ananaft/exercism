#include "queen_attack.h"

bool position_in_bounds(position_t queen)
{
	return queen.row <= 7 && queen.column <= 7;
}

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
	if (queen_1.row == queen_2.row && queen_1.column == queen_2.column) {
		return INVALID_POSITION;
	}
	if (!position_in_bounds(queen_1) || !position_in_bounds(queen_2)) {
		return INVALID_POSITION;	
	}

	if (queen_1.row == queen_2.row || queen_1.column == queen_2.column) {
		return CAN_ATTACK;
	} else if (queen_1.row + queen_1.column == queen_2.row + queen_2.column) {
		return CAN_ATTACK;
	} else if (queen_1.row - queen_1.column == queen_2.row - queen_2.column) {
		return CAN_ATTACK;
	} else {
		return CAN_NOT_ATTACK;
	}
}
