/*****************************************************/
/*****************************************************/
/**********       Author : Hassan Sayed      **********/
/**********       Layer  : HAL             **********/
/**********       Version: 1.00              *********/
/**********       Date   : 23-10-2022       **********/
/*****************************************************/
/*****************************************************/



#include "../../04_LIB/STD_TYPES.h"
#include "../../04_LIB/BIT_MATH.h"
#include "../../03_MCAL/DIO_Driver/DIO_Interface.h"
#include "KPAD_Config.h"
#include "KPAD_Private.h"
#include "KPAD_Interface.h"
#include <avr/delay.h>


 void KPAD_voidInitializeKeypad(void)
 {
	
	 /*for loop to scan all keypad columns and rows*/
	 for (u8 i = 0 ; i<4 ; i++)
	 {
	 	 /*set column current bit in ColumnArray[] OUTPUT*/
		 DIO_VoidSetPinDirection(KEYPAD_PORT,KPAD_u8ColumnArray[i],DIO_OUTPUT_PIN);
	
		 /*set current bit in RowArray[] INPUT*/
		 DIO_VoidSetPinDirection(KEYPAD_PORT,KPAD_u8RowArray[i],DIO_INPUT_PIN);
		
		 /*Enable pull up resistor for current bit in RowArray[]*/
		 DIO_VoidSetPinValue(KEYPAD_PORT,KPAD_u8RowArray[i],DIO_HIGH);
	 }/*end of for loop*/
	
 }

u8 KPAD_u8GetPressedKey(void)
{

    /*for loop to set all column pins HIGH*/
    for (u8 i = 0; i<4 ;i++ )
    {
        /*set current pin in ColumnArray HIGH*/
        DIO_VoidSetPinValue(KEYPAD_PORT,KPAD_u8ColumnArray[i],DIO_HIGH);

    }/*end of for loop*/

    /*for loop to scan all keypad columns*/
    for (u8 i = 0 ; i<4 ; i++)
    {
        /*set current column pin low to test all row pins to find out which button has been pressed*/
        DIO_VoidSetPinValue(KEYPAD_PORT,KPAD_u8ColumnArray[i],DIO_LOW);

        /*for loop to scan and test all keypad row pins*/
        for (u8 j = 0 ; j<4 ; j++)
        {

            /*check current row pin value*/
            if ( DIO_LOW == DIO_U8GetPinValue(KEYPAD_PORT,KPAD_u8RowArray[j]) )
            {
                /*return pressed button value*/
                return KeyPadArr[j][i];
            }
        }/*end of for loop*/

        /*set current column pin HIGH again*/
        DIO_VoidSetPinValue(KEYPAD_PORT,KPAD_u8ColumnArray[i],DIO_HIGH);

    }/*end of for loop*/

    /*Report no Button pressed*/
    return '?';

}/*end of HKPD_u8GetPressedKey()*/



