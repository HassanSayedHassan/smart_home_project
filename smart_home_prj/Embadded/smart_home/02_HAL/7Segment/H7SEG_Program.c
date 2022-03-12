#include "../../04_LIB/STD_TYPES.h"
#include "../../04_LIB/BIT_MATH.h"
#include "../../03_MCAL/DIO_Driver/DIO_Interface.h"
#include "H7SEG_Private.h"
#include "H7SEG_Interface.h"

void H7SEG_VoidInit(u8 Copy_U8Port)
{

    DIO_VoidSetPortDirection(Copy_U8Port,DIO_OUTPUT_PORT);
}

void H7SEG_VoidDisplayNumber(u8 Copy_U8Port,u8 Copy_u8DisplayNumber)
{

    DIO_VoidSetPortValue(Copy_U8Port,H7SEG_u8SevenSegArray[Copy_u8DisplayNumber]);

}
