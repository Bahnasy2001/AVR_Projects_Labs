/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 7/6/2024        *************************/
/*************************      SWC: WDT            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "WDT_interface.h"
#include "WDT_config.h"
#include "WDT_private.h"

void WDT_voidEnable(void)
{
	SET_BIT(WDT_u8_WDTCR_REG,3);
#if WDT_u8_PRESCALER == WDT_u8_PRESCALER_16
	/* Set Prescaler Value */
	CLR_BIT(WDT_u8_WDTCR_REG,2);
	CLR_BIT(WDT_u8_WDTCR_REG,1);
	CLR_BIT(WDT_u8_WDTCR_REG,0);
#elif WDT_u8_PRESCALER == WDT_u8_PRESCALER_32
	/* Set Prescaler Value */
	CLR_BIT(WDT_u8_WDTCR_REG,2);
	CLR_BIT(WDT_u8_WDTCR_REG,1);
	SET_BIT(WDT_u8_WDTCR_REG,0);
#elif WDT_u8_PRESCALER == WDT_u8_PRESCALER_64
	/* Set Prescaler Value */
	CLR_BIT(WDT_u8_WDTCR_REG,2);
	SET_BIT(WDT_u8_WDTCR_REG,1);
	CLR_BIT(WDT_u8_WDTCR_REG,0);
#elif WDT_u8_PRESCALER == WDT_u8_PRESCALER_128
	/* Set Prescaler Value */
	CLR_BIT(WDT_u8_WDTCR_REG,2);
	SET_BIT(WDT_u8_WDTCR_REG,1);
	SET_BIT(WDT_u8_WDTCR_REG,0);
#elif WDT_u8_PRESCALER == WDT_u8_PRESCALER_256
	/* Set Prescaler Value */
	SET_BIT(WDT_u8_WDTCR_REG,2);
	CLR_BIT(WDT_u8_WDTCR_REG,1);
	CLR_BIT(WDT_u8_WDTCR_REG,0);
#elif WDT_u8_PRESCALER == WDT_u8_PRESCALER_512
	/* Set Prescaler Value */
	SET_BIT(WDT_u8_WDTCR_REG,2);
	CLR_BIT(WDT_u8_WDTCR_REG,1);
	SET_BIT(WDT_u8_WDTCR_REG,0);
#elif WDT_u8_PRESCALER == WDT_u8_PRESCALER_1024
	/* Set Prescaler Value */
	SET_BIT(WDT_u8_WDTCR_REG,2);
	SET_BIT(WDT_u8_WDTCR_REG,1);
	CLR_BIT(WDT_u8_WDTCR_REG,0);
#elif WDT_u8_PRESCALER == WDT_u8_PRESCALER_2048
	/* Set Prescaler Value */
	SET_BIT(WDT_u8_WDTCR_REG,2);
	SET_BIT(WDT_u8_WDTCR_REG,1);
	SET_BIT(WDT_u8_WDTCR_REG,0);
#endif
}

void WDT_voidDisable(void)
{
	/* Write logical one to WDTOE and WDE */
	WDT_u8_WDTCR_REG |= (1<<4) | (1<<3);
	/* Turn off WDT */
	WDT_u8_WDTCR_REG = 0x00;
}
