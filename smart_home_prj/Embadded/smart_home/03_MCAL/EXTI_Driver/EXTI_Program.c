#include "../../04_LIB/STD_TYPES.h"
#include "../../04_LIB/BIT_MATH.h"
#include "EXTI_Private.h"
#include "EXTI_Interface.h"
#include "EXTI_Config.h"



static void   (*EXTI_CallBackFunc[3])(void )= {NULL};
/*
static void   (*EXTI0_CallBackFunc)(void )= NULL;
static void   (*EXTI1_CallBackFunc)(void )= NULL;
static void   (*EXTI2_CallBackFunc)(void )= NULL;
*/

/*
 * Prototype   : void EXTI_VoidINTInit(u8 Copy_u8INT);
 * Description : Initialize  INT using pre processing directive [ Mood , Status]
 * Arguments   : u8 INT_Number      [INT0, INT1, INT2]
 * return      : void
 */
void EXTI_VoidINTInit(u8 Copy_u8INT_Number)
{
    switch (Copy_u8INT_Number)
    {
        case INT0:
            if (INT0_MOOD==LOW_MOOD )
            {
                CLR_BIT(MCUCR_REG,MCUCR_ISC00);
                CLR_BIT(MCUCR_REG,MCUCR_ISC01);
            }
            else if (INT0_MOOD==ON_CHANGE_MOOD)
            {
                SET_BIT(MCUCR_REG,MCUCR_ISC00);
                CLR_BIT(MCUCR_REG,MCUCR_ISC01);
            }
            else if(INT0_MOOD==FAILING_EDGE_MOOD)
            {
                CLR_BIT(MCUCR_REG,MCUCR_ISC00);
                SET_BIT(MCUCR_REG,MCUCR_ISC01);
            }
            else if(INT0_MOOD==RAISING_EDGE_MOOD)
            {
                SET_BIT(MCUCR_REG,MCUCR_ISC00);
                SET_BIT(MCUCR_REG,MCUCR_ISC01);
            }


            if(INT0_STATUS==Enable)
            {
                SET_BIT(GICR_REG,GICR_INT0);
            }
            else if(INT0_STATUS==Disable)
            {
                CLR_BIT(GICR_REG,GICR_INT0);
            }
        break;
        case INT1:
            if(INT1_MOOD==LOW_MOOD)
            {
                CLR_BIT(MCUCR_REG,MCUCR_ISC10);
                CLR_BIT(MCUCR_REG,MCUCR_ISC11);
            }
            else if (INT1_MOOD==ON_CHANGE_MOOD)
            {
                SET_BIT(MCUCR_REG,MCUCR_ISC10);
                CLR_BIT(MCUCR_REG,MCUCR_ISC11);
            }
            else if (INT1_MOOD==FAILING_EDGE_MOOD)
            {
                CLR_BIT(MCUCR_REG,MCUCR_ISC10);
                SET_BIT(MCUCR_REG,MCUCR_ISC11);
            }
            else if (INT1_MOOD==RAISING_EDGE_MOOD)
            {
                SET_BIT(MCUCR_REG,MCUCR_ISC10);
                SET_BIT(MCUCR_REG,MCUCR_ISC11);
            }

            if(INT1_STATUS==Enable)
            {
                SET_BIT(GICR_REG,GICR_INT1);
            }
            else if(INT1_STATUS==Disable)
            {
                CLR_BIT(GICR_REG,GICR_INT1);
            }

     break;

        case INT2:

            if(INT2_MOOD==RAISING_EDGE_MOOD)
            {
                SET_BIT(MCUCSR_REG,MCUCSR_ISC2);
            }

           if(INT2_MOOD==FAILING_EDGE_MOOD)
            {
                CLR_BIT(MCUCSR_REG,MCUCSR_ISC2);
            }


          if(INT2_STATUS==Enable)
          {
              SET_BIT(GICR_REG,GICR_INT2);
          }

          if(INT2_STATUS==Disable)
          {
              CLR_BIT(GICR_REG,GICR_INT2);
          }

            break;
    }
}

/*
 * Prototype   : void EXTI_VoidINTEnable(u8 Copy_u8INT);
 * Description : Enable  INT at Run time
 * Arguments   : u8 Copy_u8INT_Number      [INT0, INT1, INT2]
 * return      : void
 */
void EXTI_VoidINTEnable(u8 Copy_u8INT_Number)
{
    switch (Copy_u8INT_Number)
    {
        case INT0:
            SET_BIT(GICR_REG,GICR_INT0);
            break;
        case INT1:
            SET_BIT(GICR_REG,GICR_INT1);
            break;
        case INT2:
            SET_BIT(GICR_REG,GICR_INT2);
            break;
    }
}

/*
 * Prototype   : void EXTI_VoidINTEnable(u8 Copy_u8INT);
 * Description : Disable  INT at Run time
 * Arguments   : u8 Copy_u8INT_Number      [INT0, INT1, INT2]
 * return      : void
 */
