/*****************************************************/
/*****************************************************/
/**********       Author : Hassan Syed      **********/
/**********       Layer  : MCAL             **********/
/**********       File   : UART_Program.c **********/
/**********       Version: 1.00              *********/
/**********       Date   : 23-10-2022       **********/
/*****************************************************/
/*****************************************************/

#include "../../04_LIB/STD_TYPES.h"
#include "../../04_LIB/BIT_MATH.h"
#include "UART_Private.h"
#include "UART_Interface.h"
#include "UART_Config.h"

static void   (*UART_RXCallBackOVFunc)(void )= NULL;

void UART_voidInitUART(void)
{

    /* make local var to collect bits values before assign it to UCSRC Register */
    u8 Local_u8RegValue=0;

    /*set bit 7 to select writing in UCSRC not UBRRH */
    SET_BIT(Local_u8RegValue,UART_UCSRC_URSEL);

    /* Select Asyncronous */
    CLR_BIT(Local_u8RegValue,UART_UCSRC_UMSEL);

    /*Select Parity Disable*/
    CLR_BIT(Local_u8RegValue,UART_UCSRC_UPM1);
    CLR_BIT(Local_u8RegValue,UART_UCSRC_UPM0);

    /* select one bit for stop */
    CLR_BIT(Local_u8RegValue,UART_UCSRC_USBS);

    /*Select Char Size * bit*/
    CLR_BIT(Local_u8RegValue,UART_UCSRB_UCSZ2);
    SET_BIT(Local_u8RegValue,UART_UCSRC_UCSZ0);
    SET_BIT(Local_u8RegValue,UART_UCSRC_UCSZ1);


   // Assign Value To Register
    UART_UCSRC=Local_u8RegValue;

    /*Select Baud Rate 9600 bps*/
    UART_UBRRL=51;   // From table in data sheet

	 /*Receive interrupt enable config*/
#if MUART_RX_INTERRUPT_ENABLE==MUART_DISABLED
    CLR_BIT(UART_UCSRB,UART_UCSRB_RXCIE);
#else
    SET_BIT(UART_UCSRB,UART_UCSRB_RXCIE);
#endif

    /*Enable Rx and Tx*/
    SET_BIT(UART_UCSRB,UART_UCSRB_RXEN);
    SET_BIT(UART_UCSRB,UART_UCSRB_TXEN);
}

void UART_voidSendData(u8 Copy_u8Data)
{
	//UART_UDR=Copy_u8Data;
    /*wait till Data Register Empty flag is set*/
    while (GET_BIT(UART_UCSRA,UART_UCSRA_UDRE)==0);
        UART_UDR= Copy_u8Data;
}

u8 UART_U8ReceiveData(void)
{
    /* Waiting till receiving flag is set*/
    while (GET_BIT(UART_UCSRA,UART_UCSRA_RXC)==0);
        return UART_UDR;

}
void UART_VoidSendString(char *str)
{
	u16 i = 0;

	while(str[i] != '\0')
	{
		UART_voidSendData(str[i]);
		i++;
	}
}



void UART_u8SetRXCallBack(void(*Copy_CallBackFunc)(void))
{
    if(Copy_CallBackFunc!=NULL)
    {
    	UART_RXCallBackOVFunc=Copy_CallBackFunc;
    }
}


void __vector_13(void)  __attribute__((signal));
void __vector_13(void)
{
    if(UART_RXCallBackOVFunc!=NULL)
    {
    	UART_RXCallBackOVFunc();
    }

}

