/*
 * fsm_traffic_light.c
 *
 *  Created on: Nov 1, 2022
 *      Author: ntpt
 */

#include "User/global_object.h"

FSM_state_t FSM_count_get_next_state(FSM_state_t current_state)
{
	FSM_state_t next_state = current_state;

	switch (current_state)
	{
	case STATE_0:
		break;
	case STATE_1:
		break;
	case STATE_2:
		break;
	case STATE_3:
		break;
	case STATE_4:
		break;
	case STATE_5:
		break;
	case STATE_6:
		break;
	case STATE_7:
		break;
	case STATE_8:
		break;
	case STATE_9:
		break;

	default:
		next_state = STATE_0;
		break;
	}

	return next_state;
}

void FSM_count_set_to_next_state(FSM_t *fsm, FSM_state_t next_state)
{
	if (fsm->current_state == next_state)
	{
		return;
	}

	fsm->current_state = next_state;

	switch (next_state)
	{
	case STATE_0:
		break;
	case STATE_1:
		break;
	case STATE_2:
		break;
	case STATE_3:
		break;
	case STATE_4:
		break;
	case STATE_5:
		break;
	case STATE_6:
		break;
	case STATE_7:
		break;
	case STATE_8:
		break;
	case STATE_9:
		break;

	default:
		// do nothing, the next_state is invalid
		break;
	}
}

void FSM_count_do_action_within_state(FSM_t *fsm)
{
	switch (fsm->current_state)
	{
	case STATE_0:
		break;
	case STATE_1:
		break;
	case STATE_2:
		break;
	case STATE_3:
		break;
	case STATE_4:
		break;
	case STATE_5:
		break;
	case STATE_6:
		break;
	case STATE_7:
		break;
	case STATE_8:
		break;
	case STATE_9:
		break;

	default:
		// do nothing, current state of fsm is invalid
		break;
	}
}
