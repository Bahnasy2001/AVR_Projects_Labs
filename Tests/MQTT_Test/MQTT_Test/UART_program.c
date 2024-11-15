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

static void (*UART_pfTXC)(void) = NULL;
static u8* UART_pu8StringToSend = NULL;
static u8 UART_u8CurrentIndex = 0;
static volatile u8 UART_u8BusyFlagTx = 0;

static u8* UART_pu8ReceivedString = NULL;
static void (*UART_pfRXC)(void) = NULL;
static u8 UART_u8ReceiveCurrentIndex = 0;
static volatile u8 UART_u8BusyFlagRx = 0;
static u8 UART_u8ReceiveMessageSize = 0;

void UART_voidInit(void)
{
	u16 Local_u16BaudRate = UART_u8_BAUD_RATE;
	u8 Local_u8UCSRCValue = 0b10000000;
	/* Baud Rate = 9600 */
	UART_u8_UBRRL_REG = (u8)Local_u16BaudRate;
	UART_u8_UBRRH_REG = (u8)(Local_u16BaudRate >> 8);
#if UART_u8_SPEED == UART_u8_NORMAL_SPEED
	/* Normal Speed */
	CLR_BIT(UART_u8_UCSRA_REG,UCSRA_U2X);
#elif UART_u8_SPEED == UART_u8_DOUBLE_SPEED
	/* Double Speed */
	SET_BIT(UART_u8_UCSRA_REG,UCSRA_U2X);
#endif

#if UART_u8_MPM_MODE == UART_u8_DISABLE_MPM
	/* Disable MPM */
	CLR_BIT(UART_u8_UCSRA_REG,UCSRA_MPCM);
#elif UART_u8_MPM_MODE == UART_u8_ENABLE_MPM
	/* Enable MPM */
	SET_BIT(UART_u8_UCSRA_REG,UCSRA_MPCM);
#endif

#if UART_u8_RXCIE_MODE == UART_u8_ENABLE_RXCIE
	/* RX Complete Interrupt Enable */
	SET_BIT(UART_u8_UCSRB_REG,UCSRB_RXCIE);
#endif

#if UART_u8_TXCIE_MODE == UART_u8_ENABLE_TXCIE
	/* TX Complete Interrupt Enable */
	SET_BIT(UART_u8_UCSRB_REG,UCSRB_TXCIE);
#endif

#if UART_u8_UDRIE_MODE == UART_u8_ENABLE_UDRIE
	/* USART Data Register Empty Interrupt Enable */
	SET_BIT(UART_u8_UCSRB_REG,UCSRB_UDRIE);
#endif

#if UART_u8_RXEN_MODE == UART_u8_ENABLE_RXEN
	/* Enable Rx */
	SET_BIT(UART_u8_UCSRB_REG,UCSRB_RXEN);
#elif UART_u8_RXEN_MODE == UART_u8_DISABLE_RXEN
	/* Disable Rx */
	CLR_BIT(UART_u8_UCSRB_REG,UCSRB_RXEN);
#endif

#if UART_u8_TXEN_MODE == UART_u8_ENABLE_TXEN
	/* Enable Tx */
	SET_BIT(UART_u8_UCSRB_REG,UCSRB_TXEN);
#elif UART_u8_TXEN_MODE == UART_u8_DISABLE_TXEN
	/* Disable Tx */
	CLR_BIT(UART_u8_UCSRB_REG,UCSRB_TXEN);
#endif
	
	/* Select 8 bit Data */
	CLR_BIT(UART_u8_UCSRB_REG,UCSRB_UCSZ2);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
#if UART_u8_USART_MODE == UART_u8_ASYNCH_MODE
	/* Select Asynch Mode */
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);
#elif UART_u8_USART_MODE == UART_u8_SYNCH_MODE
	/* Select synch Mode */
	SET_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);
#endif

#if UART_u8_PARITY_MODE == UART_u8_PARITY_DISABLE
	/* No Parity Bit */
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM1);
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
#elif UART_u8_PARITY_MODE == UART_u8_PARITY_EVEN
	/* Even Parity Bit */
	SET_BIT(Local_u8UCSRCValue,UCSRC_UPM1);
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
#elif UART_u8_PARITY_MODE == UART_u8_PARITY_ODD
	/* Odd Parity Bit */
	SET_BIT(Local_u8UCSRCValue,UCSRC_UPM1);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
#endif

#if UART_u8_NO_STOP_BITS == UART_u8_ONE_BITS_STOP
	/* Enable 1 Stop Bits */
	CLR_BIT(Local_u8UCSRCValue,UCSRC_USBS);
