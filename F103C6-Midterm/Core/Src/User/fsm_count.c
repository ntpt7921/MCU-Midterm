/*
 * fsm_traffic_light.c
 *
 *  Created on: Nov 1, 2022
 *      Author: ntpt
 */

#include "User/global_object.h"
#include "User/fsm_count.h"
#include "User/led_7seg.h"

FSM_state_t FSM_count_get_next_state(FSM_state_t current_state)
{
	FSM_state_t next_state = current_state;

	switch (current_state)
	{
	case STATE_0:
        if (condition_increment_count())
        {
            next_state = STATE_1;
        }
        else if (condition_decrement_count())
        {
            next_state = STATE_9;
        }
		break;
	case STATE_1:
        if (condition_back_to_reset())
        {
            next_state = STATE_0;
        }
        else if (condition_increment_count())
        {
            next_state = STATE_2;
        }
        else if (condition_decrement_count_auto())
        {
            next_state = STATE_0;
        }
		break;
	case STATE_2:
        if (condition_back_to_reset())
        {
            next_state = STATE_0;
        }
        else if (condition_increment_count())
        {
            next_state = STATE_3;
        }
        else if (condition_decrement_count_auto())
        {
            next_state = STATE_1;
        }
		break;
	case STATE_3:
        if (condition_back_to_reset())
        {
            next_state = STATE_0;
        }
        else if (condition_increment_count())
        {
            next_state = STATE_4;
        }
        else if (condition_decrement_count_auto())
        {
            next_state = STATE_2;
        }
		break;
	case STATE_4:
        if (condition_back_to_reset())
        {
            next_state = STATE_0;
        }
        else if (condition_increment_count())
        {
            next_state = STATE_5;
        }
        else if (condition_decrement_count_auto())
        {
            next_state = STATE_3;
        }
		break;
	case STATE_5:
        if (condition_back_to_reset())
        {
            next_state = STATE_0;
        }
        else if (condition_increment_count())
        {
            next_state = STATE_6;
        }
        else if (condition_decrement_count_auto())
        {
            next_state = STATE_4;
        }
		break;
	case STATE_6:
        if (condition_back_to_reset())
        {
            next_state = STATE_0;
        }
        else if (condition_increment_count())
        {
            next_state = STATE_7;
        }
        else if (condition_decrement_count_auto())
        {
            next_state = STATE_5;
        }
		break;
	case STATE_7:
        if (condition_back_to_reset())
        {
            next_state = STATE_0;
        }
        else if (condition_increment_count())
        {
            next_state = STATE_8;
        }
        else if (condition_decrement_count_auto())
        {
            next_state = STATE_6;
        }
		break;
	case STATE_8:
        if (condition_back_to_reset())
        {
            next_state = STATE_0;
        }
        else if (condition_increment_count())
        {
            next_state = STATE_9;
        }
        else if (condition_decrement_count_auto())
        {
            next_state = STATE_7;
        }
		break;
	case STATE_9:
        if (condition_back_to_reset())
        {
            next_state = STATE_0;
        }
        else if (condition_increment_count())
        {
            next_state = STATE_0;
        }
        else if (condition_decrement_count_auto())
        {
            next_state = STATE_8;
        }
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
        current_count = 0;
		break;
	case STATE_1:
        current_count = 1;
		break;
	case STATE_2:
        current_count = 2;
		break;
	case STATE_3:
        current_count = 3;
		break;
	case STATE_4:
        current_count = 4;
		break;
	case STATE_5:
        current_count = 5;
		break;
	case STATE_6:
        current_count = 6;
		break;
	case STATE_7:
        current_count = 7;
		break;
	case STATE_8:
        current_count = 8;
		break;
	case STATE_9:
        current_count = 9;
		break;

	default:
		// do nothing, the next_state is invalid
		break;
	}
}

void FSM_count_do_action_within_state(FSM_t *fsm)
{
	led_7seg_change_pattern(current_count);
}

// state transition condition function
uint8_t condition_back_to_reset()
{
    if (button_is_pressed_activated(&button_reset)
        || button_is_hold_activated(&button_reset))
    {
        software_timer_set_duration_ms(&timer_10s, NO_ACTION_AUTO_DECREMENT_DELAY_MS);
        button_clear_activation(&button_reset);
        return 1;
    }
    else
    {
        return 0;
    }
    return 1; // should not reach this
}

uint8_t condition_increment_count()
{
    if (button_is_pressed_activated(&button_inc)
        || button_is_hold_activated(&button_inc))
    {
        software_timer_set_duration_ms(&timer_10s, NO_ACTION_AUTO_DECREMENT_DELAY_MS);
        button_clear_activation(&button_inc);
        return 1;
    }
    else
    {
        return 0;
    }
    return 1; // should not reach this
}

uint8_t condition_decrement_count_auto()
{
    if (button_is_pressed_activated(&button_dec)
        || button_is_hold_activated(&button_dec)
        || software_timer_is_set(&timer_10s))
    {
        software_timer_set_duration_ms(&timer_10s, NO_ACTION_AUTO_DECREMENT_DELAY_MS);
        button_clear_activation(&button_dec);
        return 1;
    }
    else
    {
        return 0;
    }
    return 1; // should not reach this
}

uint8_t condition_decrement_count()
{
    if (button_is_pressed_activated(&button_dec)
        || button_is_hold_activated(&button_dec))
    {
        software_timer_set_duration_ms(&timer_10s, NO_ACTION_AUTO_DECREMENT_DELAY_MS);
        button_clear_activation(&button_dec);
        return 1;
    }
    else
    {
        return 0;
    }
    return 1; // should not reach this
}
