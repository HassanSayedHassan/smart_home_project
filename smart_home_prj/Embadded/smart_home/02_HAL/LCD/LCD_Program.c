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
#include "LCD_Privte.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include <avr/delay.h>

/*==============================================================================================================================================
 * Global variables
 *==============================================================================================================================================*/

/*Initialize display with cursor and display enabled*/
u8 DisplayAndCursorCommand  = 0b00001111;
/*initialize font size with 7 Dot size, 2 lines and, 4Bit Modes */
u8 FontSizeAndLineCommand   = 0b00101000;  



/*==============================================================================================================================================
 * Private Modules
 *==============================================================================================================================================*/

static void LCD_voidWriteCommand(u8 Copy_u8Command);
static void LCD_voidWriteData(u8 Copy_u8Data);

/*==============================================================================================================================================
 * Public Modules
 *==============================================================================================================================================*/


/*=================================================================================================
 * 8 Bit Mode 
 *=================================================================================================*/

#if (LCD_MODE == LCD_8BIT)
 
 /* 
  * Prototype   : u8 LCD_voidWriteCommand(u8 Copy_u8Command);
  * Description : write command to LCD
  * Arguments   : u8 Command       
  * return      : void
  */
  void LCD_voidWriteCommand(u8 Copy_u8Command)
  {
	  /*Set RW pin 0 (Write Mode selected)*/
	  DIO_VoidSetPinValue(ContREG,LCD_RW,DIO_LOW) ;
	  /*Set RS pin 0 (Instruction register selected)*/
	  DIO_VoidSetPinValue(ContREG,LCD_RS,DIO_LOW) ;
	  /*output instruction data to Data Bus*/
	  switch(Copy_u8Command)
	  {
		  /*if command value is 1 clear data register and output 1 to it*/
		  case 1  : { DIO_VoidSetPortValue(DataREG,DIO_LOW); DIO_VoidSetPinValue(DataREG,LCD_DATA_REG_PIN0,DIO_HIGH); } break;
		  /*else output command to data register*/
		  default : { DIO_VoidSetPortValue(DataREG,Copy_u8Command); }

	  }/*end of switch case*/

	  /*Set EN pin 1 (LCD Read data )*/
	  DIO_VoidSetPinValue(ContREG,LCD_EN,DIO_HIGH);
	  //_delay_ms(2);
	  _delay_ms(2);
	  /*Set EN pin 0 (LCD Write data to its reg)*/
	  DIO_VoidSetPinValue(ContREG,LCD_EN,DIO_LOW) ;

  }/*end of LCD_u8WriteCommand()*/


/*
 * Prototype   : void LCD_voidWriteData(u8 Copy_u8Data);
 * Description : write Data to LCD
 * Arguments   : u8 Data
 * return      : void
 */
 void LCD_voidWriteData(u8 Copy_u8Data)
 {
	 /*Set RW pin 0 (Write Mode selected)*/
	 DIO_VoidSetPinValue(ContREG,LCD_RW,DIO_LOW);
	 /*Set RS pin 1 (Data register selected)*/
	 DIO_VoidSetPinValue(ContREG,LCD_RS,DIO_HIGH);
	 /*output data to Data Bus*/
	 /*output instruction data to Data Bus*/
	 switch(Copy_u8Data)
	 {
		 /*if Data value is 1 clear data register and output 1 to it*/
		 case 1  : { DIO_VoidSetPortValue(DataREG,DIO_LOW); DIO_VoidSetPinValue(DataREG,LCD_DATA_REG_PIN0,DIO_HIGH); } break;
		 /*else output Data to data register*/
		 default : { DIO_VoidSetPortValue(DataREG,Copy_u8Data); }

	 }/*end of switch case*/

	 /*Set EN pin 1 (LCD Read data )*/
	 DIO_VoidSetPinValue(ContREG,LCD_EN,DIO_HIGH);
	 //_delay_ms(2);
	 _delay_ms(2);
	 /*Set EN pin 0 (LCD Write data to its reg)*/
	 DIO_VoidSetPinValue(ContREG,LCD_EN,DIO_LOW);

 }/*end of LCD_u8WriteData()*/



/*=================================================================================================
 * 4 Bit Mode
 *=================================================================================================*/

 #elif (LCD_MODE == LCD_4BIT)


