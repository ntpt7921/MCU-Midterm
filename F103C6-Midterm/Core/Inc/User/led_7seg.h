/*
 * led_7seg.h
 *
 *  Created on: Oct 26, 2022
 *      Author: ntpt
 */

#ifndef INC_LED_7SEG_H_
#define INC_LED_7SEG_H_

#include "main.h"
#include "User/gpio_parallel.h"

/**
 * NOTE:
 * We assume that all the 7 seg led pattern will be controlled from a fix set of pin
 * and that those pin is in the same gpio port
 */
extern const uint16_t SEG7_PATTERN_0;
extern const uint16_t SEG7_PATTERN_1;
extern const uint16_t SEG7_PATTERN_2;
extern const uint16_t SEG7_PATTERN_3;
extern const uint16_t SEG7_PATTERN_4;
extern const uint16_t SEG7_PATTERN_5;
extern const uint16_t SEG7_PATTERN_6;
extern const uint16_t SEG7_PATTERN_7;
extern const uint16_t SEG7_PATTERN_8;
extern const uint16_t SEG7_PATTERN_9;
// assume all seg pattern line is in the same port
extern GPIO_TypeDef *const COMMON_SEG7_PATTERN_PORT;
extern const uint16_t SEG7_PATTERN_LIST[10];


/**
 * NOTE:
 * We will not use this type, since there is only one 7seg led, changing the pattern
 * directly also work
 */
typedef struct
{
	const uint16_t CONTROL_PIN;
	GPIO_TypeDef *const CONTROL_PORT;

	uint8_t digit_value;
} Led_7seg_t;

void led_7seg_change_pattern(uint8_t num);

#endif /* INC_LED_7SEG_H_ */
