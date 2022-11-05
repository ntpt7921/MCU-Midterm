/*
 * global_object.h
 *
 *  Created on: Nov 1, 2022
 *      Author: ntpt
 */

#ifndef INC_USER_GLOBAL_OBJECT_H_
#define INC_USER_GLOBAL_OBJECT_H_

#include "main.h"
#include "User/button.h"
#include "User/software_timer.h"
#include "User/led_7seg.h"
#include "User/fsm.h"
#include "User/fsm_count.h"

// constant configuration
extern const uint32_t LED_BLINK_PERIOD_MS;
extern const uint32_t BUTTON_LONG_PRESS_DELAY_MS;
extern const uint32_t BUTTON_LONG_PRESS_REACTIVATE_PERIOD_MS;
extern const uint32_t NO_ACTION_AUTO_DECREMENT_DELAY_MS;

extern volatile Software_timer_t timer_10s;
extern volatile Software_timer_t led_blink;

/* there supposed to be a led 7seg object here, but omitted since not needed
 * the pattern can be change directly
 */

extern volatile Button_t button_reset;
extern volatile Button_t button_inc;
extern volatile Button_t button_dec;

extern FSM_t fsm_count;
// state machine internal state
extern uint8_t current_count;

#endif /* INC_USER_GLOBAL_OBJECT_H_ */
