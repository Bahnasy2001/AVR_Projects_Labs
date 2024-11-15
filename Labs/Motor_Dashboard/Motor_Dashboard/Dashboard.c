/*
 * Dashboard.c
 *
 *  Created on: Mar 22, 2024
 *      Author: Hassan Bahnasy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "KPD_interface.h"
#include "LCD_interface.h"
#include "H_Bridge.h"


void Dashboard_FrameOne(void)
{
	u8 Local_u8Key;

	LCD_voidClearScreen();
	_delay_ms(20);
	LCD_voidWriteString((u8*)"1-DC Motor");
	LCD_u8GoToXY(LCD_u8_LINE2,0);
	LCD_voidWriteString((u8*)"2-Exit");

	while(1)
	{
		KPD_u8GetKeyState(&Local_u8Key); // Get state of pressed key
		if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED) // If a key is pressed
		{
			if(Local_u8Key == '1') // If pressed key is '1'
			{
				Dashboard_FrameTwo();
			}
			else if (Local_u8Key == '2') // If pressed key is '2'
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteString((u8*)"GoodLuck!");
				_delay_ms(3000);
				while(1)
				{

				}
			}
			else
			{
				//error handling
			}
		}
	}
}
void Dashboard_FrameTwo(void)
{
	u8 Local_u8Key;

	LCD_voidClearScreen();
	_delay_ms(20);
	LCD_voidWriteString((u8*)"1-RotateCW");
	LCD_u8GoToXY(LCD_u8_LINE2,0);
	LCD_voidWriteString((u8*)"2-RotateCCW");
	LCD_u8GoToXY(LCD_u8_LINE1,10);
	LCD_voidWriteString((u8*)"3-Back");
	while(1)
	{
		KPD_u8GetKeyState(&Local_u8Key); // Get state of pressed key
		if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED) // If a key is pressed
		{
			if(Local_u8Key == '1') // If pressed key is '1'
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteString((u8*)" Rotate CW ....");
				H_BRIDGE_voidRotateCW();
				_delay_ms(5000);
				while(1);
			}
			else if (Local_u8Key == '2') // If pressed key is '2'
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteString((u8*)" Rotate CCW ....");
				H_BRIDGE_voidRotateCCW();
				_delay_ms(5000);
				while(1);
			}
			else if(Local_u8Key == '3' ) // If pressed key is '3'
			{
				Dashboard_FrameOne();
			}
			else
			{
				//error handling
			}
		}
	}

}
