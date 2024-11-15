/*
 * main.c
 *
 *  Created on: Mar 25, 2024
 *      Author: Hassan Bahnasy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU  8000000UL
#include <util/delay.h>

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "STEPPER_interface.h"

int main(void)
{
	DIO_voidInit();
	while(1)
	{
		STEPPER_u8Move(STEPPER_u8_CW,0);
		_delay_ms(5000);
		STEPPER_u8Move(STEPPER_u8_CW,290);
		_delay_ms(5000);
	}
	return 0;
}