void EXTI_VoidINTDisable(u8 Copy_u8INT_Number)
{
    switch (Copy_u8INT_Number)
    {
        case INT0:
            CLR_BIT(GICR_REG,GICR_INT0);
            break;
        case INT1:
            CLR_BIT(GICR_REG,GICR_INT1);
            break;
        case INT2:
            CLR_BIT(GICR_REG,GICR_INT2);
            break;
    }
}

/*
 * Prototype   : void EXTI_VoidINTEnable(u8 Copy_u8INT);
 * Description : Change Mood of   INT at Run time
 * Arguments   : u8 Copy_u8INT_Number      [INT0, INT1, INT2]
               : u8 Copy_u8NewMood
                        iF choose INT0,INT1 ==> RAISING_EDGE_MOOD  FAILING_EDGE_MOOD  LOW_MOOD  ON_CHANGE_MOOD
                        iF choose INT0,INT2 ==> RAISING_EDGE_MOOD  FAILING_EDGE_MOOD
 * return      : void
 */
void EXTI_VoidINTChangeMood(u8 Copy_u8INT_Number,u8 Copy_u8NewMood)
{
    switch (Copy_u8INT_Number)
    {
        case INT0:
            if (Copy_u8NewMood==LOW_MOOD)
            {
                CLR_BIT(MCUCR_REG,MCUCR_ISC00);
                CLR_BIT(MCUCR_REG,MCUCR_ISC01);
            }
            else if (Copy_u8NewMood==ON_CHANGE_MOOD)
            {
                SET_BIT(MCUCR_REG,MCUCR_ISC00);
                CLR_BIT(MCUCR_REG,MCUCR_ISC01);
            }
            else if (Copy_u8NewMood==FAILING_EDGE_MOOD)
            {
                CLR_BIT(MCUCR_REG,MCUCR_ISC00);
                SET_BIT(MCUCR_REG,MCUCR_ISC01);
            }
            else if (Copy_u8NewMood==RAISING_EDGE_MOOD)
            {
                SET_BIT(MCUCR_REG,MCUCR_ISC00);
                SET_BIT(MCUCR_REG,MCUCR_ISC01);
            }
            break;
        case INT1:
            if (Copy_u8NewMood==LOW_MOOD)
            {
                CLR_BIT(MCUCR_REG,MCUCR_ISC10);
                CLR_BIT(MCUCR_REG,MCUCR_ISC11);
            }
            else if (Copy_u8NewMood==ON_CHANGE_MOOD)
            {
                SET_BIT(MCUCR_REG,MCUCR_ISC10);
                CLR_BIT(MCUCR_REG,MCUCR_ISC11);
            }
            else if (Copy_u8NewMood==FAILING_EDGE_MOOD)
            {
                CLR_BIT(MCUCR_REG,MCUCR_ISC10);
                SET_BIT(MCUCR_REG,MCUCR_ISC11);
            }
            else if (Copy_u8NewMood==RAISING_EDGE_MOOD)
            {
                SET_BIT(MCUCR_REG,MCUCR_ISC10);
                SET_BIT(MCUCR_REG,MCUCR_ISC11);
            }
            break;
        case INT2:
            if (Copy_u8NewMood==RAISING_EDGE_MOOD)
            {
                SET_BIT(MCUCSR_REG,MCUCSR_ISC2);
            }
            else if (Copy_u8NewMood==FAILING_EDGE_MOOD)
            {
                CLR_BIT(MCUCSR_REG,MCUCSR_ISC2);
            }
            break;
    }
}



/*
 * Prototype   : void EXTI_VoidINTSetCallBackFunc(u8 Copy_u8INT_Number,void(* Copy_CallBackFunc)(void));
 * Description : Set Call Back Func  of   INT at Run time
 * Arguments   : u8 Copy_u8INT_Number                [INT0, INT1, INT2]
               : void(* Copy_CallBackFunc)(void)     pointer point To Call Back Func
 * return      : void
 */
void EXTI_VoidINTSetCallBackFunc(u8 Copy_u8INT_Number,void(* Copy_CallBackFunc)(void))
{
    if(Copy_CallBackFunc!=NULL)
    {
        EXTI_CallBackFunc[Copy_u8INT_Number]=Copy_CallBackFunc;
    }

}


void __vector_1(void)  __attribute__((signal));     ///ISR FOR INT 0
void __vector_1(void)
{
    if(EXTI_CallBackFunc[0]!=NULL)
    {
        EXTI_CallBackFunc[0]();
    }
}


void __vector_2(void)  __attribute__((signal));     ///ISR FOR INT 1
void __vector_2(void)
{
    if(EXTI_CallBackFunc[1]!=NULL)
    {
        EXTI_CallBackFunc[1]();
    }
}

void __vector_3(void)  __attribute__((signal));     ///ISR FOR INT 2
void __vector_3(void)
{
    if(EXTI_CallBackFunc[2]!=NULL)
    {
        EXTI_CallBackFunc[2]();
    }
}
