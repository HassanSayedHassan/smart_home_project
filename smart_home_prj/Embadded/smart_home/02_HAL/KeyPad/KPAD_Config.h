/*****************************************************/
/*****************************************************/
/**********       Author : Hassan Syed      **********/
/**********       Layer  : HAL             **********/
/**********       Version: 1.00              *********/
/**********       Date   : 23-10-2022       **********/
/*****************************************************/
/*****************************************************/


#ifndef __HKPD_Config_h__
#define __HKPD_Config_h__


/*choose keypad port*/
#define KEYPAD_PORT  DIO_PORTD


/*Column connections*/
#define C1 3
#define C2 2
#define C3 1
#define C4 0
/*Row connections*/
#define R1 4
#define R2 5
#define R3 6
#define R4 7

 
/*Keypad buttons assigned values array*/
const u8 KeyPadArr[4][4]={{ '1',  '2',  '3',  '4'},
					      { '5',  '6',  '7',  '8'},
					      { '9',  '0',  '9',  '*'},
					      {'c', '0', '=', '/'}};
							  

#endif

