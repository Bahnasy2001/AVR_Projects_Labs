/*
 * main.c
 *
 *  Created on: Jul 22, 2024
 *      Author: Hassan Bahnasy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU  8000000UL
#include <util/delay.h>
#include <string.h>

#include "DIO_interface.h"
#include "UART_interface.h"

#include "MQTT.h"

int main(void)
{
	u8 * Local_u8str = "Hello From AVR";
	DIO_voidInit();
	UART_voidInit();
	MQTT_Connect((u8*)"Bahnasy",(u8*)"GP_28",(u8*)"bahnasy",(u8*)"test",(u8*)"Bahnasy");
	_delay_ms(1000);
//	MQTT_Publish((u8*)"Bahnasy","I Love Zamalek",14,1);
	MQTT_Subscribe((u8*)"test");
	_delay_ms(1000);
	while(1)
	{

//		MQTT_Publish((u8*)"Test",Local_u8str,strlen(Local_u8str),1);
		_delay_ms(10000);
	}
	return 0;
}
