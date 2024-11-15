/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 12/4/2024       *************************/
/*************************      SWC: GI             *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GI_interface.h"
#include "GI_private.h"
#include "GI_config.h"

void GI_voidEnableGI(void)
{
	SET_BIT(GI_u8_SREG,7);
}

void GI_voidDisableGI(void)
{
	CLR_BIT(GI_u8_SREG,7);
}