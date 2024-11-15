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


void TIMERS_voidTimer0Init(void)
{
#if TIMERS_u8_TIMER0_MODE == TIMERS_u8_TIMER0_NORMAL_MODE
	/* Select Mode => Normal Mode */
	CLR_BIT(TIMERS_u8_TCCR0_REG,6);
	CLR_BIT(TIMERS_u8_TCCR0_REG,3);
#elif TIMERS_u8_TIMER0_MODE == TIMERS_u8_TIMER0_CTC_MODE
	/* Select Mode => CTC Mode */
	CLR_BIT(TIMERS_u8_TCCR0_REG,6);
	SET_BIT(TIMERS_u8_TCCR0_REG,3);
#endif

#if TIMERS_u8_TIMER0_MODE == TIMERS_u8_TIMER0_NORMAL_MODE
	/* Enable OVF Interrupt */
	SET_BIT(TIMERS_u8_TIMSK_REG,0);
#elif TIMERS_u8_TIMER0_MODE == TIMERS_u8_TIMER0_CTC_MODE
	/* Enable CTC Interrupt */
	SET_BIT(TIMERS_u8_TIMSK_REG,1);
#endif
#if TIMERS_u8_TIMER0_MODE == TIMERS_u8_TIMER0_NORMAL_MODE
	/* Set Preload Value */
	TIMERS_u8_TCNT0_REG = 192;
#elif TIMERS_u8_TIMER0_MODE == TIMERS_u8_TIMER0_CTC_MODE
	/* Set Compare Match Unit Register */
	TIMERS_u8_OCR0_REG = 99;
#endif
	/* Set Prescaler Value CLK/8 */
	CLR_BIT(TIMERS_u8_TCCR0_REG,2);
	SET_BIT(TIMERS_u8_TCCR0_REG,1);
	CLR_BIT(TIMERS_u8_TCCR0_REG,0);

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
