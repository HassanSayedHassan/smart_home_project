#ifndef __EXTI_Interface_h__
#define __EXTI_Interface_h__


/*Interrupt number*/
#define INT0    (u8)0
#define INT1    (u8)1
#define INT2    (u8)2


/*Interrupt status*/
#define Enable 1
#define Disable 0


//Interrupt modes
#define LOW_MOOD            1
#define ON_CHANGE_MOOD      2
#define FAILING_EDGE_MOOD   3
#define RAISING_EDGE_MOOD   4


/*Function Prototypes*/

/*
 * Prototype   : void EXTI_VoidINTInit(u8 Copy_u8INT);
 * Description : Initialize  INT using pre processing directive [ Mood , Status]
 * Arguments   : u8 INT_Number      [INT0, INT1, INT2]
 * return      : void
 */
void EXTI_VoidINTInit(u8 Copy_u8INT_Number);


/*
 * Prototype   : void EXTI_VoidINTEnable(u8 Copy_u8INT);
 * Description : Enable  INT at Run time
 * Arguments   : u8 Copy_u8INT_Number      [INT0, INT1, INT2]
 * return      : void
 */
void EXTI_VoidINTEnable(u8 Copy_u8INT_Number);

/*
 * Prototype   : void EXTI_VoidINTEnable(u8 Copy_u8INT);
 * Description : Disable  INT at Run time
 * Arguments   : u8 Copy_u8INT_Number      [INT0, INT1, INT2]
 * return      : void
 */
void EXTI_VoidINTDisable(u8 Copy_u8INT_Number);

/*
 * Prototype   : void EXTI_VoidINTEnable(u8 Copy_u8INT);
 * Description : Change Mood of   INT at Run time
 * Arguments   : u8 Copy_u8INT_Number      [INT0, INT1, INT2]
               : u8 Copy_u8NewMood
                        iF choose INT0,INT1 ==> RAISING_EDGE_MOOD  FAILING_EDGE_MOOD  LOW_MOOD  ON_CHANGE_MOOD
                        iF choose INT0,INT2 ==> RAISING_EDGE_MOOD  FAILING_EDGE_MOOD
 * return      : void
 */
void EXTI_VoidINTChangeMood(u8 Copy_u8INT_Number,u8 Copy_u8NewMood);


/*
 * Prototype   : void EXTI_VoidINTSetCallBackFunc(u8 Copy_u8INT_Number,void(* Copy_CallBackFunc)(void));
 * Description : Set Call Back Func  of   INT at Run time
 * Arguments   : u8 Copy_u8INT_Number                [INT0, INT1, INT2]
               : void(* Copy_CallBackFunc)(void)     pointer point To Call Back Func
 * return      : void
 */
void EXTI_VoidINTSetCallBackFunc(u8 Copy_u8INT_Number,void(* Copy_CallBackFunc)(void));



#endif
