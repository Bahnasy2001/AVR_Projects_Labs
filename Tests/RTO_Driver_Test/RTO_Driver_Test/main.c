/*
 * main.c
 *
 *  Created on: Jul 24, 2024
 *      Author: Hassan Bahnasy
 */
/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU   8000000UL
#include <util/delay.h>

/* MCAL Layer */
#include "DIO_interface.h"
#include "GI_interface.h"
#include "TIMERS_interface.h"

/* Service Layer */
#include "RTO_interface.h"


void App_TaskOne(void);
void App_TaskTwo(void);
void App_TaskThree(void);


int main(void)
{
	DIO_voidInit();

	GI_voidEnableGI();

	/* Create Tasks */
	RTO_u8CreateTask(0,1000,6000,&App_TaskOne);
	RTO_u8CreateTask(1,2000,0,&App_TaskTwo);
	RTO_u8CreateTask(2,5000,0,&App_TaskThree);

	RTO_voidInit();
	while(1);
	return 0;
}
void App_TaskOne(void)
{
	static u8 Local_u8Flag = 0;
	if(Local_u8Flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		Local_u8Flag = 1;
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
		Local_u8Flag = 0;
	}
}

void App_TaskTwo(void)
{
	static u8 Local_u8Flag = 0;
	if(Local_u8Flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
		Local_u8Flag = 1;
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_LOW);
		Local_u8Flag = 0;
	}
}
void App_TaskThree(void)
{
	static u8 Local_u8Flag = 0;
	if(Local_u8Flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
		Local_u8Flag = 1;
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_LOW);
		Local_u8Flag = 0;
	}
}
