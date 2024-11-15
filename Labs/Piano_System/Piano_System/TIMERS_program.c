/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 11/5/2024       *************************/
/*************************      SWC: TIMERS         *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMERS_interface.h"
#include "TIMERS_config.h"
#include "TIMERS_private.h"

/* Global Pointer to Function of Timer0 OVF */
static void (*TIMERS_pfTimer0OVF)(void) = NULL;
static void (*TIMERS_pfTimer0CTC)(void) = NULL;

/* Global Pointer to Function of Timer1 OVF */
static void (*TIMERS_pfTimer1OVF)(void) = NULL;
static void (*TIMERS_pfTimer1CTC_COMPA)(void) = NULL;
static void (*TIMERS_pfTimer1CAPT)(void) = NULL;
static void (*TIMERS_pfTimer1CTC_COMPB)(void) = NULL;

void TIMERS_voidTimer0Init(void)
{
	/* Select Mode  */
#if TIMERS_u8_TIMER0_MODE == TIMERS_u8_TIMER0_NORMAL_MODE
	/* Select Mode => Normal Mode */
	CLR_BIT(TIMERS_u8_TCCR0_REG,6);
	CLR_BIT(TIMERS_u8_TCCR0_REG,3);
#elif TIMERS_u8_TIMER0_MODE == TIMERS_u8_TIMER0_CTC_MODE
	/* Select Mode => CTC Mode */
	CLR_BIT(TIMERS_u8_TCCR0_REG,6);
	SET_BIT(TIMERS_u8_TCCR0_REG,3);
#elif TIMERS_u8_TIMER0_MODE == TIMERS_u8_TIMER0_PWM_PHASE_CORRECT_MODE
	/* Select Mode => Phase Correct PWM Mode */
	SET_BIT(TIMERS_u8_TCCR0_REG,6);
	CLR_BIT(TIMERS_u8_TCCR0_REG,3);
#elif TIMERS_u8_TIMER0_MODE == TIMERS_u8_TIMER0_PWM_FAST_PWM_MODE
	/* Select Mode => Fast PWM Mode */
	SET_BIT(TIMERS_u8_TCCR0_REG,6);
	SET_BIT(TIMERS_u8_TCCR0_REG,3);
#endif
	/* Select INT  */
#if TIMERS_u8_TIMER0_MODE == TIMERS_u8_TIMER0_NORMAL_MODE
	/* Enable OVF Interrupt */
	SET_BIT(TIMERS_u8_TIMSK_REG,0);
#elif TIMERS_u8_TIMER0_MODE == TIMERS_u8_TIMER0_CTC_MODE
	/* Enable CTC Interrupt */
	SET_BIT(TIMERS_u8_TIMSK_REG,1);
#endif
#if TIMERS_u8_TIMER0_MODE == TIMERS_u8_TIMER0_NORMAL_MODE
	/* Set Preload Value */
	TIMERS_u8_TCNT0_REG = TIMERS_u8_TIMER0_PRELOAD_VALUE;
#elif TIMERS_u8_TIMER0_MODE == TIMERS_u8_TIMER0_CTC_MODE
	/* Set Compare Match Unit Register */
	TIMERS_u8_OCR0_REG = TIMERS_u8_TIMER0_COMPARE_MATCH_OCR0;
#endif

#if TIMERS_u8_TIMER0_COMPARE_MATCH_MODE == TIMERS_u8_TIMER0_OC0_DISCONNECTED
	CLR_BIT(TIMERS_u8_TCCR0_REG,5);
	CLR_BIT(TIMERS_u8_TCCR0_REG,4);
#elif TIMERS_u8_TIMER0_COMPARE_MATCH_MODE == TIMERS_u8_TIMER0_OC0_TOGGLE
	CLR_BIT(TIMERS_u8_TCCR0_REG,5);
	SET_BIT(TIMERS_u8_TCCR0_REG,4);
#elif TIMERS_u8_TIMER0_COMPARE_MATCH_MODE == TIMERS_u8_TIMER0_OC0_CLEAR
	SET_BIT(TIMERS_u8_TCCR0_REG,5);
	CLR_BIT(TIMERS_u8_TCCR0_REG,4);
#elif TIMERS_u8_TIMER0_COMPARE_MATCH_MODE == TIMERS_u8_TIMER0_OC0_SET
	SET_BIT(TIMERS_u8_TCCR0_REG,5);
	SET_BIT(TIMERS_u8_TCCR0_REG,4);
#elif TIMERS_u8_TIMER0_COMPARE_MATCH_MODE == TIMERS_u8_TIMER0_OC0_NON_INVERTING
	SET_BIT(TIMERS_u8_TCCR0_REG,5);
	CLR_BIT(TIMERS_u8_TCCR0_REG,4);
#elif TIMERS_u8_TIMER0_COMPARE_MATCH_MODE == TIMERS_u8_TIMER0_OC0_INVERTING
	SET_BIT(TIMERS_u8_TCCR0_REG,5);
	SET_BIT(TIMERS_u8_TCCR0_REG,4);
#endif

#if TIMERS_u8_TIMER0_CLOCK_SOURCE == TIMERS_u8_TIMER0_NO_SOURCE
	CLR_BIT(TIMERS_u8_TCCR0_REG,2);
	CLR_BIT(TIMERS_u8_TCCR0_REG,1);
	CLR_BIT(TIMERS_u8_TCCR0_REG,0);
#elif TIMERS_u8_TIMER0_CLOCK_SOURCE == TIMERS_u8_TIMER0_NO_PRESCALER
	CLR_BIT(TIMERS_u8_TCCR0_REG,2);
	CLR_BIT(TIMERS_u8_TCCR0_REG,1);
	SET_BIT(TIMERS_u8_TCCR0_REG,0);
#elif TIMERS_u8_TIMER0_CLOCK_SOURCE == TIMERS_u8_TIMER0_PRESCALER_8
	/* Set Prescaler Value CLK/8 */
	CLR_BIT(TIMERS_u8_TCCR0_REG,2);
	SET_BIT(TIMERS_u8_TCCR0_REG,1);
	CLR_BIT(TIMERS_u8_TCCR0_REG,0);
#elif TIMERS_u8_TIMER0_CLOCK_SOURCE == TIMERS_u8_TIMER0_PRESCALER_64
	/* Set Prescaler Value CLK/64 */
	CLR_BIT(TIMERS_u8_TCCR0_REG,2);
	SET_BIT(TIMERS_u8_TCCR0_REG,1);
	SET_BIT(TIMERS_u8_TCCR0_REG,0);
#elif TIMERS_u8_TIMER0_CLOCK_SOURCE == TIMERS_u8_TIMER0_PRESCALER_256
	/* Set Prescaler Value CLK/256 */
	SET_BIT(TIMERS_u8_TCCR0_REG,2);
	CLR_BIT(TIMERS_u8_TCCR0_REG,1);
	CLR_BIT(TIMERS_u8_TCCR0_REG,0);
#elif TIMERS_u8_TIMER0_CLOCK_SOURCE == TIMERS_u8_TIMER0_PRESCALER_1024
	/* Set Prescaler Value CLK/1024 */
	SET_BIT(TIMERS_u8_TCCR0_REG,2);
	CLR_BIT(TIMERS_u8_TCCR0_REG,1);
	SET_BIT(TIMERS_u8_TCCR0_REG,0);
#elif TIMERS_u8_TIMER0_CLOCK_SOURCE == TIMERS_u8_TIMER0_T0_PIN_FALLING_EDGE
	SET_BIT(TIMERS_u8_TCCR0_REG,2);
	SET_BIT(TIMERS_u8_TCCR0_REG,1);
	CLR_BIT(TIMERS_u8_TCCR0_REG,0);
#elif TIMERS_u8_TIMER0_CLOCK_SOURCE == TIMERS_u8_TIMER0_T0_PIN_RISING_EDGE
	SET_BIT(TIMERS_u8_TCCR0_REG,2);
	SET_BIT(TIMERS_u8_TCCR0_REG,1);
	SET_BIT(TIMERS_u8_TCCR0_REG,0);
#endif

}

