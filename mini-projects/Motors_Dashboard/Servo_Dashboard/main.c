/*
 * main.c
 *
 *  Created on: Jun 10, 2024
 *      Author: Hassan Bahnasy
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

/* MCAL Layer */
#include "DIO_interface.h"
#include "TIMERS_interface.h"
/* HAL Layer */
#include "LCD_interface.h"
#include "KPD_interface.h"
#include "SERVO_interface.h"
#include "STEPPER_interface.h"
/*Services Layer*/
#include "Login_System.h"
#include "H_Bridge.h"
#include "Dashboard.h"

int main(void)
{
	u8 const password[] = "1234";
	u8 flag;//To check login correct or wrong
	DIO_voidInit();
	LCD_voidInit();
	while(1)
	{
		login_system(password,&flag);
		if(flag)
		{
			_delay_ms(1000);
			LCD_voidClearScreen();
			_delay_ms(20);
			LCD_voidWriteString((u8*)"Welcome To Motor");
			LCD_u8GoToXY(LCD_u8_LINE2,0);
			LCD_voidWriteString((u8*)"Dashboard");
			_delay_ms(3000);
			Dashboard_FrameOne();
			while(1)
			{
			}
		}
		else
		{
			_delay_ms(1000);
			LCD_voidClearScreen();
			_delay_ms(20);
			LCD_voidWriteString((u8*)"GoodLuck!");
			_delay_ms(3000);
			while(1)
			{

			}
		}
	}
	return 0;
}
