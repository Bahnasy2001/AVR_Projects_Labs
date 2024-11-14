/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 22/5/2024       *************************/
/*************************      SWC: SERVO          *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <math.h>
#include "TIMERS_interface.h"

#include "SERVO_interface.h"
#include "SERVO_config.h"
#include "SERVO_private.h"


void SERVO_voidInit(void)
{
	TIMERS_voidTimer1Init();
}
void SERVO_voidRotate(u8 Copy_u8Angle)
{
	u16 OCRValue;
	OCRValue = 999 + ceil((f64)(Copy_u8Angle * (1000.0/180.0)));
	TIMERS_voidTimer1SetCompareMatchValueUnitA(OCRValue);
}