void TIMERS_voidTimer1Init(void)
{
	/* Select Mode  */
#if TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_NORMAL_MODE
	CLR_BIT(TIMERS_u8_TCCR1A_REG,0);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,3);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,4);
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_PWM_PHASE_CORRECT_8BIT_MODE
	SET_BIT(TIMERS_u8_TCCR1A_REG,0);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,3);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,4);
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_PWM_PHASE_CORRECT_9BIT_MODE
	CLR_BIT(TIMERS_u8_TCCR1A_REG,0);
	SET_BIT(TIMERS_u8_TCCR1A_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,3);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,4);
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_PWM_PHASE_CORRECT_10BIT_MODE
	SET_BIT(TIMERS_u8_TCCR1A_REG,0);
	SET_BIT(TIMERS_u8_TCCR1A_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,3);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,4);
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_CTC_OCR1A_MODE 
	CLR_BIT(TIMERS_u8_TCCR1A_REG,0);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,1);
	SET_BIT(TIMERS_u8_TCCR1B_REG,3);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,4);
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_CTC_OCR1B_MODE 
	CLR_BIT(TIMERS_u8_TCCR1A_REG,0);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,1);
	SET_BIT(TIMERS_u8_TCCR1B_REG,3);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,4);
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_FAST_PWM_8BIT_MODE
	SET_BIT(TIMERS_u8_TCCR1A_REG,0);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,1);
	SET_BIT(TIMERS_u8_TCCR1B_REG,3);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,4);
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_FAST_PWM_9BIT_MODE
	CLR_BIT(TIMERS_u8_TCCR1A_REG,0);
	SET_BIT(TIMERS_u8_TCCR1A_REG,1);
	SET_BIT(TIMERS_u8_TCCR1B_REG,3);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,4);
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_FAST_PWM_10BIT_MODE
	SET_BIT(TIMERS_u8_TCCR1A_REG,0);
	SET_BIT(TIMERS_u8_TCCR1A_REG,1);
	SET_BIT(TIMERS_u8_TCCR1B_REG,3);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,4);
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_PWM_PHASE_FREQ_CORRECT_ICR1_MODE
	CLR_BIT(TIMERS_u8_TCCR1A_REG,0);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,3);
	SET_BIT(TIMERS_u8_TCCR1B_REG,4);
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_PWM_PHASE_FREQ_CORRECT_OCR1A_MODE
	SET_BIT(TIMERS_u8_TCCR1A_REG,0);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,3);
	SET_BIT(TIMERS_u8_TCCR1B_REG,4);
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_PWM_PHASE_CORRECT_ICR1_MODE
	CLR_BIT(TIMERS_u8_TCCR1A_REG,0);
	SET_BIT(TIMERS_u8_TCCR1A_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,3);
	SET_BIT(TIMERS_u8_TCCR1B_REG,4);
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE
	SET_BIT(TIMERS_u8_TCCR1A_REG,0);
	SET_BIT(TIMERS_u8_TCCR1A_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,3);
	SET_BIT(TIMERS_u8_TCCR1B_REG,4);
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_CTC_ICR1_MODE
	CLR_BIT(TIMERS_u8_TCCR1A_REG,0);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,1);
	SET_BIT(TIMERS_u8_TCCR1B_REG,3);
	SET_BIT(TIMERS_u8_TCCR1B_REG,4);
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_FAST_PWM_ICR1_MODE
	CLR_BIT(TIMERS_u8_TCCR1A_REG,0);
	SET_BIT(TIMERS_u8_TCCR1A_REG,1);
	SET_BIT(TIMERS_u8_TCCR1B_REG,3);
	SET_BIT(TIMERS_u8_TCCR1B_REG,4);
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_FAST_PWM_OCR1A_MODE
	SET_BIT(TIMERS_u8_TCCR1A_REG,0);
	SET_BIT(TIMERS_u8_TCCR1A_REG,1);
	SET_BIT(TIMERS_u8_TCCR1B_REG,3);
	SET_BIT(TIMERS_u8_TCCR1B_REG,4);
