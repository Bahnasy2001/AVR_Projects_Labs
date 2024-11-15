/*
 * main.c
 *
 *  Created on: May 11, 2024
 *      Author: Hassan Bahnasy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "ADC_interface.h"

int main()
{
	DIO_voidInit();
	ADC_voidInit();
	u16 Local_u16DigitalValue,Local_u16AnalogValue;
	while(1)
	{
		ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_0,&Local_u16DigitalValue);
		Local_u16AnalogValue = (u16)((Local_u16DigitalValue * 5000UL)/1024);
		if((Local_u16AnalogValue >= 0) && (Local_u16AnalogValue < 625))
		{
			DIO_u8SetPortValue(DIO_u8_PORTD,0x01);
		}
		else if ((Local_u16AnalogValue >= 625) && (Local_u16AnalogValue < 1250))
		{
			DIO_u8SetPortValue(DIO_u8_PORTD,0x03);
		}
		else if ((Local_u16AnalogValue >= 1250) && (Local_u16AnalogValue < 1875))
		{
			DIO_u8SetPortValue(DIO_u8_PORTD,0x07);
		}
		else if ((Local_u16AnalogValue >= 1875) && (Local_u16AnalogValue < 2500))
		{
			DIO_u8SetPortValue(DIO_u8_PORTD,0x0F);
		}
		else if ((Local_u16AnalogValue >= 2500) && (Local_u16AnalogValue < 3125))
		{
			DIO_u8SetPortValue(DIO_u8_PORTD,0x1F);
		}
		else if ((Local_u16AnalogValue >= 3125) && (Local_u16AnalogValue < 3750))
		{
			DIO_u8SetPortValue(DIO_u8_PORTD,0x3F);
		}
		else if ((Local_u16AnalogValue >= 3750) && (Local_u16AnalogValue < 4375))
		{
			DIO_u8SetPortValue(DIO_u8_PORTD,0x7F);
		}
		else if ((Local_u16AnalogValue >= 4375) && (Local_u16AnalogValue < 5000))
		{
			DIO_u8SetPortValue(DIO_u8_PORTD,0xFF);
		}
		else
		{
			//error handling
		}
	}
	return 0;
}
