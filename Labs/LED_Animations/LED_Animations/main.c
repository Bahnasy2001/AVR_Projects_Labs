/*
 * main.c
 *
 *  Created on: Feb 22, 2024
 *      Author: Hassan Bahnasy
 */
#include <avr/io.h>
#include <util/delay.h>
/**********MACROS FOR PORTS*********/
#define LED_PORT PORTD
#define DIP_PIN  PINB
#define DIP_SW1 ((PINB >> 0)&1)
#define DIP_SW2 ((PINB >> 1)&1)
#define DIP_SW3 ((PINB >> 2)&1)
/***********************************/
/**********MACROS FOR DELAYS*********/
#define FLASHING_DELAY 500
#define SHIFT_DELAY 250
#define CONVERGE_DIVERGE_DELAY 300
#define PING_PONG_DELAY 250
#define SNAKE_DELAY 300
/***********************************/
/**********APIs********************/
void Init();
int get_DIP_val();
void FlashingAnimation();
void ShiftLeftAnimation();
void ShiftRightAnimation();
void ConvergingAnimation();
void DivergingAnimation();
void PingPongAnimation();
void SnakeAnimation();
/***********************************/
unsigned char DIP_VALUE;
int main()
{
	//Initialization
	Init();
	//Super loop
	while(1)
	{
		switch(get_DIP_val())
		{
		case 0:
			PORTD = 0x00;
			break;
		case 1:
			FlashingAnimation();
			break;
		case 2:
			ShiftLeftAnimation();
			break;
		case 3:
			ShiftRightAnimation();
			break;
		case 4:
			ConvergingAnimation();
			break;
		case 5:
			DivergingAnimation();
			break;
		case 6:
			PingPongAnimation();
			break;
		case 7:
			SnakeAnimation();
			break;
		}

	}
	return 0;
}

void Init()
{
	DDRD = 0xFF; //Set PORTD as output
	PORTD = 0x00; //Initialize PORTD with all LEDs off
	DDRB = 0x00; //Set PORTB as input
	PORTB = 0x00; //Disable pull up resistor

}
int get_DIP_val()
{
	if((DIP_SW1) && (!DIP_SW2) && (!DIP_SW3))
	{
		return DIP_VALUE = 1;
	}
	else if((!DIP_SW1) && (DIP_SW2) && (!DIP_SW3))
	{
		return DIP_VALUE = 2;
	}
	else if((DIP_SW1) && (DIP_SW2) && (!DIP_SW3))
	{
		return DIP_VALUE = 3;
	}
	else if((!DIP_SW1) && (!DIP_SW2) && (DIP_SW3))
	{
		return DIP_VALUE = 4;
	}
	else if((DIP_SW1) && (!DIP_SW2) && (DIP_SW3))
	{
		return DIP_VALUE = 5;
	}
	else if((!DIP_SW1) && (DIP_SW2) && (DIP_SW3))
	{
		return DIP_VALUE = 6;
	}
	else if((DIP_SW1) && (DIP_SW2) && (DIP_SW3))
	{
		return DIP_VALUE = 7;
	}
	else
	{
		return DIP_VALUE = 0;
	}
	return DIP_VALUE;
}
void FlashingAnimation()
{
	LED_PORT = 0x00;
	while (get_DIP_val() == 1) // Loop until DIP switch 1 is activated
	{
		LED_PORT ^= 0xFF; // Toggle all LEDs
		_delay_ms(FLASHING_DELAY);
	}
}
void ShiftLeftAnimation()
{
	LED_PORT = 0x01; // Initialize LEDs with one LED on
	unsigned char i;
	unsigned char Animation[8]=
	{
			0b00000001,
			0b00000010,
			0b00000100,
			0b00001000,
			0b00010000,
			0b00100000,
			0b01000000,
			0b10000000
	};
	while (get_DIP_val() == 2)
	{ // Loop until DIP switch 2 is activated
		for(i = 0; i < 8 ; i++)
		{
		LED_PORT = Animation[i]; // Shift left
		_delay_ms(SHIFT_DELAY);
		}
	}
}
void ShiftRightAnimation()
{
	LED_PORT = 0x80; // Initialize LEDs with one LED on
	unsigned char i;
	unsigned char Animation[8]=
	{
			0b10000000,
			0b01000000,
			0b00100000,
			0b00010000,
			0b00001000,
			0b00000100,
			0b00000010,
			0b00000001
	};
	while (get_DIP_val() == 3)
	{// Loop until DIP switches 1 and 2 are activated
		for(i = 0;i < 8; i++)
		{
			LED_PORT = Animation[i]; ; // Shift right
			_delay_ms(SHIFT_DELAY);
		}
	}
}
void ConvergingAnimation()
{
	LED_PORT = 0x00;// Initialize LEDs off
	unsigned char i;
	while (get_DIP_val() == 4)
	{// Loop until DIP switch 3 are activated
		for (i = 0; i < 4; ++i)
		{
			LED_PORT |= ((1<<i) | (1<<(7-i)));
			_delay_ms(CONVERGE_DIVERGE_DELAY);
			LED_PORT = 0x00;
		}
	}

}
void DivergingAnimation()
{
	LED_PORT = 0x18; // Initialize LEDs with two middle LEDs on
	signed char i;
	    while (get_DIP_val() == 5) {
	    	// Loop until DIP switches 1 and 3 are activated
			for (i = 3; i >= 0 ; --i)
			{
				LED_PORT |= ((1<<i) | (1<<(7-i)));
				_delay_ms(CONVERGE_DIVERGE_DELAY);
				LED_PORT = 0x00;
			}
	    }
}
void PingPongAnimation()
{
    LED_PORT = 0x01; // Initialize LEDs with one LED on
    while (get_DIP_val() == 6)
    { // Loop until DIP switches 2 and 3 are activated
        LED_PORT = (LED_PORT << 1) ^ (LED_PORT >> 6); // Ping-pong effect
        _delay_ms(PING_PONG_DELAY);
    }
}
void SnakeAnimation()
{
    //LED_PORT = 0x01; // Initialize LEDs with one LED on
    while (get_DIP_val() == 7)
    { // Loop until all DIP switches are activated
    	LED_PORT = 0x01;// Initialize LEDs with one LED on in loop to save first led on
        for (int i = 0; i < 8; i++) {
            LED_PORT |= (1<<i) ; // Incrementing (snake effect)
            _delay_ms(SNAKE_DELAY);
        }
    }
}
