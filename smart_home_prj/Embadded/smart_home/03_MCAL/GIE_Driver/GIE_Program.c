// Copyright (c) 2021. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

/*****************************************************/
/*****************************************************/
/**********       Author : Hassan Syed      **********/
/**********       Layer  : MCAL             **********/
/**********       File   : GIE_Program.c  **********/
/**********       Version: 1.00              *********/
/**********       Date   : 23-10-2022       **********/
/*****************************************************/
/*****************************************************/

#ifndef _GIE_Program_C_
#define _GIE_Program_C_
#include "../../04_LIB/STD_TYPES.h"
#include "../../04_LIB/BIT_MATH.h"
#include "GIE_Private.h"
#include "GIE_Interface.h"
#include "GIE_Configration.h"


void GIE_VoidEnable(void)
{
    SET_BIT(SREG_REG,SREG_I_PIN);
}
void GIE_VoidDisable(void)
{
    CLR_BIT(SREG_REG,SREG_I_PIN);
}



#endif