/*
 * Prototype   : u8 LCD_voidWriteCommand(u8 Copy_u8Command);
 * Description : write command to LCD
 * Arguments   : u8 Command
 * return      : void
 */
 void LCD_voidWriteCommand(u8 Copy_u8Data)
 {
	 /*Set RW pin 0 (Write Mode selected)*/
	 DIO_VoidSetPinValue(ContREG,LCD_RW,DIO_LOW) ;
	 /*Set RS pin 0 (Instruction register selected)*/
	 DIO_VoidSetPinValue(ContREG,LCD_RS,DIO_LOW) ;
	 /*output first 4 bits instruction data to Data Bus*/
	 for(u8 i=4;i<8;i++)
	 {
		 /*Output value of Instruction bit i at Data Register DIO Pin i*/
		 DIO_VoidSetPinValue(DataREG,i,GET_BIT(Copy_u8Data,i));
	 }
	 /*latch sent data*/
	 /*Set EN pin 1 (LCD Read data )*/
	 DIO_VoidSetPinValue(ContREG,LCD_EN,DIO_HIGH) ;
	 //_delay_ms(2);
	 _delay_ms(2);
	 /*Set EN pin 0 (LCD Write data to its reg)*/
	 DIO_VoidSetPinValue(ContREG,LCD_EN,DIO_LOW) ;

	 /*output second 4 bits instruction to data bus*/
	 for(u8 i=0;i<4;i++)
	 {
		 /*Output value of Instruction bit i at Data Register DIO Pin i*/
		 DIO_VoidSetPinValue(DataREG,i+4,GET_BIT(Copy_u8Data,i));
	 }
	 /*latch sent data*/
	 /*Set EN pin 1 (LCD Read data )*/
	 DIO_VoidSetPinValue(ContREG,LCD_EN,DIO_HIGH) ;
	 //_delay_ms(2);
	 _delay_ms(2);
	 /*Set EN pin 0 (LCD Write data to its reg)*/
	 DIO_VoidSetPinValue(ContREG,LCD_EN,DIO_LOW) ;
 }/*end of LCD_voidWriteCommand()*/


 /*
 * Prototype   : void LCD_voidWriteData(u8 Copy_u8Data);
 * Description : write Data to LCD
 * Arguments   : u8 Data
 * return      : void
 */
 void LCD_voidWriteData(u8 Copy_u8Data)
 {
	 /*Set RW pin 0 (Write Mode selected)*/
	 DIO_VoidSetPinValue(ContREG,LCD_RW,DIO_LOW) ;
	 /*Set RS pin 1 (Data register selected)*/
	 DIO_VoidSetPinValue(ContREG,LCD_RS,DIO_HIGH) ;
	 /*output first 4 Data bits to Data Bus*/
	 for(u8 i=4;i<8;i++)
	 {
		 /*Output value of Data bit i at Data register DIO Pin i*/
		 DIO_VoidSetPinValue(DataREG,i,GET_BIT(Copy_u8Data,i));
	 }
	 /*latch sent data*/
	 /*Set EN pin 1 (LCD Read data )*/
	 DIO_VoidSetPinValue(ContREG,LCD_EN,DIO_HIGH) ;
	 //_delay_ms(2);
	 _delay_ms(2);
	 /*Set EN pin 0 (LCD Write data to its reg)*/
	 DIO_VoidSetPinValue(ContREG,LCD_EN,DIO_LOW) ;

	 /*output second 4 bits Data to data bus*/
	 for(u8 i=0;i<4;i++)
	 {
		 /*Output value of Data bit i at Data register DIO Pin i*/
		 DIO_VoidSetPinValue(DataREG,i+4,GET_BIT(Copy_u8Data,i));
	 }
	 /*latch sent data*/
	 /*Set EN pin 1 (LCD Read data)*/
	 DIO_VoidSetPinValue(ContREG,LCD_EN,DIO_HIGH) ;
	 //_delay_ms(2);
	 _delay_ms(2);
	 /*Set EN pin 0 (LCD Write data to its reg)*/
	 DIO_VoidSetPinValue(ContREG,LCD_EN,DIO_LOW) ;

 }/*end of LCD_voidWriteData()*/


