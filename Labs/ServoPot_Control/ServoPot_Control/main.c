/*
 * main.c
 *
 *  Created on: Jun 7, 2024
 *      Author: Hassan Bahnasy
 */

/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU  8000000UL
#include <util/delay.h>

/* MCAL Layer */
#include "DIO_interface.h"
#include "GI_interface.h"
#include "ADC_interface.h"
#include "TIMERS_interface.h"

int main(void)
{
	u16 Local_u16DigitalValue,Local_u16ServoValue;
	DIO_voidInit();
	TIMERS_voidTimer1Init();
	ADC_voidInit();


	/* SuperLoop */
	while(1)
	{
		/* Read Pot Value */
		ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_0,&Local_u16DigitalValue);
		Local_u16ServoValue = ((u32)(1000UL * Local_u16DigitalValue) / 1023) + 999;
		if(Local_u16DigitalValue > 512)
		{
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
		}
		/* Update Angle of Servo Motor */
		TIMERS_voidTimer1SetCompareMatchValueUnitA(Local_u16ServoValue);
	}
	return 0;
}