#endif

	/* Select INT  */
#if TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_NORMAL_MODE
	/* Enable OVF Interrupt */
	SET_BIT(TIMERS_u8_TIMSK_REG,2);
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_CTC_OCR1A_MODE
	/* Enable CTC Interrupt OCR1A */
	SET_BIT(TIMERS_u8_TIMSK_REG,4);
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_CTC_OCR1B_MODE
	/* Enable CTC Interrupt OCR1B */
	SET_BIT(TIMERS_u8_TIMSK_REG,3);
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_CTC_ICR1_MODE
	/* Enable CTC Interrupt ICR1 */
	SET_BIT(TIMERS_u8_TIMSK_REG,5);
#endif


#if TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_NORMAL_MODE
	/* Set Preload Value */
	TIMERS_u16_TCNT1_REG = TIMERS_u16_TIMER1_PRELOAD_VALUE;
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_CTC_OCR1A_MODE
	/* Set Compare Match Unit Register */
	TIMERS_u16_OCR1A_REG = TIMERS_u16_TIMER1_COMPARE_MATCH_OCR1A;
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_CTC_OCR1B_MODE
	/* Set Compare Match Unit Register */
	TIMERS_u16_OCR1B_REG = TIMERS_u16_TIMER1_COMPARE_MATCH_OCR1B;
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_FAST_PWM_ICR1_MODE
	/* Set Top Value in ICR1 */
	TIMERS_u16_ICR1_REG = TIMERS_u16_TIMER1_TOP_VALUE_ICR1;
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_PWM_PHASE_CORRECT_ICR1_MODE
	/* Set Top Value in ICR1 */
	TIMERS_u16_ICR1_REG = TIMERS_u16_TIMER1_TOP_VALUE_ICR1;
