/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 25/3/2024       *************************/
/*************************      SWC: STEPPER        *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/

/* LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU  8000000UL
#include <util/delay.h>

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "STEPPER_interface.h"
#include "STEPPER_config.h"
#include "STEPPER_private.h"

u8 STEPPER_u8Move(u8 direction , u16 angle) // two phase excitation
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	// Step Angle = 0.5 deg so No of steps for full step = 360/0.5 = 720
	u32 Local_u8NoOfiterations = (((u32) angle * 720) / (360 * 4)) ; // ((angle * 720) / (360*4))
	u8 i;
#if STEPPER_u8_MODE == STEPPER_u8_DOUBLE_PHASE
	if(direction == STEPPER_u8_CCW)
	{
		for(i = 0; i < Local_u8NoOfiterations;i++)
		{
			//Step 1 0x03 --> - step angle * 1
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_LOW);
			_delay_ms(100);
			//Step 2 0x06 --> - step angle * 2
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_LOW);
			_delay_ms(100);
			//Step 1 0x0C --> - step angle * 3
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_HIGH);
			_delay_ms(100);
			//Step 4 0x09 --> - step angle * 4
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_HIGH);
			_delay_ms(100);
		}
	}
	else if(direction == STEPPER_u8_CW)
	{
		for(i = 0; i < Local_u8NoOfiterations;i++)
		{
			//Step 1 0x0C --> step angle
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_HIGH);
			_delay_ms(100);
			//Step 2 0x06 --> step angle * 2
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_LOW);
			_delay_ms(100);
			//Step 3 0x03 --> step angle * 3
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_LOW);
			_delay_ms(100);
			//Step 4 0x09 --> step angle * 4
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_HIGH);
			_delay_ms(100);
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
#elif STEPPER_u8_MODE == STEPPER_u8_SINGLE_PHASE
	if(direction == STEPPER_u8_CCW)
	{
		for(i = 0; i < Local_u8NoOfiterations;i++)
		{
			//Step 1 0x02 --> - step angle
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_LOW);
			_delay_ms(100);
			//Step 2 0x04 --> - step angle * 2
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_LOW);
			_delay_ms(100);
			//Step 3 0x08 --> - step angle * 3
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_HIGH);
			_delay_ms(100);
			//Step 4 0x01 --> - step angle * 4
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_LOW);
			_delay_ms(100);
		}
	}
	else if(direction == STEPPER_u8_CW)
	{
		for(i = 0; i < Local_u8NoOfiterations;i++)
		{
			//Step 1 0x04 --> step angle * 1
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_LOW);
			_delay_ms(100);
			//Step 2 0x02 --> step angle * 2
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_LOW);
			_delay_ms(100);
			//Step 3 0x01 --> step angle * 3
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_LOW);
			_delay_ms(100);
			//Step 4 0x08 --> step angle * 4
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_HIGH);
			_delay_ms(100);
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
#endif
	return Local_u8ErrorState;
}
