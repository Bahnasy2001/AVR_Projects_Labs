/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 16/6/2024       *************************/
/*************************      SWC: SWICU          *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef SWICU_INTERFACE_H
#define SWICU_INTERFACE_H

void SWICU_voidEnable(void);

void SWICU_voidDisable(void);

u8   SWICU_u8GetTotalPeriod(u32 * Copy_pu32TotalPeriod);

u8   SWICU_u8GetDutyCycle(u8 * Copy_pu8DutyCycle);

u8   SWICU_u8GetOnPeriod(u16 * Copy_pu16OnPeriod);


#endif