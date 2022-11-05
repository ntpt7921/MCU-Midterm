/*
 * software_timer.c
 *
 *  Created on: Oct 24, 2022
 *      Author: ntpt
 */

#include "User/software_timer.h"

// since timer will be update every tick duration, it can only register
// event with the smallest time scale of tick duration (in this case TIMER_TICK_DURATION_MS)

void software_timer_set_duration_ms(volatile Software_timer_t *tm, uint32_t ms)
{
	tm->timer_counter = (ms / TIMER_TICK_DURATION_MS);
	tm->timer_flag = TIMER_FLAG_RESET;
}

void software_timer_update_after_tick(volatile Software_timer_t *tm)
{
	if (tm->timer_counter > 0)
	{
		tm->timer_counter--;
	}

	if (tm->timer_counter == 0)
	{
		tm->timer_flag = TIMER_FLAG_SET;
	}
}

uint8_t software_timer_is_set(volatile Software_timer_t *tm)
{
	return (tm->timer_flag == TIMER_FLAG_SET);
}
