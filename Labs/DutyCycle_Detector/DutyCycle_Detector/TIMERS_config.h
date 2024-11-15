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
	3-TIMERS_u8_TIMER0_PWM_PHASE_CORRECT_MODE
	4-TIMERS_u8_TIMER0_PWM_FAST_PWM_MODE
*/

#define TIMERS_u8_TIMER0_MODE             TIMERS_u8_TIMER0_PWM_FAST_PWM_MODE

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
#define TIMERS_u8_TIMER0_CLOCK_SOURCE     TIMERS_u8_TIMER0_PRESCALER_8

/* Options to Select Cmpare Match Mode,non PWM Mode For Timer 0 */
/*
	1-TIMERS_u8_TIMER0_OC0_DISCONNECTED
	2-TIMERS_u8_TIMER0_OC0_TOGGLE
	3-TIMERS_u8_TIMER0_OC0_CLEAR
	4-TIMERS_u8_TIMER0_OC0_SET
*/

/* Options to Select Cmpare Match Mode,Phase Correct PWM Mode For Timer 0 */
/*
	1-TIMERS_u8_TIMER0_OC0_DISCONNECTED
	2-TIMERS_u8_TIMER0_OC0_TOGGLE
	3-TIMERS_u8_TIMER0_OC0_CLEAR
	4-TIMERS_u8_TIMER0_OC0_SET
	5-TIMERS_u8_TIMER0_OC0_NON_INVERTING    //For PWM Modes
	6-TIMERS_u8_TIMER0_OC0_INVERTING        //For PWM Modes
*/
/*
Phase Correct PWM:
Non Inverting: Clear OC0 on compare match when up-counting. Set OC0 on compare
			   match when downcounting.

Inverting: Set OC0 on compare match when up-counting. Clear OC0 on compare
			   match when downcounting
*/

/*
Fast PWM:
Non Inverting: Clear OC0 on compare match, set OC0 at BOTTOM,
               (non-inverting mode)

Inverting: Set OC0 on compare match, clear OC0 at BOTTOM,
           (inverting mode)
*/

#define TIMERS_u8_TIMER0_COMPARE_MATCH_MODE     TIMERS_u8_TIMER0_OC0_NON_INVERTING


/* Options to Select Preload Value from 0 to 255 */
#define TIMERS_u8_TIMER0_PRELOAD_VALUE            192
/* Options to Select Compare Match Value from 0 to 255 */
#define TIMERS_u8_TIMER0_COMPARE_MATCH_OCR0       64




/* Options to Select Mode For Timer 1 */
/*
	1-TIMERS_u8_TIMER1_NORMAL_MODE
	2-TIMERS_u8_TIMER1_PWM_PHASE_CORRECT_8BIT_MODE
	3-TIMERS_u8_TIMER1_PWM_PHASE_CORRECT_9BIT_MODE 
	4-TIMERS_u8_TIMER1_PWM_PHASE_CORRECT_10BIT_MODE
	5-TIMERS_u8_TIMER1_CTC_OCR1A_MODE
	6-TIMERS_u8_TIMER1_FAST_PWM_8BIT_MODE
	7-TIMERS_u8_TIMER1_FAST_PWM_9BIT_MODE
	8-TIMERS_u8_TIMER1_FAST_PWM_10BIT_MODE
	9-TIMERS_u8_TIMER1_PWM_PHASE_FREQ_CORRECT_ICR1_MODE
	10-TIMERS_u8_TIMER1_PWM_PHASE_FREQ_CORRECT_OCR1A_MODE
	11-TIMERS_u8_TIMER1_PWM_PHASE_CORRECT_ICR1_MODE
	12-TIMERS_u8_TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE
	13-TIMERS_u8_TIMER1_CTC_ICR1_MODE
	14-TIMERS_u8_TIMER1_FAST_PWM_ICR1_MODE
	15-TIMERS_u8_TIMER1_FAST_PWM_OCR1A_MODE
*/
/* Options to Select channel For Timer 1 */
/*
	1-TIMERS_u8_TIMER1_CHANNEL_A_B
	2-TIMERS_u8_TIMER1_CHANNEL_A
	3-TIMERS_u8_TIMER1_CHANNEL_B
*/
#define TIMERS_u8_TIMER1_CHANNEL         TIMERS_u8_TIMER1_CHANNEL_A

#define TIMERS_u8_TIMER1_MODE           TIMERS_u8_TIMER1_NORMAL_MODE

