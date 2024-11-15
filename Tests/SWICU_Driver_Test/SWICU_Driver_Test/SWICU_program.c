/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 16/6/2024       *************************/
/*************************      SWC: SWICU          *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU  8000000UL
#include <util/delay.h>
/* MCAL */
#include "TIMERS_interface.h"
#include "EXTI_interface.h"
#include "LCD_interface.h"

/* HAL */
#include "SWICU_interface.h"
#include "SWICU_private.h"
#include "SWICU_config.h"


/* Global Variables */
static volatile u16 Period_Ticks = 0;
static volatile u16 ON_Ticks = 0;

void SWICU_voidEnable(void)
{
	/* Set EXTI CallBack */
	EXTI_u8EXTISetCallBack(EXTI_u8_INT0,&SWICU_voidEXTICallBack);
	/* Enable EXTI => Raising Edge */
	EXTI_u8EXTIEnable(EXTI_u8_INT0,EXTI_u8_RAISING_EDGE);
}

void SWICU_voidDisable(void)
{
	EXTI_u8EXTIDisable(EXTI_u8_INT0);
}

u8   SWICU_u8GetTotalPeriod(u32 * Copy_pu32TotalPeriod)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if(Copy_pu32TotalPeriod != NULL)
	{
		*Copy_pu32TotalPeriod = Period_Ticks;
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;
}

u8   SWICU_u8GetDutyCycle(u8 * Copy_pu8DutyCycle)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if(Copy_pu8DutyCycle != NULL)
	{
		*Copy_pu8DutyCycle = (u32)((f32)ON_Ticks / Period_Ticks * 100);
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;
}

u8   SWICU_u8GetOnPeriod(u16 * Copy_pu16OnPeriod)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if(Copy_pu16OnPeriod != NULL)
	{
		*Copy_pu16OnPeriod = ON_Ticks;
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;
}

static void SWICU_voidEXTICallBack(void)
{
	static volatile u8 Local_u8Counter = 0;
	Local_u8Counter++;
	/* First Raising Edge */
	if(Local_u8Counter == 1)
	{
		/* Timer starts Counting */
		TIMERS_u8SetTCNT1Value(0);
	}
	/* Second Raising Edge */
	else if (Local_u8Counter == 2)
	{
		/* Read Timer1 */
		TIMERS_u8GetTCNT1Value(&Period_Ticks); // Read timer value
		/* Change Trigger */
		EXTI_u8EXTISetEdge(EXTI_u8_INT0, EXTI_u8_FALLING_EDGE);
	}
	/* Falling Edge */
	else if (Local_u8Counter == 3)
	{
		/* Read Timer1 */
		TIMERS_u8GetTCNT1Value(&ON_Ticks); // Read timer value
		ON_Ticks -= Period_Ticks; // Calculate on ticks
		/* Disable INT */ // ONCE
//		EXTI_u8EXTIDisable(EXTI_u8_INT0);
		Local_u8Counter = 0;
		//Continuous Reading
		/* Change Trigger back to Rising Edge */
		EXTI_u8EXTISetEdge(EXTI_u8_INT0, EXTI_u8_RAISING_EDGE);
	}
}

