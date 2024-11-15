/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 11/5/2024       *************************/
/*************************      SWC: TIMERS         *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef TIMERS_CONFIG_H
#define TIMERS_CONFIG_H

/* Options to Select Mode For Timer 0 */
/*
	1-TIMERS_u8_TIMER0_NORMAL_MODE
	2-TIMERS_u8_TIMER0_CTC_MODE
*/

#define TIMERS_u8_TIMER0_MODE             TIMERS_u8_TIMER0_NORMAL_MODE

/* Options to Select CLOCK For Timer 0 */
/*
	1-TIMERS_u8_TIMER0_NO_SOURCE
	2-TIMERS_u8_TIMER0_NO_PRESCALER
	3-TIMERS_u8_TIMER0_PRESCALER_8
	4-TIMERS_u8_TIMER0_PRESCALER_64
	5-TIMERS_u8_TIMER0_PRESCALER_256
	6-TIMERS_u8_TIMER0_PRESCALER_1024
	7-TIMERS_u8_TIMER0_T0_PIN_FALLING_EDGE
	8-TIMERS_u8_TIMER0_T0_PIN_RISING_EDGE
*/
#define TIMERS_u8_TIMER0_CLOCK_SOURCE     TIMERS_u8_TIMER0_T0_PIN_RISING_EDGE

/* Options to Select Cmpare Match Mode,non PWM Mode For Timer 0 */
/*
	1-TIMERS_u8_TIMER0_OC0_DISCONNECTED
	2-TIMERS_u8_TIMER0_OC0_TOGGLE
	3-TIMERS_u8_TIMER0_OC0_CLEAR
	4-TIMERS_u8_TIMER0_OC0_SET
*/
#define TIMERS_u8_TIMER0_COMPARE_MATCH_MODE     TIMERS_u8_TIMER0_OC0_DISCONNECTED

/* Options to Select Preload Value from 0 to 255 */
#define TIMER0_u8_TIMER0_PRELOAD_VALUE            0
/* Options to Select Compare Match Value from 0 to 255 */
#define TIMER0_u8_TIMER0_COMPARE_MATCH_OCR0       99

#endif
