/*****************************************************/
/*****************************************************/
/**********       Author : Hassan Sayed      **********/
/**********       Layer  : MCAL             **********/
/**********       File   : PORT_Program.c   **********/
/**********       Version: 1.00              *********/
/**********       Date   : 23-10-2022       **********/
/*****************************************************/
/*****************************************************/

#include "../../04_LIB/STD_TYPES.h"
#include "../../04_LIB/BIT_MATH.h"
#include "PORT_Config.h"
#include "PORT_Interface.h"
#include "PORT_private.h"

void PORT_VoidInit()
{
DDRA_REG=PORTA_DIR;
DDRB_REG=PORTB_DIR;
DDRC_REG=PORTC_DIR;
DDRD_REG=PORTD_DIR;

PORTA_REG_INITIAL=PORTA_INITIAL_VALUE;
PORTB_REG_INITIAL=PORTB_INITIAL_VALUE;
PORTC_REG_INITIAL=PORTC_INITIAL_VALUE;
PORTD_REG_INITIAL=PORTD_INITIAL_VALUE;

}
