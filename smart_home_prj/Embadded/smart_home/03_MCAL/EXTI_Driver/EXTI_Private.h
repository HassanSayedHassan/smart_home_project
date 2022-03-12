/*
 External Interrupt Private File
 */
#ifndef __EXTI_Private_h__
#define __EXTI_Private_h__


/* Registers And Pins*/

#define GICR_REG              (*(volatile u8 *)(0x5B))  //General interrupt control reg Definition
#define GICR_INT0             6     //External Interrupt Request 0 Enable
#define GICR_INT1             7     //External Interrupt Request 1 Enable
#define GICR_INT2             5     //External Interrupt Request 2 Enable

#define GIFR_REG             (*(volatile u8 *)(0x5A)) //General interrupt flag reg Definition
#define GIFR_INT0             6     //External Interrupt Request 0 Flag
#define GIFR_INT1             7     //External Interrupt Request 1 Flag
#define GIFR_INT2             5     //External Interrupt Request 2 Flag

#define MCUCR_REG            (*(volatile u8 *)(0x55)) //Micro controller Unit control reg Definition
#define MCUCR_ISC00          0         //Interrupt 0 Sense Control bit 0
#define MCUCR_ISC01          1         //Interrupt 0 Sense Control bit 1
#define MCUCR_ISC10          2         //Interrupt 1 Sense Control bit 1
#define MCUCR_ISC11          3         //Interrupt 1 Sense Control bit 1

#define MCUCSR_REG          (*(volatile u8 *)(0x54)) //Micro controller Unit control and status reg Definition
#define MCUCSR_ISC2          6      //Interrupt 2 Sense Control bit









#endif