#elif TIMERS_u8_TIMER1_MODE == TIMERS_u8_TIMER1_CTC_ICR1_MODE
	/* Set Top Value in ICR1 */
	TIMERS_u16_ICR1_REG = TIMERS_u16_TIMER1_TOP_VALUE_ICR1;
#endif

#if TIMERS_u8_TIMER1_CHANNEL == TIMERS_u8_TIMER1_CHANNEL_A_B
	/* Set Compare Match Unit Register */
	TIMERS_u16_OCR1A_REG = TIMERS_u16_TIMER1_COMPARE_MATCH_OCR1A;
	/* Set Compare Match Unit Register */
	TIMERS_u16_OCR1B_REG = TIMERS_u16_TIMER1_COMPARE_MATCH_OCR1B;
#elif TIMERS_u8_TIMER1_CHANNEL == TIMERS_u8_TIMER1_CHANNEL_A
	/* Set Compare Match Unit Register */
	TIMERS_u16_OCR1A_REG = TIMERS_u16_TIMER1_COMPARE_MATCH_OCR1A;
#elif TIMERS_u8_TIMER1_CHANNEL == TIMERS_u8_TIMER1_CHANNEL_B
	/* Set Compare Match Unit Register */
	TIMERS_u16_OCR1B_REG = TIMERS_u16_TIMER1_COMPARE_MATCH_OCR1B;
#endif

/* Compare Match Output Mode unit A */
#if TIMERS_u8_TIMER1_COMPARE_MATCH_MODE_A == TIMERS_u8_TIMER1_OC1A_DISCONNECTED
	CLR_BIT(TIMERS_u8_TCCR1A_REG,6);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,7);
#elif TIMERS_u8_TIMER1_COMPARE_MATCH_MODE_A == TIMERS_u8_TIMER1_OC1A_TOGGLE
	SET_BIT(TIMERS_u8_TCCR1A_REG,6);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,7);
#elif TIMERS_u8_TIMER1_COMPARE_MATCH_MODE_A == TIMERS_u8_TIMER1_OC1A_CLEAR
	CLR_BIT(TIMERS_u8_TCCR1A_REG,6);
	SET_BIT(TIMERS_u8_TCCR1A_REG,7);
#elif TIMERS_u8_TIMER1_COMPARE_MATCH_MODE_A == TIMERS_u8_TIMER1_OC1A_SET
	SET_BIT(TIMERS_u8_TCCR1A_REG,6);
	SET_BIT(TIMERS_u8_TCCR1A_REG,7);
#elif TIMERS_u8_TIMER1_COMPARE_MATCH_MODE_A == TIMERS_u8_TIMER1_OC1A_NON_INVERTING
	CLR_BIT(TIMERS_u8_TCCR1A_REG,6);
	SET_BIT(TIMERS_u8_TCCR1A_REG,7);
#elif TIMERS_u8_TIMER1_COMPARE_MATCH_MODE_A == TIMERS_u8_TIMER1_OC1A_INVERTING
	SET_BIT(TIMERS_u8_TCCR1A_REG,6);
	SET_BIT(TIMERS_u8_TCCR1A_REG,7);
#endif
/* Compare Match Output Mode unit B */
#if TIMERS_u8_TIMER1_COMPARE_MATCH_MODE_B == TIMERS_u8_TIMER1_OC1B_DISCONNECTED
	CLR_BIT(TIMERS_u8_TCCR1A_REG,4);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,5);
#elif TIMERS_u8_TIMER1_COMPARE_MATCH_MODE_B == TIMERS_u8_TIMER1_OC1B_TOGGLE
	SET_BIT(TIMERS_u8_TCCR1A_REG,4);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,5);
