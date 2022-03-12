#ifndef __EXTI_Config_h__
#define __EXTI_Config_h__

/*
                      -----------------------
                PB0   | 1                40 |
                PB1   | 2                39 |
        (INT2)  PB2   | 3                38 |
                PB3   | 4                37 |
                PB4   | 5                36 |
                PB5   | 6                35 |
                PB6   | 7                34 |
                PB7   | 8                33 |
                      | 9                32 |
                      | 10               31 |
                      | 11               30 |
                      | 12               29 |
                      | 13               28 |
                PD0   | 14               27 |
                PD1   | 15               26 |
         (INT0) PD2   | 16               25 |
         (INT1) PD3   | 17               24 |
                PD4   | 18               23 |
                PD5   | 19               22 |
                PD6   | 20               21 |
                      -----------------------

 */




/*Interrupt moods*/
/*
 Options of INT0,INT1:
     RAISING_EDGE_MOOD  FAILING_EDGE_MOOD  LOW_MOOD  ON_CHANGE_MOOD
 Options of INT2
      RAISING_EDGE_MOOD  FAILING_EDGE_MOOD
*/
#define INT0_MOOD  FAILING_EDGE_MOOD
#define INT1_MOOD  LOW_MOOD
#define INT2_MOOD  FAILING_EDGE_MOOD

/*Interrupt status*/
/*
 Options :
    Enable
    Disable
*/


#define INT0_STATUS  Enable
#define INT1_STATUS  Enable
#define INT2_STATUS  Enable



#endif
