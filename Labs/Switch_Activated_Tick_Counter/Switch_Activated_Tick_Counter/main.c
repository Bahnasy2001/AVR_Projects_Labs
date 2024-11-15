/*
 * main.c
 *
 *  Created on: May 13, 2024
 *      Author: Hassan Bahnasy
 */

/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer */
#include "DIO_interface.h"
#include "GI_interface.h"
#include "TIMERS_interface.h"

/* HAL Layer */
#include "LCD_interface.h"

int main(void)
{
	/* Initialization */
	DIO_voidInit();
	GI_voidEnableGI();
	LCD_voidInit();
	TIMERS_voidTimer0Init();
	u8 Local_u8Counter,Local_u8PreviousCounter = 0;
	LCD_voidWriteString((u8 *)"Counter = ");
	TIMERS_u8GetTCNT0Value(&Local_u8Counter); //Get the Number of Counts
	LCD_voidWriteNumber((u32) Local_u8Counter); // Display the Number of Counts
	while(1)
	{
		TIMERS_u8GetTCNT0Value(&Local_u8Counter);//Update the Number of Counts
		/* Check if there is a change in the Number of Counts */
		if(Local_u8Counter - Local_u8PreviousCounter > 0)
		{
			LCD_voidClearScreen();//Clear the Screen
			LCD_voidWriteString((u8 *)"Counter = ");
			TIMERS_u8GetTCNT0Value(&Local_u8Counter);//Get the Number of Counts
			LCD_voidWriteNumber((u32) Local_u8Counter);// Display the Number of Counts

		}
		/* Save the TCNT0 Value in Variable */
		Local_u8PreviousCounter = Local_u8Counter;
	}
	return 0;
}