#elif TIMERS_u8_TIMER1_COMPARE_MATCH_MODE_B == TIMERS_u8_TIMER1_OC1B_CLEAR
	CLR_BIT(TIMERS_u8_TCCR1A_REG,4);
	SET_BIT(TIMERS_u8_TCCR1A_REG,5);
#elif TIMERS_u8_TIMER1_COMPARE_MATCH_MODE_B == TIMERS_u8_TIMER1_OC1B_SET
	SET_BIT(TIMERS_u8_TCCR1A_REG,4);
	SET_BIT(TIMERS_u8_TCCR1A_REG,5);
#elif TIMERS_u8_TIMER1_COMPARE_MATCH_MODE_B == TIMERS_u8_TIMER1_OC1B_NON_INVERTING
	CLR_BIT(TIMERS_u8_TCCR1A_REG,4);
	SET_BIT(TIMERS_u8_TCCR1A_REG,5);
#elif TIMERS_u8_TIMER1_COMPARE_MATCH_MODE_B == TIMERS_u8_TIMER1_OC1B_INVERTING
	SET_BIT(TIMERS_u8_TCCR1A_REG,4);
	SET_BIT(TIMERS_u8_TCCR1A_REG,5);
#endif
/* clock source */
#if TIMERS_u8_TIMER1_CLOCK_SOURCE == TIMERS_u8_TIMER1_NO_SOURCE
	CLR_BIT(TIMERS_u8_TCCR1B_REG,2);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,0);
#elif TIMERS_u8_TIMER1_CLOCK_SOURCE == TIMERS_u8_TIMER1_NO_PRESCALER
	CLR_BIT(TIMERS_u8_TCCR1B_REG,2);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,1);
	SET_BIT(TIMERS_u8_TCCR1B_REG,0);
#elif TIMERS_u8_TIMER1_CLOCK_SOURCE == TIMERS_u8_TIMER1_PRESCALER_8
	/* Set Prescaler Value CLK/8 */
	CLR_BIT(TIMERS_u8_TCCR1B_REG,2);
	SET_BIT(TIMERS_u8_TCCR1B_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,0);
#elif TIMERS_u8_TIMER1_CLOCK_SOURCE == TIMERS_u8_TIMER1_PRESCALER_64
	/* Set Prescaler Value CLK/64 */
	CLR_BIT(TIMERS_u8_TCCR1B_REG,2);
	SET_BIT(TIMERS_u8_TCCR1B_REG,1);
	SET_BIT(TIMERS_u8_TCCR1B_REG,0);
#elif TIMERS_u8_TIMER1_CLOCK_SOURCE == TIMERS_u8_TIMER1_PRESCALER_256
	/* Set Prescaler Value CLK/256 */
	SET_BIT(TIMERS_u8_TCCR1B_REG,2);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,0);
#elif TIMERS_u8_TIMER1_CLOCK_SOURCE == TIMERS_u8_TIMER1_PRESCALER_1024
	/* Set Prescaler Value CLK/1024 */
	SET_BIT(TIMERS_u8_TCCR1B_REG,2);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,1);
	SET_BIT(TIMERS_u8_TCCR1B_REG,0);
#elif TIMERS_u8_TIMER1_CLOCK_SOURCE == TIMERS_u8_TIMER1_T1_PIN_FALLING_EDGE
	SET_BIT(TIMERS_u8_TCCR1B_REG,2);
	SET_BIT(TIMERS_u8_TCCR1B_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,0);
#elif TIMERS_u8_TIMER1_CLOCK_SOURCE == TIMERS_u8_TIMER1_T1_PIN_RISING_EDGE
	SET_BIT(TIMERS_u8_TCCR1B_REG,2);
	SET_BIT(TIMERS_u8_TCCR1B_REG,1);
	SET_BIT(TIMERS_u8_TCCR1B_REG,0);
#endif
}
void TIMERS_voidTimer1SetCompareMatchValueUnitA(u16 Copy_u16OCR1AValue)
{
	TIMERS_u16_OCR1A_REG = Copy_u16OCR1AValue;
}

void TIMERS_voidTimer1SetCompareMatchValueUnitB(u16 Copy_u16OCR1BValue)
{
	TIMERS_u16_OCR1B_REG = Copy_u16OCR1BValue;
}
u8 TIMERS_u8GetTCNT0Value(u8 * Copy_pu8Value)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pu8Value != NULL)
	{
		*Copy_pu8Value = TIMERS_u8_TCNT0_REG;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
void TIMERS_voidTimer1SetICR1Value(u16 Copy_u16ICR1Value)
{
	TIMERS_u16_ICR1_REG = Copy_u16ICR1Value;
}

void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value)
{
	TIMERS_u8_OCR0_REG = Copy_u8OCR0Value;
}

