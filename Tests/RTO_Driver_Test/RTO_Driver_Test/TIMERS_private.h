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

#define TIMERS_u8_TCCR1A_REG                 *((volatile u8*)0x4F)
#define TIMERS_u8_TCCR1B_REG                 *((volatile u8*)0x4E)
#define TIMERS_u8_TCNT1H_REG                 *((volatile u8*)0x4D)
#define TIMERS_u8_TCNT1L_REG                 *((volatile u8*)0x4C)
#define TIMERS_u16_TCNT1_REG                 *((volatile u16*)0x4C)
#define TIMERS_u8_OCR1AH_REG                 *((volatile u8*)0x4B)
#define TIMERS_u8_OCR1AL_REG                 *((volatile u8*)0x4A)
#define TIMERS_u16_OCR1A_REG                 *((volatile u16*)0x4A)
#define TIMERS_u8_OCR1BH_REG                 *((volatile u8*)0x49)
#define TIMERS_u8_OCR1BL_REG                 *((volatile u8*)0x48)
#define TIMERS_u16_OCR1B_REG                 *((volatile u16*)0x48)
#define TIMERS_u8_ICR1H_REG                  *((volatile u8*)0x47)
#define TIMERS_u8_ICR1L_REG                  *((volatile u8*)0x46)
#define TIMERS_u16_ICR1_REG                  *((volatile u16*)0x46)

#define TIMERS_u8_TCCR2_REG                  *((volatile u8*)0x45)
#define TIMERS_u8_TCNT2_REG                  *((volatile u8*)0x44)
#define TIMERS_u8_OCR2_REG                   *((volatile u8*)0x43)








/****************************Timer 0*********************************/
/* Define Macros For Options for Selecting Mode of Timer0 */
#define TIMERS_u8_TIMER0_NORMAL_MODE                          1
#define TIMERS_u8_TIMER0_CTC_MODE                             2
#define TIMERS_u8_TIMER0_PWM_PHASE_CORRECT_MODE               3
#define TIMERS_u8_TIMER0_PWM_FAST_PWM_MODE                    4



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



/* Define Macros For Options for Selecting Compare Match Mode on OC0 ,PWM */

#define TIMERS_u8_TIMER0_OC0_NON_INVERTING         5
#define TIMERS_u8_TIMER0_OC0_INVERTING             6

/****************************Timer 1*********************************/
/* Define Macros For Options for Selecting Mode of Timer1 */
#define TIMERS_u8_TIMER1_NORMAL_MODE                         1
#define TIMERS_u8_TIMER1_PWM_PHASE_CORRECT_8BIT_MODE         2
#define TIMERS_u8_TIMER1_PWM_PHASE_CORRECT_9BIT_MODE         3
#define TIMERS_u8_TIMER1_PWM_PHASE_CORRECT_10BIT_MODE        4
#define TIMERS_u8_TIMER1_CTC_OCR1A_MODE                      5
#define TIMERS_u8_TIMER1_FAST_PWM_8BIT_MODE                  6
#define TIMERS_u8_TIMER1_FAST_PWM_9BIT_MODE                  7
#define TIMERS_u8_TIMER1_FAST_PWM_10BIT_MODE                 8
#define TIMERS_u8_TIMER1_PWM_PHASE_FREQ_CORRECT_ICR1_MODE    9
#define TIMERS_u8_TIMER1_PWM_PHASE_FREQ_CORRECT_OCR1A_MODE  10
#define TIMERS_u8_TIMER1_PWM_PHASE_CORRECT_ICR1_MODE        11
#define TIMERS_u8_TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE       12
#define TIMERS_u8_TIMER1_CTC_ICR1_MODE                      13
#define TIMERS_u8_TIMER1_FAST_PWM_ICR1_MODE                 14
#define TIMERS_u8_TIMER1_FAST_PWM_OCR1A_MODE                15
#define TIMERS_u8_TIMER1_CTC_OCR1B_MODE                     16





/* Define Macros For Options for Selecting Clock Source */
#define TIMERS_u8_TIMER1_NO_SOURCE              1
#define TIMERS_u8_TIMER1_NO_PRESCALER           2
#define TIMERS_u8_TIMER1_PRESCALER_8            3
#define TIMERS_u8_TIMER1_PRESCALER_64           4
#define TIMERS_u8_TIMER1_PRESCALER_256          5
#define TIMERS_u8_TIMER1_PRESCALER_1024         6
#define TIMERS_u8_TIMER1_T1_PIN_FALLING_EDGE    7
#define TIMERS_u8_TIMER1_T1_PIN_RISING_EDGE     8




/* Define Macros For Options for Selecting Compare Match Mode on OC1A ,nonPWM */
#define TIMERS_u8_TIMER1_OC1A_DISCONNECTED         1
#define TIMERS_u8_TIMER1_OC1A_TOGGLE               2
#define TIMERS_u8_TIMER1_OC1A_CLEAR                3
#define TIMERS_u8_TIMER1_OC1A_SET                  4

/* Define Macros For Options for Selecting Compare Match Mode on OC1A ,PWM */
#define TIMERS_u8_TIMER1_OC1A_NON_INVERTING        5
#define TIMERS_u8_TIMER1_OC1A_INVERTING            6
/* Define Macros For Options for Selecting Compare Match Mode on OC1B ,nonPWM */
#define TIMERS_u8_TIMER1_OC1B_DISCONNECTED         1
#define TIMERS_u8_TIMER1_OC1B_TOGGLE               2
#define TIMERS_u8_TIMER1_OC1B_CLEAR                3
#define TIMERS_u8_TIMER1_OC1B_SET                  4
/* Define Macros For Options for Selecting Compare Match Mode on OC1B ,PWM */
#define TIMERS_u8_TIMER1_OC1B_NON_INVERTING        5
#define TIMERS_u8_TIMER1_OC1B_INVERTING            6

/*Define Macros For Options for Selecting Channel*/
#define TIMERS_u8_TIMER1_CHANNEL_A_B               1         
#define TIMERS_u8_TIMER1_CHANNEL_A                 2
#define TIMERS_u8_TIMER1_CHANNEL_B                 3


/* Define Macros For Options for Selecting Interrupt */
#define TIMERS_u8_Timer1_OVF                       1
#define TIMERS_u8_Timer1_COMPB                     2
#define TIMERS_u8_Timer1_COMPA                     3
#define TIMERS_u8_Timer1_CAPT                      4


/* Define Macros For Options for Input Capture Edge */
#define TIMERS_u8_Timer1_DISCONNECTED              1
#define TIMERS_u8_Timer1_FALLING_EDGE              2
#define TIMERS_u8_Timer1_RAISING_EDGE              3

#endif