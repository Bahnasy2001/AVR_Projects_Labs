/*
 * main.c
 *
 *  Created on: Apr 12, 2024
 *      Author: Hassan Bahnasy
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "GI_interface.h"


//#define  SREG         *((volatile u8*)0x5F)
void Tog_Led(void);

int main(void)
{
	DIO_voidInit();
	/* Enable Global Interrupt */
	GI_voidEnableGI();
	/* Set CallBack Function */
	EXTI_u8EXTISetCallBack(EXTI_u8_INT0,&Tog_Led);
	/* Enable EXTI0  */
	EXTI_u8EXTIEnable(EXTI_u8_INT0,EXTI_u8_ANY_LOGICAL_CHANGE);
	while(1);
	return 0;
}
/* Prototype for ISR of EXTI0 */


void Tog_Led(void)
{
	static u8 Local_u8Flag = 0;
	if(Local_u8Flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		Local_u8Flag = 1;
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
		Local_u8Flag = 0;
	}
}

/* Prototype for ISR of EXTI0 */
/*
void __vector_1(void)    __attribute__((signal));
void __vector_1(void)
{
	static u8 Local_u8Flag = 0;
	if(Local_u8Flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		Local_u8Flag = 1;
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
		Local_u8Flag = 0;
	}
}
*/
