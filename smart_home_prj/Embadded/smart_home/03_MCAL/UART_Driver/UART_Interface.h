/*****************************************************/
/*****************************************************/
/**********       Author : Hassan Syed      **********/
/**********       Layer  : MCAL             **********/
/**********       File   : UART_Interface.h **********/
/**********       Version: 1.00              *********/
/**********       Date   : 23-10-2022       **********/
/*****************************************************/
/*****************************************************/

#ifndef __UART_INTERFACE_H__
#define __UART_INTERFACE_H__



void UART_voidInitUART(void);

void UART_voidSendData(u8 Copy_u8Data);

u8 UART_U8ReceiveData(void);
void UART_VoidSendString(char *str);

void UART_u8SetRXCallBack(void(* Copy_CallBackFunc)(void));
#endif