u8 TIMERS_u8Timer0SetCallBack(void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pf != NULL)
	{
		TIMERS_pfTimer0OVF = Copy_pf;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

u8 TIMERS_u8Timer0CTCSetCallBack(void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pf != NULL)
	{
		TIMERS_pfTimer0CTC = Copy_pf;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}


u8 TIMERS_u8Timer1SetCallBack(void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pf != NULL)
	{
		TIMERS_pfTimer1OVF = Copy_pf;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 TIMERS_u8Timer1COMPASetCallBack(void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pf != NULL)
	{
		TIMERS_pfTimer1CTC_COMPA = Copy_pf;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 TIMERS_u8Timer1COMPBSetCallBack(void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pf != NULL)
	{
		TIMERS_pfTimer1CTC_COMPB = Copy_pf;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 TIMERS_u8Timer1CAPTSetCallBack(void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pf != NULL)
	{
		TIMERS_pfTimer1CAPT = Copy_pf;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

/* Prototype for ISR TIMER1 OVF */
void __vector_9(void)   __attribute__((signal));
void __vector_9(void)
{
	static u16 Local_u16CounterOVF = 0;
	Local_u16CounterOVF++;
	if(Local_u16CounterOVF == 3907)
	{
		/* Update Preload Value */
		TIMERS_u16_TCNT1_REG = 192;
		/* Clear the OVF Counter */
		Local_u16CounterOVF = 0;
		/* Call App Function */
		if(TIMERS_pfTimer1OVF != NULL)
		{
			TIMERS_pfTimer1OVF();
		}
	}
}


/* Prototype for ISR TIMER1 COMPB */
void __vector_8(void)   __attribute__((signal));
void __vector_8(void)
{
	static u16 Local_u16CounterCTC = 0;
	Local_u16CounterCTC++;
	if(Local_u16CounterCTC == 10000)
	{
		/* Clear the CTC Counter */
		Local_u16CounterCTC = 0;
		/* Call App Function */
		if(TIMERS_pfTimer1CTC_COMPB != NULL)
		{
			TIMERS_pfTimer1CTC_COMPB();
		}
	}
}

/* Prototype for ISR TIMER1 COMPA */
void __vector_7(void)   __attribute__((signal));
void __vector_7(void)
{
	static u16 Local_u16CounterCTC = 0;
	Local_u16CounterCTC++;
	if(Local_u16CounterCTC == 10000)
	{
		/* Clear the CTC Counter */
		Local_u16CounterCTC = 0;
		/* Call App Function */
		if(TIMERS_pfTimer1CTC_COMPA != NULL)
		{
			TIMERS_pfTimer1CTC_COMPA();
		}
	}
}

/* Prototype for ISR TIMER1 CAPT */
void __vector_6(void)   __attribute__((signal));
void __vector_6(void)
{
	static u16 Local_u16CounterCAPT = 0;
	Local_u16CounterCAPT++;
	if(Local_u16CounterCAPT == 10000)
	{
		/* Clear the CTC Counter */
		Local_u16CounterCAPT = 0;
		/* Call App Function */
		if(TIMERS_pfTimer1CAPT != NULL)
		{
			TIMERS_pfTimer1CAPT();
		}
	}
}

/* Prototype for ISR TIMER0 OVF */
void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{
	static u16 Local_u16CounterOVF = 0;
	Local_u16CounterOVF++;
	if(Local_u16CounterOVF == 3907)
	{
		/* Update Preload Value */
		TIMERS_u8_TCNT0_REG = 192;
		/* Clear the OVF Counter */
		Local_u16CounterOVF = 0;
		/* Call App Function */
		if(TIMERS_pfTimer0OVF != NULL)
		{
			TIMERS_pfTimer0OVF();
		}
	}
}

/* Prototype for ISR TIMER0 CTC */
void __vector_10(void)   __attribute__((signal));
void __vector_10(void)
{
	static u16 Local_u16CounterCTC = 0;
	Local_u16CounterCTC++;
	if(Local_u16CounterCTC == 10000)
	{
		/* Clear the CTC Counter */
		Local_u16CounterCTC = 0;
		/* Call App Function */
		if(TIMERS_pfTimer0CTC != NULL)
		{
			TIMERS_pfTimer0CTC();
		}
	}
}
