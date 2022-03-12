/*****************************************************/
/*****************************************************/
/**********       Author : Hassan Syed      **********/
/**********       Layer  : MCAL             **********/
/**********       File   : PORT_Privete.h   **********/
/**********       Version: 1.00              *********/
/**********       Date   : 23-10-2022       **********/
/*****************************************************/
/*****************************************************/

#ifndef PORT_PRIVATE_H_
#define PORT_PRIVATE_H_

#define CONCAT(b7,b6,b5,b4,b3,b2,b1,b0)       CONC(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)         0b##b7##b6##b5##b4##b3##b2##b1##b0


#define PORTA_DIR  CONCAT(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)
#define PORTB_DIR  CONCAT(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
#define PORTC_DIR  CONCAT(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR)
#define PORTD_DIR  CONCAT(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR)


#define PORTA_INITIAL_VALUE CONCAT(PORTA_PIN7_INITIAL_VALUE,PORTA_PIN6_INITIAL_VALUE,PORTA_PIN5_INITIAL_VALUE,PORTA_PIN4_INITIAL_VALUE,PORTA_PIN3_INITIAL_VALUE,PORTA_PIN2_INITIAL_VALUE,PORTA_PIN1_INITIAL_VALUE,PORTA_PIN0_INITIAL_VALUE)
#define PORTB_INITIAL_VALUE CONCAT(PORTB_PIN7_INITIAL_VALUE,PORTB_PIN6_INITIAL_VALUE,PORTB_PIN5_INITIAL_VALUE,PORTB_PIN4_INITIAL_VALUE,PORTB_PIN3_INITIAL_VALUE,PORTB_PIN2_INITIAL_VALUE,PORTB_PIN1_INITIAL_VALUE,PORTB_PIN0_INITIAL_VALUE)
#define PORTC_INITIAL_VALUE CONCAT(PORTC_PIN7_INITIAL_VALUE,PORTC_PIN6_INITIAL_VALUE,PORTC_PIN5_INITIAL_VALUE,PORTC_PIN4_INITIAL_VALUE,PORTC_PIN3_INITIAL_VALUE,PORTC_PIN2_INITIAL_VALUE,PORTC_PIN1_INITIAL_VALUE,PORTC_PIN0_INITIAL_VALUE)
#define PORTD_INITIAL_VALUE CONCAT(PORTD_PIN7_INITIAL_VALUE,PORTD_PIN6_INITIAL_VALUE,PORTD_PIN5_INITIAL_VALUE,PORTD_PIN4_INITIAL_VALUE,PORTD_PIN3_INITIAL_VALUE,PORTD_PIN2_INITIAL_VALUE,PORTD_PIN1_INITIAL_VALUE,PORTD_PIN0_INITIAL_VALUE)

/* ======================================================
 * PORT Registers && Pins
 ======================================================*/

/* Group A Registers */
#define DDRA_REG                     *((volatile u8*)0x3A)
#define PORTA_REG_INITIAL            *((volatile u8*)0x3B)

/* Group B Registers */
#define DDRB_REG                     *((volatile u8*)0x37)
#define PORTB_REG_INITIAL            *((volatile u8*)0x38)

/* Group C Registers */
#define DDRC_REG                    *((volatile u8*)0x34)
#define PORTC_REG_INITIAL           *((volatile u8*)0x35)

/* Group D Registers */
#define DDRD_REG                    *((volatile u8*)0x31)
#define PORTD_REG_INITIAL           *((volatile u8*)0x32)

#endif