/* Options to Input Capture Edge for Timer 1 */
/*
	1-TIMERS_u8_Timer1_DISCONNECTED
	2-TIMERS_u8_Timer1_FALLING_EDGE
	3-TIMERS_u8_Timer1_RAISING_EDGE

*/
#define TIMERS_u8_TIMER1_ICU_EDGE                TIMERS_u8_Timer1_RAISING_EDGE
/* Options to Select Preload Value from 0 to 65535 */
#define TIMERS_u16_TIMER1_PRELOAD_VALUE            0
/* Options to Select Compare Match Value from 0 to 65535 */
#define TIMERS_u16_TIMER1_COMPARE_MATCH_OCR1A      999
/* Options to Select Compare Match Value from 0 to 65535 */
#define TIMERS_u16_TIMER1_COMPARE_MATCH_OCR1B      99
/* Options to Select Top Value from 0 to 65535 */
#define TIMERS_u16_TIMER1_TOP_VALUE_ICR1           19999
/* Options to Select Cmpare Match Mode,Phase Correct PWM Mode For Timer 1 */
/*
	1-TIMERS_u8_TIMER1_OC1A_DISCONNECTED
	2-TIMERS_u8_TIMER1_OC1A_TOGGLE
	3-TIMERS_u8_TIMER1_OC1A_CLEAR
	4-TIMERS_u8_TIMER1_OC1A_SET
	5-TIMERS_u8_TIMER1_OC1A_NON_INVERTING    //For PWM Modes
	6-TIMERS_u8_TIMER1_OC1A_INVERTING        //For PWM Modes

*/
/*
	1-TIMERS_u8_TIMER1_OC1B_DISCONNECTED
	2-TIMERS_u8_TIMER1_OC1B_TOGGLE
	3-TIMERS_u8_TIMER1_OC1B_CLEAR
	4-TIMERS_u8_TIMER1_OC1B_SET
	5-TIMERS_u8_TIMER1_OC1B_NON_INVERTING    //For PWM Modes
	6-TIMERS_u8_TIMER1_OC1B_INVERTING        //For PWM Modes
*/

/*
Fast PWM:
TIMERS_u8_TIMER1_OC1A/B_TOGGLE:
	WGM13:0 = 15: Toggle OC1A on Compare
	Match, OC1B disconnected (normal port
	operation).
	For all other WGM13:0 settings, normal port
	operation, OC1A/OC1B disconnected.
TIMERS_u8_TIMER1_OC1A/B_NON_INVERTING:
	Clear OC1A/OC1B on compare match, set
	OC1A/OC1B at BOTTOM,
	(non-inverting mode)
TIMERS_u8_TIMER1_OC1A/B_INVERTING:
	Set OC1A/OC1B on compare match, clear
	OC1A/OC1B at BOTTOM,
	(inverting mode)
*/
/*
Phase Correct and Phase and Frequency Correct PWM:
TIMERS_u8_TIMER1_OC1A/B_TOGGLE:
	WGM13:0 = 9 or 14: Toggle OC1A on
	Compare Match, OC1B disconnected (normal
	port operation).
	For all other WGM13:0 settings, normal port
	operation, OC1A/OC1B disconnected.
TIMERS_u8_TIMER1_OC1A/B_NON_INVERTING:
	Clear OC1A/OC1B on compare match when
	up-counting. Set OC1A/OC1B on compare
	match when downcounting
TIMERS_u8_TIMER1_OC1A/B_INVERTING:
	Set OC1A/OC1B on compare match when upcounting.
	Clear OC1A/OC1B on compare
	match when downcounting.
*/

#define TIMERS_u8_TIMER1_COMPARE_MATCH_MODE_A             TIMERS_u8_TIMER1_OC1A_DISCONNECTED

#define TIMERS_u8_TIMER1_COMPARE_MATCH_MODE_B             TIMERS_u8_TIMER1_OC1B_DISCONNECTED

/* Options to Select CLOCK For Timer 1 */
/*
	1-TIMERS_u8_TIMER1_NO_SOURCE
	2-TIMERS_u8_TIMER1_NO_PRESCALER
	3-TIMERS_u8_TIMER1_PRESCALER_8
	4-TIMERS_u8_TIMER1_PRESCALER_64
	5-TIMERS_u8_TIMER1_PRESCALER_256
	6-TIMERS_u8_TIMER1_PRESCALER_1024
	7-TIMERS_u8_TIMER1_T1_PIN_FALLING_EDGE
	8-TIMERS_u8_TIMER1_T1_PIN_RISING_EDGE
*/
#define TIMERS_u8_TIMER1_CLOCK_SOURCE     TIMERS_u8_TIMER1_PRESCALER_8


#endif
