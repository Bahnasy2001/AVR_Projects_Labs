/*
 * main.c
 *
 *  Created on: May 11, 2024
 *      Author: Hassan Bahnasy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "GI_interface.h"
#include "TIMERS_interface.h"

void App_voidTogLed(void);

int main(void)
{
	DIO_voidInit();
	/* Enable Global Interrupt */
	GI_voidEnableGI();
	/* Set Call Back */
	TIMERS_u8Timer0SetCallBack(&App_voidTogLed);
	/* Start Timer */
	TIMERS_voidTimer0Init();
	/* SuperLoop */
	while(1);

	return 0;
}

void App_voidTogLed(void)
{
	static u8 flag = 0;
	if(flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		flag = 1;
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
		flag = 0;
	}
}
