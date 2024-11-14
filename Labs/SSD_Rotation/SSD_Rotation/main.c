/*
 * main.c
 *
 *  Created on: Feb 12, 2024
 *      Author: Hassan Bahnasy
 */


#include <avr/io.h>
#include <util/delay.h>
#define SSD_PORT PORTC
#define a 0x01
#define b 0x02
#define c 0x04
#define d 0x08
#define e 0x10
#define f 0x20
#define off 0x00

void Init();
void SSD_display(unsigned char segment1,unsigned char segment2);
void Rotate_Right();
void Rotate_Left();
int main()
{
	Init();
	while(1)
	{
		if(!(PIND & (1<<6))) //Switch 1 is pressed (Rotate Right)
		{
			Rotate_Right();
		}
		else if(!(PIND & (1<<7))) //Switch 2 is pressed (Rotate Left)
		{
			Rotate_Left();
		}
		else
		{
			//error handling
		}
		_delay_ms(10);
	}
	return 0;

}

void Init()
{
	DDRC = 0xff; //SSD is output

	DDRD = 0x03; //Switches is input and Enable SSD is output
}

void SSD_display(unsigned char segment1,unsigned char segment2)
{
	PORTD |= (1<<0) & (1<<1);//Disable SSD 1 & SSD 2
	SSD_PORT = segment1;
	PORTD &=~(1<<0); //Enable SSD 1
	_delay_ms(100);
	PORTD |=(1<<0); //Disable SSD 1
	SSD_PORT = segment2;
	PORTD &=~(1<<1); //Enable SSD 2
	_delay_ms(100);
	PORTD |=(1<<1);
}
void Rotate_Right()
{
	SSD_display(off,off);
	_delay_ms(100);
	SSD_display(d,off);
	_delay_ms(100);
	SSD_display(c,off);
	_delay_ms(100);
	SSD_display(b,off);
	_delay_ms(100);
	SSD_display(a,off);
	_delay_ms(100);
	SSD_display(off,a);
	_delay_ms(100);
	SSD_display(off,f);
	_delay_ms(100);
	SSD_display(off,e);
	_delay_ms(100);
	SSD_display(off,d);
	_delay_ms(100);
}
void Rotate_Left()
{
	SSD_display(off,off);
	_delay_ms(100);
	SSD_display(d,off);
	_delay_ms(100);
	SSD_display(off,d);
	_delay_ms(100);
	SSD_display(off,e);
	_delay_ms(100);
	SSD_display(off,f);
	_delay_ms(100);
	SSD_display(off,a);
	_delay_ms(100);
	SSD_display(a,off);
	_delay_ms(100);
	SSD_display(b,off);
	_delay_ms(100);
	SSD_display(c,off);
	_delay_ms(100);
}
