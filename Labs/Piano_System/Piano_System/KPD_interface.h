/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 7/3/2024        *************************/
/*************************      SWC: KPD            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef KPD_INTERFACE_H
#define KPD_INTERFACE_H

#define KPD_u8_KEY_NOT_PRESSED      0xFF

u8 KPD_u8GetKeyState(u16 * Copy_pu8ReturnedKey);

#endif
