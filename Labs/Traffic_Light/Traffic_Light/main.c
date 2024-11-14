/*
 * main.c
 *
 *  Created on: Feb 7, 2024
 *      Author: Hassan Bahnasy
 */
#include <avr/io.h>
#include <util/delay.h>

void init_Ports(void);
void display_number(unsigned int number);

int main()
{
	//Initialization
	init_Ports();
	unsigned int i;
	//Super Loop
	while(1)
	{
		//Green Light
		PORTB = 0b00000100; // Green LED ON, Red and Yellow OFF
		for(i = 15; i > 0; i--)
		{
			display_number(i);
			_delay_ms(1000);
		}

		//Yellow Light
		PORTB = 0b00000010; // Yellow LED ON, Red and Green OFF
		for(i = 3; i > 0; i--)
		{
			display_number(i);
			_delay_ms(1000);
		}
		//Red Light
		PORTB = 0b00000001; // Red LED ON, Green and Yellow OFF
		for(i = 10; i > 0; i--)
		{
			display_number(i);
			_delay_ms(1000);
		}

	}
	return 0;
}

void init_Ports()
{
	// Set PORTB as output for LEDs
	DDRB = 0xFF;
	// Set PORTC as output for 7-segment displays
	DDRC = 0xFF;
	// Set PORTD as output for 7-segment displays
	DDRD = 0xFF;
}

void display_number(unsigned int number)
{
	// Array for 7-segment display patterns
	unsigned int display_pattern[10] = {
			0b00111111, //0
			0b00000110, //1
			0b01011011, // 2
			0b01001111, // 3
			0b01100110, // 4
			0b01101101, // 5
			0b01111101, // 6
			0b00000111, // 7
			0b01111111, // 8
			0b01101111  // 9
	};
	// Extract tens and units digits
	unsigned int tens = number / 10;
	unsigned int units = number % 10;
	// Disable Both 7-segment display
	PORTB &= 0b00111111;
	// Display tens digit on first 7-segment display
	PORTC = display_pattern[tens];
	// Enable first 7-segment display
	PORTB |= (1<<PB7);
	_delay_ms(5);
	// Disable first 7-segment display
	PORTB &= ~(1<<PB7);

	// Display units digit on second 7-segment display
	PORTD = display_pattern[units];
	// Enable second 7-segment display
	PORTB |= (1<<PB6);
	_delay_ms(5);
	// Disable second 7-segment display
	PORTB &= ~(1<<PB6);
}
