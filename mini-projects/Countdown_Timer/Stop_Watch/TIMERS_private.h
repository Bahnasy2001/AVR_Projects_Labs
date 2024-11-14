/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 11/5/2024       *************************/
/*************************      SWC: TIMERS         *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H


/* Registers Define */
#define TIMERS_u8_TIMSK_REG                  *((volatile u8*)0x59)
#define TIMERS_u8_TIFR_REG                   *((volatile u8*)0x58)
#define TIMERS_u8_TCCR0_REG                  *((volatile u8*)0x53)
#define TIMERS_u8_TCNT0_REG                  *((volatile u8*)0x52)
#define TIMERS_u8_OCR0_REG                   *((volatile u8*)0x5C)



















/* Define Macros For Options for Selecting Mode of Timer0 */
#define TIMERS_u8_TIMER0_NORMAL_MODE            1
#define TIMERS_u8_TIMER0_CTC_MODE               2





/* Define Macros For Options for Selecting Clock Source */
#define TIMERS_u8_TIMER0_NO_SOURCE              1
#define TIMERS_u8_TIMER0_NO_PRESCALER           2
#define TIMERS_u8_TIMER0_PRESCALER_8            3
#define TIMERS_u8_TIMER0_PRESCALER_64           4
#define TIMERS_u8_TIMER0_PRESCALER_256          5
#define TIMERS_u8_TIMER0_PRESCALER_1024         6
#define TIMERS_u8_TIMER0_T0_PIN_FALLING_EDGE    7
#define TIMERS_u8_TIMER0_T0_PIN_RISING_EDGE     8

/* Define Macros For Options for Selecting Compare Match Mode on OC0 ,nonPWM */
#define TIMERS_u8_TIMER0_OC0_DISCONNECTED       1
#define TIMERS_u8_TIMER0_OC0_TOGGLE             2
#define TIMERS_u8_TIMER0_OC0_CLEAR              3
#define TIMERS_u8_TIMER0_OC0_SET                4

#endif