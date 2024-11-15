/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 26/6/2024       *************************/
/*************************      SWC: SPI            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU    8000000UL
#include <util/delay.h>
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

/* Global variables */
static u8 * SPI_pu8TransmittedString = NULL;
static u8 * SPI_pu8ReceivedString = NULL;
static void(*SPI_pfTXC)(void) = NULL;
static void(*SPI_pfRXC)(void) = NULL;
static volatile u8 SPI_u8TransmitCurrentIndex = 0;
static volatile u8 SPI_u8ReceiveCurrentIndex = 0;
static volatile u8 SPI_u8BusyFlagTx = 0;
static volatile u8 SPI_u8BusyFlagRx = 0;
static volatile u8 SPI_u8ReceiveMessageSize = 0;
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
	CLR_BIT(SPI_u8_SPSR_REG,SPSR_SPI2X);
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

u8   SPI_u8SendStringSynch(u8 * Copy_pu8TransmittedString)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u32 Local_u32TimeoutCounter = 0;
	if(Copy_pu8TransmittedString != NULL)
	{
		while(*Copy_pu8TransmittedString != '\0')
		{
			SPI_u8_SPDR_REG = *Copy_pu8TransmittedString;
			Local_u32TimeoutCounter = 0;
			while(((GET_BIT(SPI_u8_SPSR_REG,SPSR_SPIF)) == 0) && (Local_u32TimeoutCounter < SPI_u32_TIMEOUT_MAX_VALUE))
			{
				Local_u32TimeoutCounter++;
			}
			if (Local_u32TimeoutCounter >= SPI_u32_TIMEOUT_MAX_VALUE) 
			{
				Local_u8ErrorState = STD_TYPES_NOK;
				break;
			}
			// Add a small delay to ensure data is properly transmitted
			_delay_us(10);
			Copy_pu8TransmittedString++;

		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8   SPI_u8ReceiveStringSynch(u8 * Copy_pu8ReceivedString)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u32 Local_u32TimeoutCounter = 0;
	u8 Local_u8Index = 0;

	if(Copy_pu8ReceivedString != NULL)
	{
		while(1)
		{
			u32 Local_u32TimeoutCounter = 0;
			while(((GET_BIT(SPI_u8_SPSR_REG,SPSR_SPIF)) == 0) && (Local_u32TimeoutCounter < SPI_u32_TIMEOUT_MAX_VALUE))
			{
				Local_u32TimeoutCounter++;
			}
			if (Local_u32TimeoutCounter >= SPI_u32_TIMEOUT_MAX_VALUE) 
			{
				Local_u8ErrorState = STD_TYPES_NOK;
				break;
			}
			Copy_pu8ReceivedString[Local_u8Index] = SPI_u8_SPDR_REG;
			if(Copy_pu8ReceivedString[Local_u8Index] == '\0')
			{
				break;
			}
			Local_u8Index++;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8   SPI_u8SendStringAsynch(u8 * Copy_pu8TransmittedString, void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Copy_pu8TransmittedString != NULL && Copy_pf != NULL)
	{
		if(SPI_u8BusyFlagTx == 0)
		{
			//Set Busy Flag
			SPI_u8BusyFlagTx = 1;
			//Assign Global Variables and Pointers
			SPI_pu8TransmittedString = Copy_pu8TransmittedString;
			SPI_pfTXC = Copy_pf;
			SPI_u8TransmitCurrentIndex = 0;
			/* Start Transmission */
			SPI_u8_SPDR_REG = SPI_pu8TransmittedString[SPI_u8TransmitCurrentIndex];
			// Enable SPI Interrupt
			SET_BIT(SPI_u8_SPCR_REG, SPCR_SPIE); 
		}
		else
		{
			Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8   SPI_u8ReceiveStringAsynch(u8 * Copy_pu8ReceivedString,void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Copy_pu8ReceivedString != NULL && Copy_pf != NULL)
	{
		if (SPI_u8BusyFlagRx == 0)
		{
			/* Set Busy Flag */
			SPI_u8BusyFlagRx = 1;
			/* Set Receive String and Callback */
			SPI_pu8ReceivedString = Copy_pu8ReceivedString;
			SPI_pfRXC = Copy_pf;
			SPI_u8ReceiveCurrentIndex = 0;
			SPI_u8ReceiveMessageSize = sizeof(Copy_pu8ReceivedString);
			/* Enable SPI Interrupt */
			SET_BIT(SPI_u8_SPCR_REG, SPCR_SPIE);
		}
		else
		{
			Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8   SPI_u8SendReceiveStringSynch(u8 * Copy_pu8TransmittedString,u8 * Copy_pu8ReceivedString)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u32 Local_u32TimeoutCounter = 0;
	u8 Local_u8Index = 0;

	if (Copy_pu8TransmittedString != NULL && Copy_pu8ReceivedString != NULL)
	{
		while (Copy_pu8TransmittedString[Local_u8Index] != '\0')
		{
			SPI_u8_SPDR_REG = Copy_pu8TransmittedString[Local_u8Index];
			Local_u32TimeoutCounter = 0;
			while ((GET_BIT(SPI_u8_SPSR_REG, SPSR_SPIF) == 0) && (Local_u32TimeoutCounter < SPI_u32_TIMEOUT_MAX_VALUE))
			{
				Local_u32TimeoutCounter++;
			}
			if (Local_u32TimeoutCounter >= SPI_u32_TIMEOUT_MAX_VALUE)
			{
				Local_u8ErrorState = STD_TYPES_NOK;
				break;
			}
			Copy_pu8ReceivedString[Local_u8Index] = SPI_u8_SPDR_REG;
			Local_u8Index++;
		}
		Copy_pu8ReceivedString[Local_u8Index] = '\0';
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8   SPI_u8SendReceiveStringAsynch(u8 * Copy_pu8TransmittedString,u8 * Copy_pu8ReceivedString,void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	//Check Pointers
	if (Copy_pu8TransmittedString != NULL && Copy_pu8ReceivedString != NULL && Copy_pf != NULL)
	{
		if (SPI_u8BusyFlagTx == 0 && SPI_u8BusyFlagRx == 0)
		{
			//Set Busy Flags
			SPI_u8BusyFlagTx = 1;
			SPI_u8BusyFlagRx = 1;
			//Assign Global Pointers
			SPI_pu8TransmittedString = Copy_pu8TransmittedString;
			SPI_pu8ReceivedString = Copy_pu8ReceivedString;
			SPI_pfRXC = Copy_pf;
			SPI_u8TransmitCurrentIndex = 0;
			// Check for Write Collision
			if (GET_BIT(SPI_u8_SPSR_REG, SPSR_WCOL))
			{
				// Clear the WCOL bit by reading SPSR and then accessing SPDR
				u8 dummy = SPI_u8_SPSR_REG;
				dummy = SPI_u8_SPDR_REG;
				(void)dummy; // Prevent unused variable warning
			}
			/* Start Transmission */
			SPI_u8_SPDR_REG = SPI_pu8TransmittedString[SPI_u8TransmitCurrentIndex];
			SET_BIT(SPI_u8_SPCR_REG, SPCR_SPIE); // Enable SPI Interrupt
		}
		else
		{
			Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

#if SPI_u8_ISR == SPI_u8_TX_ISR
void __vector_12(void) __attribute__((signal)); // SPI Interrupt Service Routine
void __vector_12(void)
{
	if(SPI_pu8TransmittedString[SPI_u8TransmitCurrentIndex] != '\0')
	{
		SPI_u8_SPDR_REG = SPI_pu8TransmittedString[SPI_u8TransmitCurrentIndex];
		SPI_u8TransmitCurrentIndex++;
	}
	else
	{

		/* Disable SPI Interrupt */
		CLR_BIT(SPI_u8_SPCR_REG, SPCR_SPIE);
		if (SPI_pfTXC != NULL)
		{
			SPI_pfTXC();
		}
		//Clear Busy Flag
		SPI_u8BusyFlagTx = 0;
		//Clear The Global Index
		SPI_u8TransmitCurrentIndex = 0;
	}
}

#elif SPI_u8_ISR == SPI_u8_RX_ISR
void __vector_12(void) __attribute__((signal)); // SPI Interrupt Service Routine
void __vector_12(void)
{
	if (SPI_u8ReceiveCurrentIndex < SPI_u8ReceiveMessageSize)
	{
		SPI_pu8ReceivedString[SPI_u8ReceiveCurrentIndex] = SPI_u8_SPDR_REG;
		SPI_u8ReceiveCurrentIndex++;
		if (SPI_u8ReceiveCurrentIndex >= SPI_u8ReceiveMessageSize)
		{
			/* Disable SPI Interrupt */
			CLR_BIT(SPI_u8_SPCR_REG, SPCR_SPIE);

			if (SPI_pfRXC != NULL)
			{
				SPI_pfRXC();
			}
			//Clear Busy Flag
			SPI_u8BusyFlagRx = 0;
			//Clear The Global Index
			SPI_u8ReceiveCurrentIndex = 0;
		}
	}
}

#elif SPI_u8_ISR == SPI_u8_TXRX_ISR
void __vector_12(void) __attribute__((signal)); // SPI Interrupt Service Routine
void __vector_12(void)
{
	//Check Pointers
	if (SPI_pu8TransmittedString != NULL && SPI_pu8ReceivedString != NULL && SPI_pfRXC != NULL)
	{
		// Check for Write Collision
		if (GET_BIT(SPI_u8_SPSR_REG, SPSR_WCOL))
		{
			// Clear the WCOL bit by reading SPSR and then accessing SPDR
			u8 dummy = SPI_u8_SPSR_REG;
			dummy = SPI_u8_SPDR_REG;
			(void)dummy; // Prevent unused variable warning
		}
		//Read Data
		SPI_pu8ReceivedString[SPI_u8TransmitCurrentIndex] = SPI_u8_SPDR_REG;
		SPI_u8TransmitCurrentIndex++;
		if(SPI_pu8TransmittedString[SPI_u8TransmitCurrentIndex] != '\0')
		{
			SPI_u8_SPDR_REG = SPI_pu8TransmittedString[SPI_u8TransmitCurrentIndex];
		}
		else
		{
			// Null-terminate the received string
			SPI_pu8ReceivedString[SPI_u8TransmitCurrentIndex] = '\0';
			/* Disable SPI Interrupt */
			CLR_BIT(SPI_u8_SPCR_REG, SPCR_SPIE);
			if (SPI_pfRXC != NULL)
			{
				SPI_pfRXC();
			}
			//Clear Busy Flag
			SPI_u8BusyFlagTx = 0;
			//Clear Busy Flag
			SPI_u8BusyFlagRx = 0;
			//Clear The Global Index
			SPI_u8TransmitCurrentIndex = 0;
		}
	}
}
#endif
