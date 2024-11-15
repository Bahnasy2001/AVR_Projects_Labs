/*
 * main.c
 *
 *  Created on: Jun 16, 2024
 *      Author: Hassan Bahnasy
 */

/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU  8000000UL
#include <util/delay.h>

/* MCAL Layer */
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "TIMERS_interface.h"
#include "GI_interface.h"

/* HAL Layer */
#include "LCD_interface.h"
#include "SWICU_interface.h"

int main(void)
{
	u32 Local_u32TotalPeriod;
	u8  Local_u8DutyCycle;
	DIO_voidInit();
	LCD_voidInit();

	TIMERS_voidTimer1Init(); //Measure Periods (Counter)
	/* Enable Global Interrupt */
	GI_voidEnableGI();
	TIMERS_voidTimer0Init(); //generate PWM
	SWICU_voidEnable();
	while(1)
	{
		SWICU_u8GetTotalPeriod(&Local_u32TotalPeriod);
		SWICU_u8GetDutyCycle(&Local_u8DutyCycle);
		if ((Local_u32TotalPeriod != 0) && (Local_u8DutyCycle != 0))
		{
			LCD_u8GoToXY(LCD_u8_LINE1, 0);
			LCD_voidWriteString((u8 *)"Duty = ");
			LCD_voidWriteNumber(Local_u8DutyCycle);
			LCD_voidWriteString((u8 *)"%");
			LCD_u8GoToXY(LCD_u8_LINE2, 0);
			LCD_voidWriteString((u8 *)"T P = ");
			LCD_voidWriteNumber(Local_u32TotalPeriod);
			while(1);
		}
	}
	return 0;
}
