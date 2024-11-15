/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 15/6/2024       *************************/
/*************************      SWC: UART           *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_private.h"
#include "UART_interface.h"
#include "UART_config.h"

void UART_voidInit(void)
{
	u16 Local_u16BaudRate = 51;
	u8 Local_u8UCSRCValue = 0b10000000;
	/* Baud Rate = 9600 */
	UART_u8_UBRRL_REG = (u8) Local_u16BaudRate;
	UART_u8_UBRRH_REG = (u8)(Local_u16BaudRate >> 8);
	/* Normal Speed */
	CLR_BIT(UART_u8_UCSRA_REG,UCSRA_U2X);
	/* Disable MPM */
	CLR_BIT(UART_u8_UCSRA_REG,UCSRA_MPCM);
	/* Enable Tx,Rx */
	SET_BIT(UART_u8_UCSRB_REG,UCSRB_RXEN);
	SET_BIT(UART_u8_UCSRB_REG,UCSRB_TXEN);
	/* Select 8 bit Data */
	CLR_BIT(UART_u8_UCSRB_REG,UCSRB_UCSZ2);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
	/* Select Asynch Mode */
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);
	/* No Parity Bit */
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM1);
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
	/* Enable 2 Stop Bits */
	SET_BIT(Local_u8UCSRCValue,UCSRC_USBS);
	/* Update UCSRC Reg */
	UART_u8_UCSRC_REG = Local_u8UCSRCValue;
}

void UART_voidSendByte(u8 Copy_u8DataByte)
{
	/* wait until the transmit register is empty */
	while(GET_BIT(UART_u8_UCSRA_REG,UCSRA_UDRE) == 0);
	/* Send Data Byte */
	UART_u8_UDR_REG = Copy_u8DataByte;
}

u8   UART_u8ReceiveByte(u8 * Copy_pu8RecByte)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if(Copy_pu8RecByte != NULL)
	{
		/* wait until the data is received */
		while(GET_BIT(UART_u8_UCSRA_REG,UCSRA_RXC) == 0);
		/* Read Data */
		*Copy_pu8RecByte = UART_u8_UDR_REG;
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;
}
