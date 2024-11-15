/*
 * main.c
 *
 *  Created on: May 9, 2024
 *      Author: Hassan Bahnasy
 */
// LIB Layer
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

//MCAL Layer
#include "DIO_interface.h"
#include "ADC_interface.h"
//HAL Layer
#include "LCD_interface.h"




int main()
{
	//Initialization
	DIO_voidInit();
	LCD_voidInit();
	ADC_voidInit();
	u16 Local_u16DigitalValue,Local_u16AnalogValue,Local_u16PreviousAnalogValue = 0xFFFF;
	u8 customCharOne[] = {
			0b00100,
			0b01010,
			0b10001,
			0b01010,
			0b00100,
			0b00100,
			0b01010,
			0b10001
	};
	u8 customCharTwo[] = {
			0b00000,
			0b00000,
			0b00000,
			0b10010,
			0b01101,
			0b10010,
			0b00000,
			0b00000
	};
	while(1)
	{
		/* Get ADC Value*/
		ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_0,&Local_u16DigitalValue);
		Local_u16AnalogValue = (u16)((Local_u16DigitalValue * 5000UL)/1024);
		//Check if the ADC Value is Changed
		if((s16)(Local_u16AnalogValue - Local_u16PreviousAnalogValue) > 0 || (s16)(Local_u16AnalogValue - Local_u16PreviousAnalogValue) < 0 )
		{
			LCD_voidClearScreen();
			//if the Light ON
			if(Local_u16AnalogValue > 2500)
			{
				LCD_voidWriteString((u8*)"Good Morning");
				LCD_voidWriteSpecialChar(LCD_u8_CHAR0,customCharOne,LCD_u8_LINE1,13);
				LCD_u8GoToXY(LCD_u8_LINE2,0);
				LCD_voidWriteString((u8*)"Light ON!");
			}
			else //if the Light OFF
			{
				LCD_voidWriteString((u8*)"Good Evening");
				LCD_voidWriteSpecialChar(LCD_u8_CHAR1,customCharTwo,LCD_u8_LINE1,13);
				LCD_u8GoToXY(LCD_u8_LINE2,0);
				LCD_voidWriteString((u8*)"Light OFF!");
			}
			//Save the Previous Value
			Local_u16PreviousAnalogValue = Local_u16AnalogValue;
		}
	}
	return 0;
}
