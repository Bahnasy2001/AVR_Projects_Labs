/*
 * main.c
 *
 *  Created on: Jun 20, 2024
 *      Author: Hassan Bahnasy
 */

/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/* MCAL Layer */
#include "DIO_interface.h"
#include "GI_interface.h"
#include "UART_interface.h"

/* HAL Layer */
#include "LCD_interface.h"

/* Global Variables */
u8 ReceivedString[16];
volatile u8 AsyncFlag = 0;

void ReceiveCallback(void);
int main(void)
{
	u8 msg[] = "I Love Zamalek ";
	/* Initialization */
	DIO_voidInit();
	UART_voidInit();
	GI_voidEnableGI();
//	UART_u8SendStringSynch(msg);
	while (1)
	{
		_delay_ms(2000);
		UART_u8SendStringSynch(msg);
		_delay_ms(2000);

	}

	return 0;
}

void ReceiveCallback(void)
{
	AsyncFlag = 1;
}
