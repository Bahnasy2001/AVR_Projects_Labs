/*
 * main.c
 *
 *  Created on: Jun 10, 2024
 *      Author: Hassan Bahnasy
 */


/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
/* MCAL Layer */
#include "DIO_interface.h"
#include "GI_interface.h"
#include "EXTI_interface.h"
#include "TIMERS_interface.h"

/* HAL Layer */
#include "LCD_interface.h"

/* Global Variables */
static volatile u16 Period_Ticks = 0;
static volatile u16 ON_Ticks = 0;

/* Functions */
void ICU_SW(void);

int main(void)
{
	/* Initialization */
	DIO_voidInit();
	EXTI_u8EXTIEnable(EXTI_u8_INT2,EXTI_u8_RAISING_EDGE);
	EXTI_u8EXTISetCallBack(EXTI_u8_INT2,&ICU_SW);
	LCD_voidInit();
	TIMERS_voidTimer0Init(); //generate PWM
	TIMERS_voidTimer1Init(); //Measure Periods (Counter)
	GI_voidEnableGI();
	u8 DutyCycle = 0;
	while(1)
	{
		//		/* Busy Wait Condition */
		//		while((Period_Ticks == 0)  && (ON_Ticks == 0));
		//		LCD_u8GoToXY(LCD_u8_LINE1,0);
		//		LCD_voidWriteString((u8*) "PeriodTicks=");
		//		LCD_voidWriteNumber((u32)Period_Ticks);
		//		LCD_u8GoToXY(LCD_u8_LINE2,0);
		//		LCD_voidWriteString((u8*) "ONTicks=");
		//		LCD_voidWriteNumber((u32)ON_Ticks);
		//		_delay_ms(1000);
		//		LCD_voidClearScreen();
		//		DutyCycle = (u32)((f32)(ON_Ticks / Period_Ticks) * 100);
		//		LCD_u8GoToXY(LCD_u8_LINE1,0);
		//		LCD_voidWriteString((u8*) "Duty Cycle = ");
		//		LCD_voidWriteNumber((u32)DutyCycle);
		/* Busy Wait Condition */
		if((Period_Ticks != 0) && (ON_Ticks != 0))
		{
			LCD_u8GoToXY(LCD_u8_LINE1, 0);
			LCD_voidWriteString((u8*) "PeriodTicks=");
			LCD_voidWriteNumber((u32)Period_Ticks);
			LCD_u8GoToXY(LCD_u8_LINE2, 0);
			LCD_voidWriteString((u8*) "ONTicks=");
			LCD_voidWriteNumber((u32)ON_Ticks);
			_delay_ms(1000);
			LCD_voidClearScreen();
			DutyCycle = (u32)((f32)ON_Ticks / Period_Ticks * 100);
			LCD_u8GoToXY(LCD_u8_LINE1, 0);
			LCD_voidWriteString((u8*) "Duty Cycle = ");
			LCD_voidWriteNumber((u32)DutyCycle);
			 _delay_ms(1000);
			LCD_voidClearScreen();
			// Reset the values for the next measurement cycle
			Period_Ticks = 0;
			ON_Ticks = 0;
		}

	}
	return 0;
}
void ICU_SW(void)
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
		TIMERS_u8GetTCNT1Value(&Period_Ticks);
		/* Change Trigger */
		EXTI_u8EXTISetEdge(EXTI_u8_INT2, EXTI_u8_FALLING_EDGE);
	}
	/* Falling Edge */
	else if (Local_u8Counter == 3)
	{
		/* Read Timer1 */
		TIMERS_u8GetTCNT1Value(&ON_Ticks);
		ON_Ticks -= Period_Ticks;
		/* Disable INT */ // ONCE
		//EXTI_u8EXTIDisable(EXTI_u8_INT2);
		Local_u8Counter = 0;
		//Continuous Reading
		/* Change Trigger back to Rising Edge */
		EXTI_u8EXTISetEdge(EXTI_u8_INT2, EXTI_u8_RAISING_EDGE);
	}

}
