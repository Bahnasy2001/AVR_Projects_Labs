/*
 * Dashboard.c
 *
 *  Created on: Mar 22, 2024
 *      Author: Hassan Bahnasy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "KPD_interface.h"
#include "LCD_interface.h"
#include "H_Bridge.h"
#include "Login_System.h"
#include "STEPPER_interface.h"
#include "SERVO_interface.h"
#include "TIMERS_interface.h"

u8 Local_u8Ind = 0;
u8 Local_Au8digits[6] = {0};
u8 Local_Au8digitsServo[6] = {0};
void Dashboard_FrameOne(void)
{
	u8 Local_u8Key;

	LCD_voidClearScreen();
	_delay_ms(20);
	LCD_voidWriteString((u8*)" Choose Type of ");
	LCD_u8GoToXY(LCD_u8_LINE2,7);
	LCD_voidWriteString((u8*)" Motor ");
	_delay_ms(1000);
	LCD_voidClearScreen();
	_delay_ms(20);
	LCD_voidWriteString((u8*)"1-DC");
	LCD_u8GoToXY(LCD_u8_LINE2,0);
	LCD_voidWriteString((u8*)"2-Stepper");
	LCD_u8GoToXY(LCD_u8_LINE1,9);
	LCD_voidWriteString((u8*)"3-Servo");
	LCD_u8GoToXY(LCD_u8_LINE2,9);
	LCD_voidWriteString((u8*)"4-Exit");

	while(1)
	{
		KPD_u8GetKeyState(&Local_u8Key); // Get state of pressed key
		if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED) // If a key is pressed
		{
			if(Local_u8Key == '1') // If pressed key is '1'
			{
				Dashboard_FrameTwo();
			}
			else if(Local_u8Key == '2') // If pressed key is '2'
			{
				Dashboard_FrameThree();
			}
			else if(Local_u8Key == '3') // If pressed key is '3'
			{
				Dashboard_FrameSix();
			}
			else if (Local_u8Key == '4') // If pressed key is '2'
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteString((u8*)"GoodLuck!");
				_delay_ms(3000);
				while(1)
				{

				}
			}
			else
			{
				//error handling
			}
		}
	}
}
void Dashboard_FrameTwo(void)
{
	u8 Local_u8Key;
	u8 Local_Angle;
	LCD_voidClearScreen();
	_delay_ms(20);
	LCD_voidWriteString((u8*)"1-RotateCW");
	LCD_u8GoToXY(LCD_u8_LINE2,0);
	LCD_voidWriteString((u8*)"2-RotateCCW");
	LCD_u8GoToXY(LCD_u8_LINE1,10);
	LCD_voidWriteString((u8*)"3-Back");
	while(1)
	{
		KPD_u8GetKeyState(&Local_u8Key); // Get state of pressed key
		if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED) // If a key is pressed
		{
			if(Local_u8Key == '1') // If pressed key is '1'
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteString((u8*)" Rotate CW ....");
				H_BRIDGE_voidRotateCW();
				_delay_ms(5000);
				while(1);
			}
			else if (Local_u8Key == '2') // If pressed key is '2'
			{
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteString((u8*)" Rotate CCW ....");
				H_BRIDGE_voidRotateCCW();
				_delay_ms(5000);
				while(1);
			}
			else if(Local_u8Key == '3' ) // If pressed key is '3'
			{
				Dashboard_FrameOne();
			}
			else
			{
				//error handling
			}
		}
	}

}

void Dashboard_FrameThree()
{
	u8 Local_u8Key;
	LCD_voidClearScreen();
	_delay_ms(20);
	LCD_voidWriteString((u8*)"1-RotateCW");
	LCD_u8GoToXY(LCD_u8_LINE2,0);
	LCD_voidWriteString((u8*)"2-RotateCCW");
	LCD_u8GoToXY(LCD_u8_LINE1,10);
	LCD_voidWriteString((u8*)"3-Back");
	while(1)
	{
		KPD_u8GetKeyState(&Local_u8Key); // Get state of pressed key
		if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED)// If a key is pressed
		{
			if(Local_u8Key == '1') // If pressed key is '1' CW
			{
				Dashboard_FrameFour();
			}
			else if(Local_u8Key == '2') // If pressed key is '2' CCW
			{
				Dashboard_FrameFive();
			}
			else if (Local_u8Key == '3')
			{
				Dashboard_FrameOne();
			}
			else
			{
				//error handling
			}
		}
	}
}
void Dashboard_FrameFour(void)
{
	u8 Local_u8Key;
	u16 Local_u16Angle;
	LCD_voidClearScreen();
	_delay_ms(20);
	LCD_voidWriteString((u8*)"Angle = ");
	while(1)
	{
		KPD_u8GetKeyState(&Local_u8Key);
		if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED)// If a key is pressed
		{
			if(Local_u8Key == '=') // If pressed key is '='
			{
				GetNumber((u8*)Local_Au8digits,&Local_u16Angle);
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteString((u8*)" Rotate CW ....");
				STEPPER_u8Move(STEPPER_u8_CW,Local_u16Angle);
				break;
			}
			else
			{
				addToBuffer((u8*)Local_Au8digits,Local_u8Key); // Append pressed key to buffer
				LCD_voidSendChar(Local_u8Key); // Display pressed key on LCD
			}
		}
	}

}
void Dashboard_FrameFive(void)
{
	u8 Local_u8Key;
	u16 Local_u16Angle;
	LCD_voidClearScreen();
	_delay_ms(20);
	LCD_voidWriteString((u8*)"Angle = ");
	while(1)
	{
		KPD_u8GetKeyState(&Local_u8Key);
		if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED)// If a key is pressed
		{
			if(Local_u8Key == '=') // If pressed key is '='
			{
				GetNumber(Local_Au8digits,&Local_u16Angle);
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteString((u8*)" Rotate CCW ....");
				STEPPER_u8Move(STEPPER_u8_CCW,Local_u16Angle);

				break;
			}
			else
			{
				addToBuffer((u8*)Local_Au8digits,Local_u8Key); // Append pressed key to buffer
				LCD_voidSendChar(Local_u8Key); // Display pressed key on LCD
			}
		}
	}
}
void Dashboard_FrameSix(void)
{
	u8 Local_u8Key;
	u16 Local_u16Angle;
	SERVO_voidInit();
	LCD_voidClearScreen();
	_delay_ms(20);
	LCD_voidWriteString((u8*)"Angle = ");
	SERVO_voidInit();
	while(1)
	{
		KPD_u8GetKeyState(&Local_u8Key);
		if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED)// If a key is pressed
		{
			if(Local_u8Key == '=') // If pressed key is '='
			{
				GetNumber(Local_Au8digitsServo,&Local_u16Angle);
				LCD_voidClearScreen();
				_delay_ms(20);
				LCD_voidWriteString((u8*)"Servo Rotate ... ");
				SERVO_voidRotate(Local_u16Angle);
				break;
			}
			else
			{
				addToBuffer((u8*)Local_Au8digitsServo,Local_u8Key); // Append pressed key to buffer
				LCD_voidSendChar(Local_u8Key); // Display pressed key on LCD
			}
		}
	}
}
void GetNumber(u8 *buffer,u16 *result)
{
	u16 num = 0;// Variable to store current number
	u8 i = 0;
	while(*(buffer+i) != '\0') // Loop until end of buffer is reached
	{
		if (buffer[i] >= '0' && buffer[i] <= '9')
		{
			// Build the number digit by digit
			num = num * 10 + (buffer[i] - '0');
		}
		i++;
	}
	*result = num;
}
void addToBuffer(u8 *buffer,u8 key)
{
	if(Local_u8Ind < 5) // Make sure buffer index is within range
	{
		*(buffer+Local_u8Ind) = key; // Store the character in buffer
		Local_u8Ind++; // Increment buffer index
		*(buffer+Local_u8Ind) = '\0';// Null-terminate buffer
	}
}
