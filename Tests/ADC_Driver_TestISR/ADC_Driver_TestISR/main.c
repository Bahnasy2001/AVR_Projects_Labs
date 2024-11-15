/*
 * main.c
 *
 *  Created on: Apr 17, 2024
 *      Author: Hassan Bahnasy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "GI_interface.h"
#include "ADC_interface.h"

static u16 App_u16DigitalValue = 0xffff;

void App_voidCallBack(u16 Copy_u16ADCValue);

int main(void)
{

	DIO_voidInit();
	GI_voidEnableGI();
	ADC_voidInit();
	while(1)
	{
		ADC_u8GetDigitalValueAsynch(ADC_u8_CHANNEL_0,&App_voidCallBack);
	}
	return 0;
}
void App_voidCallBack(u16 Copy_u16ADCValue)
{
	u16 Local_u16AnalogValue;
	App_u16DigitalValue = Copy_u16ADCValue;
	if(App_u16DigitalValue != 0xffff)
	{
		Local_u16AnalogValue = (u16)((App_u16DigitalValue * 5000UL) / 1024);
		if(Local_u16AnalogValue < 3000)
		{
			//Turn off Led
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
		}
		else
		{
			//Turn on Led
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
		}
		App_u16DigitalValue = 0xffff;
	}

}
