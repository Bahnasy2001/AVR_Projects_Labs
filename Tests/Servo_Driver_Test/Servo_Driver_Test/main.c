/*
 * main.c
 *
 *  Created on: May 22, 2024
 *      Author: Hassan Bahnasy
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU  8000000UL
#include <util/delay.h>

#include "DIO_interface.h"
#include "TIMERS_interface.h"
#include "SERVO_interface.h"

int main(void)
{
	DIO_voidInit();
	SERVO_voidInit();
	while(1)
	{
		SERVO_voidRotate(50);
		_delay_ms(1000);
		SERVO_voidRotate(90);
		_delay_ms(1000);
	}
	return 0;
}
