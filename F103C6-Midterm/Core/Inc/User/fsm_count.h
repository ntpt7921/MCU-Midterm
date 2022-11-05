/*
 * fsm_traffic_light.h
 *
 *  Created on: Nov 1, 2022
 *      Author: ntpt
 */

#ifndef INC_USER_FSM_TRAFFIC_LIGHT_H_
#define INC_USER_FSM_TRAFFIC_LIGHT_H_

#include "main.h"
#include "User/fsm.h"

/**
 * NOTE:
 * In this module we define functions for changing and setting state for the
 * state machine corresponding to our traffic light system
 *
 * Other function that help with controlling peripheral within each state
 *
 * FSM_state_t is declared in fsm_state_list.h
 */

FSM_state_t FSM_count_get_next_state(FSM_state_t current_state);
void FSM_count_set_to_next_state(FSM_t *fsm, FSM_state_t next_state);
void FSM_count_do_action_within_state(FSM_t *fsm);

#endif /* INC_USER_FSM_TRAFFIC_LIGHT_H_ */
