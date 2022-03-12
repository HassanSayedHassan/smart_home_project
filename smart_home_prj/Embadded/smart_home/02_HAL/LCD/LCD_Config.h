/*****************************************************/
/**********       Author : Hassan Sayed      **********/
/**********       Layer  : HAL             **********/
/**********       Version: 1.00              *********/
/**********       Date   : 23-10-2022       **********/
/*****************************************************/
/*****************************************************/




#ifndef __LCD_CONFIG_h__
#define __LCD_CONFIG_h__

/* 
 * Choose LCD Data length Mode :
 * LCD_8BIT or LCD_4BIT
 */
 #define LCD_MODE		  LCD_8BIT

/* 
 * Choose LCD Number of lines :
 * LCD_ONE_LINE or LCD_TWO_LINES
 */
 #define LCD_LINE_MODE   LCD_TWO_LINES
 
 /* 
 * Choose LCD Font size:
 * LCD_7_DOTS or LCD_10_DOTS
 * 10 dots size ONLY work with one line mode 
 */
 #define LCD_FONT_SIZE   LCD_7_DOTS

/*============================================================================
 * LCD Connections
 *============================================================================
 * in 4Bit mode:
 * - Control  and data registers must be the same
 * - Data bits are connected D4->Bit4 D5->Bit5 D6->Bit6 D7->Bit7
 */
#define ContREG  DIO_PORTD
#define DataREG  DIO_PORTC

/*Define Register selector pin*/  
#define LCD_RS 7
/*Define Register selector pin*/ 
#define LCD_RW 6
/*Define Register selector pin*/  
#define LCD_EN 5


/* 
 * Custom made characters arrays
 * you can add new custom char by assigning new value for array 
 * there are 8 available custom char slots 
 * ex: custom made arrow at first custom made slot 
 * const u8 LCD_u8Custom_Char1[8] = {0b00010000,
 *									  0b00111000,
 *									  0b01111100,
 *									  0b11010110,
 *									  0b10010001,
 * 									  0b10010001,
 *									  0b00010000,
 *									  0b00000000}; 
 */
const u8 LCD_u8CustomCharArray[8][8] =

/*LCD_u8Custom_Char1*/			  {{0b00000000,
								    0b00001010,
									0b00011111,
									0b00011111,
									0b00001110,
									0b00000100,
									0b00000000,
									0b00000000},

/*LCD_u8Custom_Char2*/			   {0b00000100,
									0b00001110,
									0b00010101,
									0b00010101,
									0b00000100,
									0b00000100,
									0b00000000,
									0b00000000},
				   				   
/*LCD_u8Custom_Char3*/			   {0b00001110,
									0b00011111,
									0b00011111,
									0b00011111,
									0b00000000,
									0b00001110,
									0b00000000,
									0b00000000},

/*LCD_u8Custom_Char4*/			   {0b00000000,
									0b00000100,
									0b00001110,
									0b00011111,
									0b00001110,
									0b00000100,
									0b00000000,
									0b00000000},

/*LCD_u8Custom_Char5*/			   {0b00000100,
									0b00001110,
									0b00011111,
									0b00011011,
									0b00010001,
									0b00000000,
									0b00000000,
									0b00000000},

/*LCD_u8Custom_Char6*/			   {0b00010001,
									0b00011011,
									0b00001110,
									0b00000100,
									0b00001110,
									0b00011011,
									0b00010001,
									0b00000000},

/*LCD_u8Custom_Char7*/			   {0b00011111,
									0b00010101,
									0b00010101,
									0b00011111,
									0b00010101,
									0b00010101,
									0b00011111,
									0b00000000},

/*LCD_u8Custom_Char8*/			   {0b00001110,
									0b00011101,
									0b00011001,
									0b00011111,
									0b00001110,
									0b00000000,
									0b00011111,
									0b00000000}};


#endif


/*==============================================================================================================================================
 * EOF 
 *==============================================================================================================================================*/
