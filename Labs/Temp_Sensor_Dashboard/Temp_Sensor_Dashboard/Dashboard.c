/*
 * Dashboard.c
 *
 *  Created on: Mar 22, 2024
 *      Author: Hassan Bahnasy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include <math.h>
#include "KPD_interface.h"
#include "LCD_interface.h"
#include "ADC_interface.h"


void Dashboard_FrameOne(void)
{
	u8 Local_u8Key;

	LCD_voidClearScreen();
	_delay_ms(20);
	LCD_voidWriteString((u8*)"1-Temp Sensor");
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
	LCD_voidClearScreen(); // Clear the LCD screen
	_delay_ms(20); // Wait for LCD to clear
	LCD_voidWriteString((u8*)"Temp = "); // Display "Temp = " on the LCD
	u16 previousTempValue = 0xFFFF; // Initialize previous temperature value to an out-of-range value
	u16 Local_u16DigitalValue, Local_u16AnalogValue, Local_u16TempValue; // Declare variables

	while (1) // Infinite loop to continuously monitor temperature
	{
		ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_0, &Local_u16DigitalValue); // Read ADC value from temperature sensor
		Local_u16AnalogValue = (u16)((Local_u16DigitalValue * 2560UL) / 1024); // Convert ADC value to analog voltage
		Local_u16TempValue = Local_u16AnalogValue / 10; // Convert analog voltage to temperature in degrees Celsius

		// Check if the current temperature value is different from the previous one
		if (((s16)(Local_u16TempValue - previousTempValue) > 0) || ((s16)(Local_u16TempValue - previousTempValue) < 0))
		{
			// Update the LCD display only if the temperature has changed significantly
			LCD_voidClearScreen(); // Clear the LCD screen
			_delay_ms(20); // Wait for LCD to clear
			LCD_voidWriteString((u8*)"Temp = "); // Display "Temp = " on the LCD
			LCD_voidWriteNumber((u32)Local_u16TempValue); // Display the current temperature value on the LCD

			previousTempValue = Local_u16TempValue; // Update previous temperature value
		}
	}
}

