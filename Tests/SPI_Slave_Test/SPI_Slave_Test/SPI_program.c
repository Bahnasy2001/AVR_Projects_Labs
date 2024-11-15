/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 26/6/2024       *************************/
/*************************      SWC: SPI            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

/*
if Master Mode you need to Select all things
if Slave Mode you need to Select Data Order,Slave Mode,Clock Polarity and Clock Phase
*/
void SPI_voidInit(void)
{
#if SPI_u8_MODE == SPI_u8_MASTER_MODE
	/* Data Order = MSB first */
	CLR_BIT(SPI_u8_SPCR_REG,SPCR_DORD);
	/* Select Master Mode */
	SET_BIT(SPI_u8_SPCR_REG,SPCR_MSTR);
	/* Choose Clock Polarity and Clock Phase => Falling,Raising / Setup,Sample */
	SET_BIT(SPI_u8_SPCR_REG,SPCR_CPOL);
	SET_BIT(SPI_u8_SPCR_REG,SPCR_CPHA);
	/* Select Clock => Fosc/64 */
	SET_BIT(SPI_u8_SPSR_REG,SPSR_SPI2X);
	SET_BIT(SPI_u8_SPCR_REG,SPCR_SPR1);
	CLR_BIT(SPI_u8_SPCR_REG,SPCR_SPR0);
	/* Enable SPI */
	SET_BIT(SPI_u8_SPCR_REG,SPCR_SPE);
#elif SPI_u8_MODE == SPI_u8_SLAVE_MODE
	/* Data Order = MSB first */
	CLR_BIT(SPI_u8_SPCR_REG,SPCR_DORD);
	/* Select Slave Mode */
	CLR_BIT(SPI_u8_SPCR_REG,SPCR_MSTR);
	/* Choose Clock Polarity and Clock Phase => Falling,Raising / Setup,Sample */
	SET_BIT(SPI_u8_SPCR_REG,SPCR_CPOL);
	SET_BIT(SPI_u8_SPCR_REG,SPCR_CPHA);
	/* Enable SPI */
	SET_BIT(SPI_u8_SPCR_REG,SPCR_SPE);
#endif
}

u8   SPI_u8TransReceive(u8 Copy_u8TransmittedByte, u8 * Copy_pu8ReceivedByte)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if(Copy_pu8ReceivedByte != NULL)
	{
		/* Send Byte */
		SPI_u8_SPDR_REG = Copy_u8TransmittedByte;
		/* Check if the transmission is completed */
		while((GET_BIT(SPI_u8_SPSR_REG,SPSR_SPIF)) == 0);
		/* Read Byte */
		*Copy_pu8ReceivedByte = SPI_u8_SPDR_REG;
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;
}

void SPI_voidSlaveSendByte (u8 Copy_u8DataByte)
{
	SPI_u8_SPDR_REG = Copy_u8DataByte;
}

u8   SPI_u8ReceiveByte(u8 * Copy_pu8ReceivedByte)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if(Copy_pu8ReceivedByte != NULL)
	{
		/* Check if the transmission is completed */
		while((GET_BIT(SPI_u8_SPSR_REG,SPSR_SPIF)) == 0);
		/* Read Byte */
		*Copy_pu8ReceivedByte = SPI_u8_SPDR_REG;
		Local_u8ErrorState = STD_TYPES_OK;

	}
	return Local_u8ErrorState;
}