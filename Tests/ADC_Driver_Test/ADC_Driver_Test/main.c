/*
 * main.c
 *
 *  Created on: Apr 15, 2024
 *      Author: Hassan Bahnasy
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "ADC_interface.h"

int main(void)
{
	u16 Local_u16DigitalValue,Local_u16AnalogValue;
	DIO_voidInit();
	ADC_voidInit();
	while(1)
	{
		ADC_u8GetDigitalValue(ADC_u8_CHANNEL_0,&Local_u16DigitalValue);
		Local_u16AnalogValue = (u16)((Local_u16DigitalValue * 5000UL) / 1024);
		if(Local_u16AnalogValue <= 1500 )
		{
			//Turn on Led 1
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
		}
		else if ((Local_u16AnalogValue > 1500) && (Local_u16AnalogValue <= 3000))
		{
			//Turn on Led 2
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
		}
		else if (Local_u16AnalogValue > 3000)
		{
			//Turn on Led 3
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_HIGH);
		}
		else
		{
			//error Handling
		}
	}
	return 0;
}