#endif /*end of Mode select*/


/*
 * Prototype   : void LCD_voidInitializeLCD(void);
 * Description : Initialize LCD in a desired data and control registers
 *               in 4 bit mode control and data register must be the same register
 * Arguments   : void
 * return      : void
 */
 void LCD_voidInitializeLCD(void)
 {
	 /*==============================================================
	  * Configure LCD pins direction
	  *==============================================================*/
	 /*Configure RS Pin output*/
	 DIO_VoidSetPinDirection(ContREG,LCD_RS,DIO_OUTPUT_PIN);
	 /*Configure RW Pin output*/
	 DIO_VoidSetPinDirection(ContREG,LCD_RW,DIO_OUTPUT_PIN);
	 /*Configure EN Pin output*/
	 DIO_VoidSetPinDirection(ContREG,LCD_EN,DIO_OUTPUT_PIN);
	 /*Configure Data register output*/
	 DIO_VoidSetPortDirection(DataREG,DIO_OUTPUT_PIN);
	 //_delay_ms(50);
	 _delay_ms(50);

	 /*==============================================================
	  * Choose font size and number of lines
	  *==============================================================*/
	 /*Set Font size value 5*7 dots or 5*10 dots*/
	  SET_BIT_VALUE(FontSizeAndLineCommand,LCD_FONT_BIT,LCD_FONT_SIZE);
	 /*Set number of lines 1 or 2*/
	  SET_BIT_VALUE(FontSizeAndLineCommand,LCD_LINE_BIT,LCD_LINE_MODE);

	 /*==============================================================
	  * LCD initialization sequence
	  *==============================================================
	  * 8Bit Mode initialization
	  *====================================*/
	 #if (LCD_MODE == LCD_8BIT)
	    /*Choose 8Bit mode in function set instruction*/
		SET_BIT(FontSizeAndLineCommand,LCD_DATALENGTH_BIT);
		/*send Function set instruction*/
		LCD_voidWriteCommand(FontSizeAndLineCommand);
		//_delay_ms(1);
		_delay_ms(1);
	 /*====================================
	  * 4Bit Mode initialization
	  *====================================*/
     #elif (LCD_MODE == LCD_4BIT)
		/*send 4BIT Function set instruction two times*/
		LCD_voidWriteCommand(LCD_FN_SET_4BIT);
		/*send Function set instruction for font and number of lines*/
		LCD_voidWriteCommand(FontSizeAndLineCommand);
		//_delay_ms(1);
		_delay_ms(1);
	 #endif

	 /*send Display ON OFF instruction*/
	 LCD_voidWriteCommand(DisplayAndCursorCommand);
	 //_delay_ms(1);
	 _delay_ms(1);
	 /*send Display clear instruction*/
	 LCD_voidWriteCommand(LCD_DISP_CLEAR);
	 //_delay_ms(2);
	 _delay_ms(2);
	 /*send ENTRY MODE set instruction*/
	 LCD_voidWriteCommand(LCD_ENTRY_MODE);
	 //_delay_ms(2);
	 _delay_ms(2);

	 /*=============================================================================
	  * Initialize custom made characters with pre-configured arrays' values
	  *=============================================================================*/
	 /*jump to CGRAM address*/
	 LCD_voidWriteCommand(LCD_CGRAM_ADDRESS);

	 /*fill GCRAM with LCD_u8CustomCharArray values*/
	 for (u8 i = 0 ; i < 8 ; i++)
	 {
		 for (u8 j = 0 ; j < 8 ; j++)
		 {
			 LCD_voidWriteData(LCD_u8CustomCharArray[i][j]);

		 }/*end of j loop*/

	 }/*end of i loop*/

	 /*return to DDRAM address 1*/
	 LCD_voidWriteCommand(LCD_DDRAM_ADD1);

 }/*end of LCD_u8InitializeLCD()*/


 /*
  * Prototype   : void LCD_voidClearLCD(void);
  * Description : clear LCD and return cursor to first position
  * Arguments   : void
  * return      : void
  */
  void LCD_voidClearLCD(void)
  {
	  /*send Display clear instruction*/
	  LCD_voidWriteCommand(LCD_DISP_CLEAR);

  }/*end of LCD_voidClearLCD()*/

 /*
  * Prototype   : void LCD_voidReturnHome(void);
  * Description : return cursor to first position LCD content doesn't affect
  * Arguments   : void
  * return      : void
  */
  void LCD_voidReturnHome(void)
  {
	  /*send Return home instruction*/
	  LCD_voidWriteCommand(LCD_RET_HOME);

  }/*end of LCD_voidReturnHome()*/

 /*
  * Prototype   : void LCD_voidSelectLine(u8 Copy_u8Line);
  * Description : Select line 1 or 2 in LCD
  * Arguments   : choose line from (LCD_LINE1 or LCD_LINE2)
  * return      : void
  */
  void LCD_voidSelectLine(u8 Copy_u8Line)
  {
	  /*choose line*/
	  switch(Copy_u8Line)
	  {
		  case LCD_LINE1 : {  LCD_voidWriteCommand(LCD_DDRAM_ADD1); } break;
		  case LCD_LINE2 : {  LCD_voidWriteCommand(LCD_DDRAM_ADD2); } break;

	  }/*end of line switch case*/

  }/*end of LCD_voidSelectLine()*/

 /*
  * Prototype   : void LCD_voidSetCursorPosition(u8 Copy_u8Line,u8 Copy_u8Position);
  * Description : set cursor in specific position (choose line and position in line from 1 to 16)
  * Arguments   : line LCD_LINE1 or LCD_LINE2
  *               Position from 1 to 16
  * return      : void
  */
  void LCD_voidSetCursorPosition(u8 Copy_u8Line,u8 Copy_u8Position)
  {
	  /*choose line*/
	  switch(Copy_u8Line)
	  {
		  case LCD_LINE1 : { LCD_voidWriteCommand(LCD_DDRAM_ADD1+ Copy_u8Position -1); } break;
		  case LCD_LINE2 : { LCD_voidWriteCommand(LCD_DDRAM_ADD2+ Copy_u8Position -1); } break;

	  }/*end of line switch case*/

  }/*end of LCD_voidSetCursorPosition()*/

 /*
  * Prototype   : void LCD_voidDisplayChar(u8 Copy_u8CharData);
  * Description : Output character to current cursor position
  * Arguments   : Char_Data : Character to be displayed a number (0-9) or a character
  * return      : void
  */
  void LCD_voidDisplayChar(u8 Copy_u8CharData)
  {
	  /*check character type*/
	  if( (Copy_u8CharData >= 0) && (Copy_u8CharData < 10) )
	  {
		  /*if character is number*/
		  LCD_voidWriteData((Copy_u8CharData+'0'));

	  }
	  else
	  {
		  /*if character is char*/
		  LCD_voidWriteData(Copy_u8CharData);

	  }/*end of character type check*/


  }/*end of LCD_voidDisplayChar*/

 /*
  * Prototype   : void LCD_voidDisplayChar(u8 Copy_u8CharData);
  * Description : Output String or a number to LCD at current cursor position
  * Arguments   : DataPointer: pointer to data stream to be displayed it could be
  *               - Number of type u32 but function can handle up to 10 digit number (0,1,...,4294967296)
  *               - u8 character string
  *			      Data type: LCD_NUMBER or LCD_STRING
  * return      : void
  */
  void LCD_voidDisplayString(char  *Copy_u32StringDataPtr)
  {
	  u8 count=0;
		//while you don't reach to the end of your string enter the loop
		while(( Copy_u32StringDataPtr[count])!='\0')
		{
			//print the selected char
			LCD_voidDisplayChar(Copy_u32StringDataPtr[count]);
			//increment to print the next char
			count++;
		}
  }
 /*
  * Prototype   : void LCD_voidShiftRight(void);
  * Description : Shift all display right one step
  * Arguments   : void
  * return      : void
  */
  void LCD_voidShiftRight(void)
  {
	  /*send shift right instruction*/
	  LCD_voidWriteCommand(LCD_DISP_SHIFT_RIGHT);

  }/*end of LCD_voidShiftRight()*/

 /*
  * Prototype   : void LCD_voidShiftLeft(void);
  * Description : Shift all display left one step
  * Arguments   : void
  * return      : void
  */
  void LCD_voidShiftLeft(void)
  {
	 /*send shift left instruction*/
	 LCD_voidWriteCommand(LCD_DISP_SHIFT_LEFT);

  }/*end of LCD_voidShiftLeft()*/

 /*
  * Prototype   : void LCD_voidCursorShiftRight(u8 Copy_u8Steps);
  * Description : shift cursor position number of steps right
  * Arguments   : Number of Steps
  * return      : void
  */
  void LCD_voidCursorShiftRight(u8 Copy_u8Steps)
  {
	  /*loop steps*/
	  for(u8 i = 0 ; i < Copy_u8Steps ; i++)
	  {
		  /*Shift cursor one step right instruction*/
		  LCD_voidWriteCommand(LCD_CURSOR_SHIFT_RIGHT);

	  }/*end of steps for loop*/

  }/*end of LCD_voidCursorShiftRight()*/

 /*
  * Prototype   : void LCD_voidCursorShiftLeft(u8 Copy_u8Steps);
  * Description : shift cursor position number of steps Left
  * Arguments   : Number of Steps
  * return      : void
  */
  void LCD_voidCursorShiftLeft(u8 Copy_u8Steps)
  {
	  /*loop steps*/
	  for(u8 i = 0 ; i < Copy_u8Steps ; i++)
	  {
		  /*Shift cursor one step Left instruction*/
		  LCD_voidWriteCommand(LCD_CURSOR_SHIFT_LEFT);

	  }/*end of steps for loop*/

  }/*end of LCD_voidCursorShiftLeft()*/

 /*
  * Prototype   : void LCD_voidCursorDisplayOnOff(u8 Copy_u8Status);
  * Description : set cursor display on and off
  * Arguments   : Status : LCD_ON or LCD_OFF
  * return      : void
  */
  void LCD_voidCursorDisplayOnOff(u8 Copy_u8Status)
  {
	  /*Set Display status value (on or off)*/
	  SET_BIT_VALUE(DisplayAndCursorCommand,LCD_CURSOR_BIT,Copy_u8Status);
	  /*Send command*/
	  LCD_voidWriteCommand(DisplayAndCursorCommand);

  }/*end of LCD_voidCursorDisplayOnOff()*/

 /*
  * Prototype   : void LCD_voidCursorBlinkOnOff(u8 Copy_u8Status);
  * Description : set cursor blinking on and off
  * Arguments   : Status : LCD_ON or LCD_OFF
  * return      : void
  */
  void LCD_voidCursorBlinkOnOff(u8 Copy_u8Status)
  {
	  /*Set Cursor status value (on or off)*/
	  SET_BIT_VALUE(DisplayAndCursorCommand,LCD_BLINK_BIT,Copy_u8Status);
	  /*Send command*/
	  LCD_voidWriteCommand(DisplayAndCursorCommand);

  }/*end of LCD_voidCursorBlinkOnOff()*/


 /*
  * Prototype   : void LCD_voidScreenDisplayOnOff(u8 Copy_u8Status);
  * Description : set Whole display on & off
  * Arguments   : Status : LCD_ON or LCD_OFF
  * return      : void
  */
  void LCD_voidScreenDisplayOnOff(u8 Copy_u8Status)
  {
	  /*Set Display status value (on or off)*/
	  SET_BIT_VALUE(DisplayAndCursorCommand,LCD_DISP_BIT,Copy_u8Status);
	  /*Send command*/
	  LCD_voidWriteCommand(DisplayAndCursorCommand);
	  
  }/*end of LCD_voidDisplayOnOff()*/

 /* 
  * Prototype   : void LCD_voidDisplayCustomChar(u8 Copy_SlotNumber);
  * Description : use custom character from CGRAM
  * Arguments   : slot number : from (LCD_CUST_CHAR_1, LCD_CUST_CHAR_2,...LCD_CUST_CHAR_8)
  * return      : void  
  */
  void LCD_voidDisplayCustomChar(u8 Copy_SlotNumber)
  {
	  /*slot in range check*/
	  if ( (Copy_SlotNumber >= 0) && (Copy_SlotNumber<8) )
	  {
		  /*Display Custom character in that slot*/
		  LCD_voidWriteData(Copy_SlotNumber);
		
	  }/*end of slot number range check*/
	  
  }/*end of LCD_voidDisplayCustomChar()*/


