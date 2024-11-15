/*
 * main.c
 *
 *  Created on: Jul 25, 2024
 *      Author: Hassan Bahnasy
 */
/*LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
/*MCAL*/
#include "DIO_interface.h"

/*HAL*/
#include "LCD_interface.h"

/*Service*/
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

void App_voidLCD1(void * Copy_pv);
void App_voidLCD2(void * Copy_pv);

void App_voidSwitchTask(void * Copy_pv);
void App_voidLedTask(void * Copy_pv);

/* Create Semaphore */
xSemaphoreHandle LCD_Semaphore;

xSemaphoreHandle Switch_Semaphore;

int main(void)
{
	DIO_voidInit();
	LCD_voidInit();
	/* Create Tasks */
	//	xTaskCreate(&App_voidLCD1,NULL,512,NULL,2,NULL);
	//	xTaskCreate(&App_voidLCD2,NULL,512,NULL,4,NULL);
	/* Create Tasks */
	//	if (xTaskCreate(&App_voidLCD1, "LCD1", 200, NULL, 3, NULL) != pdPASS) {
	//		// Handle task creation failure
	//		LCD_voidWriteNumber(1);
	//		while(1);
	//	}
	//	if (xTaskCreate(&App_voidLCD2, "LCD2", 200, NULL, 3, NULL) != pdPASS) {
	//		// Handle task creation failure
	//		LCD_voidWriteNumber(2);
	//		while(1);
	//	}
	xTaskCreate(&App_voidSwitchTask,NULL,200,NULL,2,NULL);
	xTaskCreate(&App_voidLedTask,NULL,200,NULL,1,NULL);

	/* Create Semaphore */
	vSemaphoreCreateBinary(Switch_Semaphore);

	/* Take Semaphore */
	xSemaphoreTake(Switch_Semaphore,portMAX_DELAY);

	//	LCD_Semaphore = xSemaphoreCreateCounting(1,1);

	/* Start Scheduler */
	vTaskStartScheduler();

	while(1);

	return 0;
}

void App_voidLCD1(void * Copy_pv)
{
	while(1)
	{
		/* Take Semaphore */
		if(xSemaphoreTake(LCD_Semaphore,portMAX_DELAY) == pdTRUE)
		{
			LCD_voidWriteString((u8*)"I am TASK 1");
			_delay_ms(800);
			LCD_voidClearScreen();
			xSemaphoreGive(LCD_Semaphore);

			vTaskDelay(1000);

		}

	}
}
void App_voidLCD2(void * Copy_pv)
{
	while(1)
	{
		/* Take Semaphore */
		if(xSemaphoreTake(LCD_Semaphore,portMAX_DELAY) == pdTRUE)
		{
			LCD_voidWriteString((u8*)"I am TASK 2");
			_delay_ms(800);
			LCD_voidClearScreen();
			xSemaphoreGive(LCD_Semaphore);
			vTaskDelay(1000);
		}
	}
}
void App_voidSwitchTask(void * Copy_pv)
{
	u8 Local_u8Key;
	while(1)
	{
		/* Check Switch State */
		DIO_u8GetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,&Local_u8Key);
		if(Local_u8Key == DIO_u8_LOW) // button is pressed
		{
			xSemaphoreGive(Switch_Semaphore);
		}
		vTaskDelay(200);
	}
}
void App_voidLedTask(void * Copy_pv)
{
	static u8 Local_u8Falg = 0;
	while(1)
	{
		/* Take Semaphore */
		if(xSemaphoreTake(Switch_Semaphore,portMAX_DELAY) == pdTRUE)
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
		}
	}
}

