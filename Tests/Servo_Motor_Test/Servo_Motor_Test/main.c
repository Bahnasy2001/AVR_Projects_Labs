/*
 * main.c
 *
 *  Created on: May 22, 2024
 *      Author: Hassan Bahnasy
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "TIMERS_interface.h"

int main(void)
{
	DIO_voidInit();
	TIMERS_voidTimer1Init();
	while(1)
	{

	}
	return 0;
}
