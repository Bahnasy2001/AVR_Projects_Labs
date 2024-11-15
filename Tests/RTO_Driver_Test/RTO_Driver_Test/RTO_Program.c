/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 24/7/2024       *************************/
/*************************      SWC: RTO            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "TIMERS_interface.h"
/* RTO */
#include "RTO_interface.h"
#include "RTO_config.h"
#include "RTO_private.h"

/* Array of TCBs */
RTO_TCB RTO_AstrTasks[RTO_u8_MAX_NUMBER_TASKS];

void RTO_voidInit(void)
{
	/* Set Call Back Function */
	TIMERS_u8Timer0CTCSetCallBack(&RTO_voidScheduler);
	/* Start timer */
	TIMERS_voidTimer0Init();
}

u8 RTO_u8CreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, u16 Copy_u16FirstDelay, void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if((Copy_u8Priority < RTO_u8_MAX_NUMBER_TASKS) && (Copy_pf != NULL))
	{
		RTO_AstrTasks[Copy_u8Priority].FirstDelay = Copy_u16FirstDelay;
		RTO_AstrTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
		RTO_AstrTasks[Copy_u8Priority].pf = Copy_pf;
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;
}

static void RTO_voidScheduler(void)
{
	u8 Local_u8Counter;
	/* For Loop To Loop on The Ready Tasks */
	for(Local_u8Counter = 0;Local_u8Counter < RTO_u8_MAX_NUMBER_TASKS;Local_u8Counter++)
	{
		if(RTO_AstrTasks[Local_u8Counter].FirstDelay == 0)
		{
			/* Call Task */
			RTO_AstrTasks[Local_u8Counter].pf();
			/* Update The First Delay Value  by The Periodicity */
			RTO_AstrTasks[Local_u8Counter].FirstDelay = RTO_AstrTasks[Local_u8Counter].Periodicity - 1;
		}
		else
		{
			RTO_AstrTasks[Local_u8Counter].FirstDelay--;
		}
	}
}