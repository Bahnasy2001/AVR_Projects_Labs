/*
 * main.c
 *
 *  Created on: May 22, 2024
 *      Author: Hassan Bahnasy
 */

/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
/* MCAL Layer */
#include "DIO_interface.h"
#include "TIMERS_interface.h"

/* HAL Layer */
#include "KPD_interface.h"


void PWM_SetFrequency(u16 frequency);
int main(void)
{
	u16 Local_u16Key;
	DIO_voidInit(); // Initialize DIO
	TIMERS_voidTimer1Init(); // Initialize Timer1

	while(1)
	{
		KPD_u8GetKeyState(&Local_u16Key); // Get the key state from the keypad
		if(Local_u16Key != KPD_u8_KEY_NOT_PRESSED)
		{
			PWM_SetFrequency(Local_u16Key); // Set the PWM frequency based on the key pressed
		}
	}
	return 0;
}
void PWM_SetFrequency(u16 frequency)
{
	u16 top_value = (F_CPU / (2 * 8 * frequency)) - 1; // Calculate TOP value
	TIMERS_voidTimer1SetICR1Value(top_value);
	TIMERS_voidTimer1SetCompareMatchValueUnitA(top_value / 2); // Set duty cycle to 50%
}
