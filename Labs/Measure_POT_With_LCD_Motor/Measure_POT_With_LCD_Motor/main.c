/*
 * main.c
 *
 *  Created on: Apr 21, 2024
 *      Author: Hassan Bahnasy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#include "DIO_interface.h"
#include "LCD_interface.h"
#include "H_Bridge.h"
#include "ADC_interface.h"

int main(void)
{
	const u8 SpecialChar[] ={
			0b00100,
			0b01010,
			0b10001,
			0b01010,
			0b00100,
			0b11111,
			0b01010,
			0b10001
	};
	u16 Local_u16DigitalValue,Local_u16AnalogValue;
	DIO_voidInit();
	LCD_voidInit();
	ADC_voidInit();
	LCD_voidWriteSpecialChar(LCD_u8_CHAR0,(u8*)SpecialChar,LCD_u8_LINE1,7);
	while(1)
	{
		ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_0,&Local_u16DigitalValue);
		Local_u16AnalogValue = (u16)((Local_u16DigitalValue * 5000UL) / 1024);
		if(Local_u16AnalogValue <= 2500)
		{
			if(Local_u16AnalogValue > 2200)
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteSpecialChar(LCD_u8_CHAR0,(u8*)SpecialChar,LCD_u8_LINE1,7);
			}
			else if(Local_u16AnalogValue > 1900)
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteSpecialChar(LCD_u8_CHAR0,(u8*)SpecialChar,LCD_u8_LINE1,6);
			}
			else if(Local_u16AnalogValue > 1600)
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteSpecialChar(LCD_u8_CHAR0,(u8*)SpecialChar,LCD_u8_LINE1,5);
			}
			else if(Local_u16AnalogValue > 1300)
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteSpecialChar(LCD_u8_CHAR0,(u8*)SpecialChar,LCD_u8_LINE1,4);
			}
			else if( Local_u16AnalogValue > 1000)
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteSpecialChar(LCD_u8_CHAR0,(u8*)SpecialChar,LCD_u8_LINE1,3);
			}
			else if(Local_u16AnalogValue > 700)
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteSpecialChar(LCD_u8_CHAR0,(u8*)SpecialChar,LCD_u8_LINE1,2);
			}
			else if(Local_u16AnalogValue > 400)
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteSpecialChar(LCD_u8_CHAR0,(u8*)SpecialChar,LCD_u8_LINE1,1);
			}
			else if(Local_u16AnalogValue < 400)
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteSpecialChar(LCD_u8_CHAR0,(u8*)SpecialChar,LCD_u8_LINE1,0);
			}
			H_BRIDGE_voidRotateCCW();
			_delay_ms(500);
		}
		else if(Local_u16AnalogValue > 2500)
		{
			if(Local_u16AnalogValue > 4700)
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteSpecialChar(LCD_u8_CHAR0,(u8*)SpecialChar,LCD_u8_LINE1,15);
			}
			else if(Local_u16AnalogValue > 4400)
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteSpecialChar(LCD_u8_CHAR0,(u8*)SpecialChar,LCD_u8_LINE1,14);
			}
			else if(Local_u16AnalogValue > 4100)
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteSpecialChar(LCD_u8_CHAR0,(u8*)SpecialChar,LCD_u8_LINE1,13);
			}
			else if(Local_u16AnalogValue > 3800)
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteSpecialChar(LCD_u8_CHAR0,(u8*)SpecialChar,LCD_u8_LINE1,12);
			}
			else if( Local_u16AnalogValue > 3500)
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteSpecialChar(LCD_u8_CHAR0,(u8*)SpecialChar,LCD_u8_LINE1,11);
			}
			else if(Local_u16AnalogValue > 3200)
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteSpecialChar(LCD_u8_CHAR0,(u8*)SpecialChar,LCD_u8_LINE1,10);
			}
			else if(Local_u16AnalogValue > 2900)
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteSpecialChar(LCD_u8_CHAR0,(u8*)SpecialChar,LCD_u8_LINE1,9);
			}
			else if((Local_u16AnalogValue < 2900) && (Local_u16AnalogValue > 2500))
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteSpecialChar(LCD_u8_CHAR0,(u8*)SpecialChar,LCD_u8_LINE1,0);
			}
			H_BRIDGE_voidRotateCW();
			_delay_ms(500);
		}
		else
		{

		}
	}
	return 0;
}
