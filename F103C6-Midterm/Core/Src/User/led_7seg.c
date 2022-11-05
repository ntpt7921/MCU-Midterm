/*
 * led_7seg.c
 *
 *  Created on: Oct 26, 2022
 *      Author: ntpt
 */

#include "User/led_7seg.h"

const uint16_t SEG7_PATTERN_0 = SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin
		| SEG4_Pin | SEG5_Pin;
const uint16_t SEG7_PATTERN_1 = SEG1_Pin | SEG2_Pin;
const uint16_t SEG7_PATTERN_2 = SEG0_Pin | SEG1_Pin | SEG3_Pin | SEG4_Pin
		| SEG6_Pin;
const uint16_t SEG7_PATTERN_3 = SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin
		| SEG6_Pin;
const uint16_t SEG7_PATTERN_4 = SEG1_Pin | SEG2_Pin | SEG5_Pin | SEG6_Pin;
const uint16_t SEG7_PATTERN_5 = SEG0_Pin | SEG2_Pin | SEG3_Pin | SEG5_Pin
		| SEG6_Pin;
const uint16_t SEG7_PATTERN_6 = SEG0_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin
		| SEG5_Pin | SEG6_Pin;
const uint16_t SEG7_PATTERN_7 = SEG0_Pin | SEG1_Pin | SEG2_Pin;
const uint16_t SEG7_PATTERN_8 = SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin
		| SEG4_Pin | SEG5_Pin | SEG6_Pin;
const uint16_t SEG7_PATTERN_9 = SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin
		| SEG5_Pin | SEG6_Pin;

GPIO_TypeDef *const COMMON_SEG7_PATTERN_PORT = SEG0_GPIO_Port;

const uint16_t SEG7_PATTERN_LIST[] =
{ SEG7_PATTERN_0, SEG7_PATTERN_1, SEG7_PATTERN_2, SEG7_PATTERN_3,
		SEG7_PATTERN_4, SEG7_PATTERN_5, SEG7_PATTERN_6, SEG7_PATTERN_7,
		SEG7_PATTERN_8, SEG7_PATTERN_9, };

void led_7seg_change_pattern(uint8_t num)
{
	// SEG7_PATTERN_8 will be used as a mask since it have all pin or'ed together
	gpio_parallel_write(COMMON_SEG7_PATTERN_PORT, SEG7_PATTERN_8,
			~SEG7_PATTERN_LIST[num]);
}
