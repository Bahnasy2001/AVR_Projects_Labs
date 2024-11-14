/*
 * main.c
 *
 *  Created on: Feb 12, 2024
 *      Author: Hassan Bahnasy
 */

#include <avr/io.h>
#include <util/delay.h>

#define SSD1_PORT PORTB
#define SSD2_PORT PORTC
//Functions
void Init();
void Display_digit(unsigned int digit,unsigned int ssd);
void CountUp(unsigned char ssd);
void CountDown();
//Global Variables
unsigned int units;
unsigned int tens;
unsigned int number;
int main()
{
	//Initialization
	Init();
	Display_digit(0,1);
	Display_digit(0,2);
	//SuperLoop
	while(1)
	{
		if((!(PIND & (1<<6))) && (PIND & (1<<7))) // Switch 1 is pressed
		{
			CountUp(1);

		}
		if((!(PIND & (1<<7))) && (PIND & (1<<6))) // Switch 2 is pressed
		{
			CountUp(2);

		}
		if(!(PIND & (1<<6)) && !(PIND & (1<<7))) // both Switches are pressed
		{
			CountDown();
		}

	}
	return 0;
}

void Init()
{
	DDRB = 0xff; //SSD 1 output
	DDRC = 0xff; //SSD 2 output
	DDRD = 0x03; //SSD output but Two Switches input
	PORTD |= (1<<1) & (1<<0); // Disable Both SSDs
}
void Display_digit(unsigned int digit,unsigned int ssd)
{

	// Array for 7-segment display patterns
	unsigned int display_pattern[10] = {
			0b00111111, // 0
			0b00000110, // 1
			0b01011011, // 2
			0b01001111, // 3
			0b01100110, // 4
			0b01101101, // 5
			0b01111101, // 6
			0b00000111, // 7
			0b01111111, // 8
			0b01101111  // 9
	};
	if(ssd == 1)
	{
		PORTD &=~(1<<0); //Enable  SSD1
		SSD1_PORT = display_pattern[digit];
	}
	else if(ssd == 2)
	{
		PORTD &=~(1<<1); //Enable  SSD2
		SSD2_PORT = display_pattern[digit];
	}
	else
	{
		//error handling
	}



}
void CountUp(unsigned char ssd)
{
	if(ssd == 1)
	{
		_delay_ms(1000);
		units++;
		if(units > 9)
		{
			units = 0;
		}

		Display_digit(units,1);
	}
	else if(ssd == 2)
	{
		_delay_ms(1000);
		tens++;
		if(tens > 9)
		{

			tens = 0;
		}

		Display_digit(tens,2);
	}
	else
	{
		//error handling
	}
}

void CountDown()
{
	number = (10*tens) + units;
	unsigned int i;
	if(number != 0)
	{
		for(i = number;i >= 0; i--)
		{
			Display_digit(i%10,1);
			Display_digit(i/10,2);
			_delay_ms(1000);
			if(i==0)
			{
				break;
			}
		}
	}
	else
	{
		//error handling
	}
}
