/*****************************************************/
/*****************************************************/
/**********       Author : Hassan Syed      **********/
/**********       Layer  : MCAL             **********/
/**********       File   : UART_Private.h **********/
/**********       Version: 1.00              *********/
/**********       Date   : 23-10-2022       **********/
/*****************************************************/
/*****************************************************/
#ifndef __UART_PRIVATE_H__
#define __UART_PRIVATE_H__

/*=================================================================================
 * UART Registers and Pins
 *=================================================================================*/
#define UART_UDR            *((volatile u8*)0x2C)           //USART I/O Data Register
#define UART_UCSRA          *((volatile u8*)0x2B)          //USART Control and Status Register A
#define UART_UCSRA_RXC             7                            // USART Receive Complete flag
#define UART_UCSRA_TXC             6                            // USART Transmit Complete flag
#define UART_UCSRA_UDRE            5                            //USART Data Register Empty flag


#define UART_UCSRB                *((volatile u8*)0x2A)       //USART Control and Status Register B
#define UART_UCSRB_RXCIE           7                            //RX(Recieve) Complete Interrupt Enable
#define UART_UCSRB_TXCIE           6                           //TX Complete Interrupt Enable
#define UART_UCSRB_UDRIE           5                           //USART Data Register Empty Interrupt Enable
#define UART_UCSRB_RXEN            4                           //Receiver Enable
#define UART_UCSRB_TXEN            3                            //Transmitter Enable
#define UART_UCSRB_UCSZ2           2                           //Character Size  ... This Bit is one of three bit to select character size
#define UART_UCSRB_RXB8            1                            //Receive Data Bit 8
///Receive Data Bit Must be read before reading the low bits from UDR.
#define UART_UCSRB_TXB8            0                           //Transmit Data Bit 8
///Transmit Data Bit Must be written before writing the low bits to UDR.


#define UART_UCSRC              *((volatile u8*)0x40)        //  USART Control and StatusRegister C
/* This bit selects between accessing the UCSRC or the UBRRH Register.
 The URSEL must be one when writing the UCSRC.*/
#define UART_UCSRC_URSEL               7
/* USART Mode Select:-
    0 Asynchronous Operation
    1 Synchronous Operation*/
#define UART_UCSRC_UMSEL               6

/*
 UPM1:0: Parity Mode
 */
#define UART_UCSRC_UPM1                5
#define UART_UCSRC_UPM0                4
#define UART_UCSRC_USBS                3        //Stop Bit Select
/* The another two bits with UART_UCSRB_UCSZ2 to select character size*/
#define UART_UCSRC_UCSZ1               2
#define UART_UCSRC_UCSZ0               1
#define UART_UCSRC_UCPOL               0        //Clock Polarity

#define UART_UBRRL                *((volatile u8*)0x29)



#define UART_UBRRH                *((volatile u8*)0x40)
/* This bit selects between accessing the UCSRC or the UBRRH Register.
 The URSEL must be zero when writing UBRRH.*/
#define UART_UBRRH_URSEL               7


#define MUART_DISABLED            0
#define MUART_ENABLED             1

#endif
