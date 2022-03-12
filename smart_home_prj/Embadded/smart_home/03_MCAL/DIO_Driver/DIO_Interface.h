#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_

/* Port Defines */
#define DIO_PORTA		0
#define DIO_PORTB		1
#define DIO_PORTC		2
#define DIO_PORTD		3

#define DIO_PIN0		0
#define DIO_PIN1		1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7


/* Digital I/O value */
#define DIO_HIGH		1
#define DIO_LOW		0

/* Digital I/O Direction */
#define DIO_INPUT_PORT		0x00
#define DIO_OUTPUT_PORT	0xFF

#define DIO_INPUT_PIN		0x00
#define DIO_OUTPUT_PIN	0x01

#define DIO_EN_PULL_UP_RES     1
#define DIO_DIS_PULL_UP_RES    0

/* Functions Prototypes */
void DIO_VoidSetPinDirection(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Direction);
void DIO_VoidSetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Value);

void DIO_VoidSetPortDirection(u8 Copy_U8Port,u8 Copy_U8Direction);
void DIO_VoidSetPortValue(u8 Copy_U8Port,u8 Copy_U8Value);

void DIO_VoidTogglePin(u8 Copy_U8Port,u8 Copy_U8Pin);
u8   DIO_U8GetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin);

#endif
