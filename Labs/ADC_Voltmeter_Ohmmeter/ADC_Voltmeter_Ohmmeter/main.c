/*
 * main.c
 *
 *  Created on: May 2, 2024
 *      Author: Hassan Bahnasy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU      8000000UL
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#include "DIO_interface.h"
#include "LCD_interface.h"
#include "ADC_interface.h"

void FloatToString(float num, char *buffer, int decimal_places,int width)
{
	dtostrf(num,width,decimal_places,buffer);
}

int main()
{
	u16 Local_u16DigitalValue,Local_u16AnalogValue;
	f32 Local_f32PreviousVoltmeterValue= 0xFFFF,Local_f32PreviousOhmmeterValue=0xFFFF;
	f32 Local_f32VoltmeterValue,Local_f32OhmmeterValue;
	u8 buffer[20];
	DIO_voidInit();
	LCD_voidInit();
	ADC_voidInit();
	while(1)
	{
		// Read ADC value from Channel 0 (Voltmeter)
		ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_0,&Local_u16DigitalValue);
		Local_u16AnalogValue = ((u32)(Local_u16DigitalValue * 5000UL)/1024);
		Local_f32VoltmeterValue = ((Local_u16AnalogValue) / 5000.0) * 25.0;
		// Check if the voltmeter value has changed significantly
		if ((Local_f32VoltmeterValue - Local_f32PreviousVoltmeterValue) > 0.01 || (Local_f32PreviousVoltmeterValue - Local_f32VoltmeterValue) > 0.01)
		{
			// Update the LCD display with the new voltmeter value
			LCD_voidClearScreen();
			FloatToString(Local_f32VoltmeterValue, buffer, 2,4);
//			dtostrf(Local_f32VoltmeterValue,4,2,buffer);
			LCD_voidWriteString("Voltmeter:");
			LCD_voidWriteString(buffer);
			LCD_voidWriteString("V");
			Local_f32PreviousVoltmeterValue = Local_f32VoltmeterValue; // Update previous voltmeter value
		}
		// Read ADC value from Channel 0 (Ohmmeter)
		ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_0, &Local_u16DigitalValue);
		Local_u16AnalogValue = (u16)((Local_u16DigitalValue * 5000UL) / 1024);
		Local_f32OhmmeterValue = (Local_u16AnalogValue/5000.0) *1000.0;
		// Check if the ohmmeter value has changed significantly
		if ((Local_f32OhmmeterValue - Local_f32PreviousOhmmeterValue) > 1 || (Local_f32PreviousOhmmeterValue - Local_f32OhmmeterValue) > 1)
		{
			// Update the LCD display with the new ohmmeter value
			LCD_u8GoToXY(LCD_u8_LINE2, 0);
			LCD_voidWriteString("Ohmmeter:");
			LCD_voidWriteNumber(Local_f32OhmmeterValue);
			LCD_voidWriteString(" Ohm");
			Local_f32PreviousOhmmeterValue = Local_f32OhmmeterValue; // Update previous ohmmeter value
		}

		// Delay to allow time for human observation
		_delay_ms(500);
	}

	return 0;
}
