/*
 * main.c
 *
 *  Created on: Mar 9, 2024
 *      Author: Hassan Bahnasy
 */


/*Lib Layer*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer */
#include "DIO_interface.h"
/* HAL Layer */
#include "LCD_interface.h"
#include "KPD_interface.h"

int main(void)
{
	u8 Local_u8Key;
	DIO_voidInit();
	LCD_voidInit();

	while(1)
	{
		KPD_u8GetKeyState(&Local_u8Key);
		if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
		{
			LCD_voidSendChar(Local_u8Key);
		}
	}

	return 0;
}
