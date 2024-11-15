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

void TIMERS_voidTimer0Init(void)
{
	/* Select Mode => Normal Mode */
	CLR_BIT(TIMERS_u8_TCCR0_REG,6);
	CLR_BIT(TIMERS_u8_TCCR0_REG,3);

	/* Enable OVF Interrupt */
	SET_BIT(TIMERS_u8_TIMSK_REG,0);
	/* Set Preload Value */
	TIMERS_u8_TCNT0_REG = 192;
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