#elif UART_u8_NO_STOP_BITS == UART_u8_TWO_BITS_STOP
	/* Enable 2 Stop Bits */
	SET_BIT(Local_u8UCSRCValue,UCSRC_USBS);
#endif

	/* Update UCSRC Reg */
	UART_u8_UCSRC_REG = Local_u8UCSRCValue;
}

void UART_voidSendByte(u8 Copy_u8DataByte)
{
	/* wait until the transmit register is empty */
	while((GET_BIT(UART_u8_UCSRA_REG,UCSRA_UDRE)) == 0);
	/* Send Data Byte */
	UART_u8_UDR_REG = Copy_u8DataByte;
}

u8   UART_u8ReceiveByte(u8 * Copy_pu8RecByte)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if(Copy_pu8RecByte != NULL)
	{
		/* wait until the data is received */
		while((GET_BIT(UART_u8_UCSRA_REG,UCSRA_RXC)) == 0);
		/* Read Data */
		*Copy_pu8RecByte = UART_u8_UDR_REG;
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;
}

u8   UART_u8SendStringSynch(u8 * Copy_pu8String)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u32 Local_u32TimeoutCounter = 0;
	// Check for NULL pointer
	if(Copy_pu8String != NULL)
	{
		while(*Copy_pu8String != '\0') // Loop until the end of the string
		{
			Local_u32TimeoutCounter = 0;
			// Wait until the data register is empty or timeout occurs
			while(((GET_BIT(UART_u8_UCSRA_REG,UCSRA_UDRE)) == 0) && (Local_u32TimeoutCounter < UART_u32_TIME_OUT_MAX_VALUE))
			{
				Local_u32TimeoutCounter++;
			}
			// Check if timeout occurred
            if (Local_u32TimeoutCounter >= UART_u32_TIME_OUT_MAX_VALUE)
            {
                Local_u8ErrorState = STD_TYPES_NOK;
                break;
            }
            // Load the data register with the next character in the string
            UART_u8_UDR_REG = *Copy_pu8String;

            // Wait for the transmission to complete or timeout occurs
             Local_u32TimeoutCounter = 0;
            while ((GET_BIT(UART_u8_UCSRA_REG, UCSRA_TXC) == 0) && (Local_u32TimeoutCounter < UART_u32_TIME_OUT_MAX_VALUE))
            {
                Local_u32TimeoutCounter++;
            }
            // Check if timeout occurred
            if (Local_u32TimeoutCounter >= UART_u32_TIME_OUT_MAX_VALUE)
            {
                Local_u8ErrorState = STD_TYPES_NOK;
                break;
            }
            // Clear the transmit complete flag
            SET_BIT(UART_u8_UCSRA_REG, UCSRA_TXC);
            // Move to the next character
            Copy_pu8String++;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 UART_u8SendStringSynchWithLength(u8 *Copy_pu8Data, u16 Copy_u16Length) {
    u8 Local_u8ErrorState = STD_TYPES_OK;
    u32 Local_u32TimeoutCounter = 0;
    
    // Check for NULL pointer
    if (Copy_pu8Data != NULL) {
        for (u16 i = 0; i < Copy_u16Length; i++) {
            Local_u32TimeoutCounter = 0;
            
            // Wait until the data register is empty or timeout occurs
            while (((GET_BIT(UART_u8_UCSRA_REG, UCSRA_UDRE)) == 0) && (Local_u32TimeoutCounter < UART_u32_TIME_OUT_MAX_VALUE)) {
                Local_u32TimeoutCounter++;
            }
            
            // Check if timeout occurred
            if (Local_u32TimeoutCounter >= UART_u32_TIME_OUT_MAX_VALUE) {
                Local_u8ErrorState = STD_TYPES_NOK;
                break;
            }
            
            // Load the data register with the next byte
            UART_u8_UDR_REG = Copy_pu8Data[i];
            
            // Wait for the transmission to complete or timeout occurs
            Local_u32TimeoutCounter = 0;
            while ((GET_BIT(UART_u8_UCSRA_REG, UCSRA_TXC) == 0) && (Local_u32TimeoutCounter < UART_u32_TIME_OUT_MAX_VALUE)) {
                Local_u32TimeoutCounter++;
            }
            
            // Check if timeout occurred
            if (Local_u32TimeoutCounter >= UART_u32_TIME_OUT_MAX_VALUE) {
                Local_u8ErrorState = STD_TYPES_NOK;
                break;
            }
            
            // Clear the transmit complete flag
            SET_BIT(UART_u8_UCSRA_REG, UCSRA_TXC);
        }
    } else {
        Local_u8ErrorState = STD_TYPES_NOK;
    }
    
    return Local_u8ErrorState;
}


u8   UART_u8ReceiveStringSynch(u8 * Copy_puReceivedString, u8 Copy_u8MessageSize)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u32 Local_u32TimeoutCounter = 0;
	u8 Local_u8StringCounter = 0;
	if (Copy_puReceivedString != NULL)
	{
		while (Local_u8StringCounter < Copy_u8MessageSize)
		{
			Local_u32TimeoutCounter = 0;
			while (((GET_BIT(UART_u8_UCSRA_REG, UCSRA_RXC)) == 0) && (Local_u32TimeoutCounter < UART_u32_TIME_OUT_MAX_VALUE))
			{
				Local_u32TimeoutCounter++;
			}
			if (Local_u32TimeoutCounter >= UART_u32_TIME_OUT_MAX_VALUE)
			{
				Local_u8ErrorState = STD_TYPES_NOK;
				break;
			}
			Copy_puReceivedString[Local_u8StringCounter] = UART_u8_UDR_REG;
			Local_u8StringCounter++;
		}
		Copy_puReceivedString[Local_u8StringCounter] = '\0'; // Null-terminate the string
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8   UART_u8SendStringAsynch(u8* Copy_pu8String, void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Copy_pu8String != NULL && Copy_pf != NULL)
    {
    	if(UART_u8BusyFlagTx == 0)
    	{
	    	UART_u8BusyFlagTx = 1;
	        UART_pu8StringToSend = Copy_pu8String;
	        UART_pfTXC = Copy_pf;
	        UART_u8CurrentIndex = 0;

	        // Enable UART Data Register Empty Interrupt
	        SET_BIT(UART_u8_UCSRB_REG, UCSRB_UDRIE);
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

void __vector_14(void) __attribute__((signal)); // UART Data Register Empty ISR
void __vector_14(void)
{
    if (UART_pu8StringToSend[UART_u8CurrentIndex] != '\0')
    {
        UART_u8_UDR_REG = UART_pu8StringToSend[UART_u8CurrentIndex];
        UART_u8CurrentIndex++;
    }
    else
    {
        // Disable UART Data Register Empty Interrupt
        CLR_BIT(UART_u8_UCSRB_REG, UCSRB_UDRIE);
        
        // Call the callback function
        if (UART_pfTXC != NULL)
        {
            UART_pfTXC();
        }
        //Clear Busy Flag
        UART_u8BusyFlagTx = 0;
        //Clear The Global Counter
        UART_u8CurrentIndex = 0;
    }
}

u8   UART_u8ReceiveStringAsynch(u8* Copy_pu8ReceivedString, void(*Copy_pf)(void), u8 Copy_u8MessageSize)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	//Check Pointers
	if (Copy_pu8ReceivedString != NULL && Copy_pf != NULL && Copy_u8MessageSize > 0)
	{
		//Check Busy Flag
		if(UART_u8BusyFlagRx == 0)
		{
			//Set Busy Flag
			UART_u8BusyFlagRx = 1;
			//Update Global Variable with Receive Message
		 	UART_pu8ReceivedString = Copy_pu8ReceivedString;
		 	//Update Global Pointer To function with Notification Function 
            UART_pfRXC = Copy_pf;
            //Clear Index
            UART_u8ReceiveCurrentIndex = 0;
            //Update Global Variable with Message Size
            UART_u8ReceiveMessageSize = Copy_u8MessageSize;

            // Enable UART RX Complete Interrupt
            SET_BIT(UART_u8_UCSRB_REG, UCSRB_RXCIE);
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
void __vector_13(void) __attribute__((signal)); // UART RX Complete ISR
void __vector_13(void)
{
	if (UART_u8ReceiveCurrentIndex < UART_u8ReceiveMessageSize)
	{
		UART_pu8ReceivedString[UART_u8ReceiveCurrentIndex] = UART_u8_UDR_REG;
		UART_u8ReceiveCurrentIndex++;

		if (UART_u8ReceiveCurrentIndex >= UART_u8ReceiveMessageSize)
        {
            // Disable UART RX Complete Interrupt
            CLR_BIT(UART_u8_UCSRB_REG, UCSRB_RXCIE);

            // Null-terminate the received string
            UART_pu8ReceivedString[UART_u8ReceiveCurrentIndex] = '\0';

            // Call the callback function
            if (UART_pfRXC != NULL)
            {
                UART_pfRXC();
            }
            // Clear Busy Flag
            UART_u8BusyFlagRx = 0;

            // Clear The Global Counter
            UART_u8ReceiveCurrentIndex = 0;
        }
	}
}