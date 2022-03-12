/*****************************************************/
/*****************************************************/
/**********       Author : Hassan Syed      **********/
/**********       Layer  : MCAL             **********/
/**********       File   : PORT_Config.h    **********/
/**********       Version: 1.00              *********/
/**********       Date   : 23-10-2022       **********/
/*****************************************************/
/*****************************************************/
#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_



/*

 OUTPUT 1
 INPUT  0

 */
#define PORTA_PIN0_DIR   OUTPUT
#define PORTA_PIN1_DIR   OUTPUT
#define PORTA_PIN2_DIR   OUTPUT
#define PORTA_PIN3_DIR   OUTPUT
#define PORTA_PIN4_DIR   OUTPUT
#define PORTA_PIN5_DIR   OUTPUT
#define PORTA_PIN6_DIR   OUTPUT
#define PORTA_PIN7_DIR   OUTPUT


#define PORTB_PIN0_DIR   OUTPUT
#define PORTB_PIN1_DIR   OUTPUT
#define PORTB_PIN2_DIR   OUTPUT
#define PORTB_PIN3_DIR   OUTPUT
#define PORTB_PIN4_DIR   OUTPUT
#define PORTB_PIN5_DIR   OUTPUT
#define PORTB_PIN6_DIR   OUTPUT
#define PORTB_PIN7_DIR   OUTPUT


#define PORTC_PIN0_DIR    OUTPUT
#define PORTC_PIN1_DIR    OUTPUT
#define PORTC_PIN2_DIR    OUTPUT
#define PORTC_PIN3_DIR    OUTPUT
#define PORTC_PIN4_DIR    OUTPUT
#define PORTC_PIN5_DIR    OUTPUT
#define PORTC_PIN6_DIR    OUTPUT
#define PORTC_PIN7_DIR    OUTPUT


#define PORTD_PIN0_DIR    INPUT
#define PORTD_PIN1_DIR    OUTPUT
#define PORTD_PIN2_DIR    INPUT
#define PORTD_PIN3_DIR    OUTPUT
#define PORTD_PIN4_DIR    OUTPUT
#define PORTD_PIN5_DIR    OUTPUT
#define PORTD_PIN6_DIR    OUTPUT
#define PORTD_PIN7_DIR    OUTPUT


/*
 
IF OUTPUT:-
        LOW  0
        HIGH 1
        
IF INPUT
        PULL_UP   1
        NORMAL_IN 0
 
 */
#define PORTA_PIN0_INITIAL_VALUE  HIGH
#define PORTA_PIN1_INITIAL_VALUE  HIGH
#define PORTA_PIN2_INITIAL_VALUE  HIGH
#define PORTA_PIN3_INITIAL_VALUE  HIGH
#define PORTA_PIN4_INITIAL_VALUE  HIGH
#define PORTA_PIN5_INITIAL_VALUE  HIGH
#define PORTA_PIN6_INITIAL_VALUE  HIGH
#define PORTA_PIN7_INITIAL_VALUE  HIGH


#define PORTB_PIN0_INITIAL_VALUE  LOW
#define PORTB_PIN1_INITIAL_VALUE  LOW
#define PORTB_PIN2_INITIAL_VALUE  LOW
#define PORTB_PIN3_INITIAL_VALUE  LOW
#define PORTB_PIN4_INITIAL_VALUE  LOW
#define PORTB_PIN5_INITIAL_VALUE  LOW
#define PORTB_PIN6_INITIAL_VALUE  LOW
#define PORTB_PIN7_INITIAL_VALUE  LOW


#define PORTC_PIN0_INITIAL_VALUE  LOW
#define PORTC_PIN1_INITIAL_VALUE  LOW
#define PORTC_PIN2_INITIAL_VALUE  LOW
#define PORTC_PIN3_INITIAL_VALUE  LOW
#define PORTC_PIN4_INITIAL_VALUE  LOW
#define PORTC_PIN5_INITIAL_VALUE  LOW
#define PORTC_PIN6_INITIAL_VALUE  LOW
#define PORTC_PIN7_INITIAL_VALUE  LOW


#define PORTD_PIN0_INITIAL_VALUE  HIGH
#define PORTD_PIN1_INITIAL_VALUE  HIGH
#define PORTD_PIN2_INITIAL_VALUE  PULL_UP
#define PORTD_PIN3_INITIAL_VALUE  HIGH
#define PORTD_PIN4_INITIAL_VALUE  HIGH
#define PORTD_PIN5_INITIAL_VALUE  HIGH
#define PORTD_PIN6_INITIAL_VALUE  HIGH
#define PORTD_PIN7_INITIAL_VALUE  HIGH


#endif /* PORT_CONFIG_H_ */
