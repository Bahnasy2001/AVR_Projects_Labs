/*
 * main.c
 *
 *  Created on: Jul 25, 2024
 *      Author: Hassan Bahnasy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*MCAL*/
#include "DIO_interface.h"

#include "FreeRTOS.h"
#include "task.h"

void App_voidRedTask(void * Copy_pv);
void App_voidGreenTask(void * Copy_pv);
void App_voidBlueTask(void * Copy_pv);

#define RED_TASK_PRIORITY           4
#define GREEN_TASK_PRIORITY         3
#define BLUE_TASK_PRIORITY          1


int main(void)
{
	DIO_voidInit();
	/* Create Tasks */
	xTaskCreate(&App_voidRedTask,NULL,200,NULL,RED_TASK_PRIORITY,NULL);
	xTaskCreate(&App_voidGreenTask,NULL,200,NULL,GREEN_TASK_PRIORITY,NULL);
	xTaskCreate(&App_voidBlueTask,NULL,200,NULL,BLUE_TASK_PRIORITY,NULL);

	/* Start Scheduler */
	vTaskStartScheduler();

	while(1);

	return 0;
}

void App_voidRedTask(void * Copy_pv)
{
	static u8 Local_u8Falg = 0;
	while(1)
	{
		if(Local_u8Falg == 0)
		{
			DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
			Local_u8Falg = 1;
		}
		else
		{
			DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
			Local_u8Falg = 0;
		}
		vTaskDelay(1000);
	}
}
void App_voidGreenTask(void * Copy_pv)
{
	static u8 Local_u8Falg = 0;
	while(1)
	{
		if(Local_u8Falg == 0)
		{
			DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
			Local_u8Falg = 1;
		}
		else
		{
			DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_LOW);
			Local_u8Falg = 0;
		}
		vTaskDelay(2000);
	}
}
void App_voidBlueTask(void * Copy_pv)
{
	static u8 Local_u8Falg = 0;
	while(1)
	{
		if(Local_u8Falg == 0)
		{
			DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
			Local_u8Falg = 1;
		}
		else
		{
			DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_LOW);
			Local_u8Falg = 0;
		}
		vTaskDelay(4000);
	}
}
