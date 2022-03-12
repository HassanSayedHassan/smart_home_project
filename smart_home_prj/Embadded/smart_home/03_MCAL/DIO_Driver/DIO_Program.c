#include "../../04_LIB/STD_TYPES.h"
#include "../../04_LIB/BIT_MATH.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"

void DIO_VoidSetPinDirection(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Direction)
{
	if(Copy_U8Direction==DIO_INPUT_PIN)
	{
		switch(Copy_U8Port)
		{
			case DIO_PORTB: CLR_BIT(DDRB_REG,Copy_U8Pin); break ;
			case DIO_PORTC: CLR_BIT(DDRC_REG,Copy_U8Pin); break ;
			case DIO_PORTD: CLR_BIT(DDRD_REG,Copy_U8Pin); break ;
		}
		
	}
	else if(Copy_U8Direction==DIO_OUTPUT_PIN)
	{
		switch(Copy_U8Port)
		{
			case DIO_PORTA: SET_BIT(DDRA_REG,Copy_U8Pin); break ;
			case DIO_PORTB: SET_BIT(DDRB_REG,Copy_U8Pin); break ;
			case DIO_PORTC: SET_BIT(DDRC_REG,Copy_U8Pin); break ;
			case DIO_PORTD: SET_BIT(DDRD_REG,Copy_U8Pin); break ;
		}
		
	}
		
}

void DIO_VoidSetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Value)
{
    if(Copy_U8Value==DIO_HIGH)
    {
        switch (Copy_U8Port)
        {
            case DIO_PORTA: SET_BIT(PORTA_REG,Copy_U8Pin); break;
            case DIO_PORTB: SET_BIT(PORTB_REG,Copy_U8Pin); break;
            case DIO_PORTC: SET_BIT(PORTC_REG,Copy_U8Pin); break;
            case DIO_PORTD: SET_BIT(PORTD_REG,Copy_U8Pin); break;

        }

    }
    else if(Copy_U8Value==DIO_LOW)
    {
        switch (Copy_U8Port)
        {
            case DIO_PORTA: CLR_BIT(PORTA_REG,Copy_U8Pin); break;
            case DIO_PORTB: CLR_BIT(PORTB_REG,Copy_U8Pin); break;
            case DIO_PORTC: CLR_BIT(PORTC_REG,Copy_U8Pin); break;
            case DIO_PORTD: CLR_BIT(PORTD_REG,Copy_U8Pin); break;

        }

    }

}

void  DIO_VoidSetPortDirection(u8 Copy_U8Port,u8 Copy_U8Direction)
{
    switch (Copy_U8Port)
    {
        case     DIO_PORTA: DDRA_REG = Copy_U8Direction; break;
        case     DIO_PORTB: DDRB_REG = Copy_U8Direction; break;
        case     DIO_PORTC: DDRC_REG = Copy_U8Direction; break;
        case     DIO_PORTD: DDRD_REG = Copy_U8Direction; break;

    }

}

void  DIO_VoidSetPortValue(u8 Copy_U8Port,u8 Copy_U8Value)
{
    switch (Copy_U8Port)
    {
        case     DIO_PORTA: PORTA_REG = Copy_U8Value; break;
        case     DIO_PORTB: PORTB_REG = Copy_U8Value; break;
        case     DIO_PORTC: PORTC_REG = Copy_U8Value; break;
        case     DIO_PORTD: PORTD_REG = Copy_U8Value; break;

    }

}

void  DIO_VoidTogglePin(u8 Copy_U8Port,u8 Copy_U8Pin)
{
    switch (Copy_U8Port)
    {
        case DIO_PORTA: TOGGLE_BIT(PORTA_REG,Copy_U8Pin); break;
        case DIO_PORTB: TOGGLE_BIT(PORTB_REG,Copy_U8Pin); break;
        case DIO_PORTC: TOGGLE_BIT(PORTC_REG,Copy_U8Pin); break;
        case DIO_PORTD: TOGGLE_BIT(PORTD_REG,Copy_U8Pin); break;

    }
}

u8 DIO_U8GetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin)
{
	u8 LOC_ReturnedValue; 			// LOC mean local variable
	switch(Copy_U8Port)
	{
		case DIO_PORTA: LOC_ReturnedValue= GET_BIT(PINA_REG,Copy_U8Pin); break;
		case DIO_PORTB: LOC_ReturnedValue= GET_BIT(PINB_REG,Copy_U8Pin); break;
		case DIO_PORTC: LOC_ReturnedValue= GET_BIT(PINC_REG,Copy_U8Pin); break;
		case DIO_PORTD: LOC_ReturnedValue= GET_BIT(PIND_REG,Copy_U8Pin); break;
	}
	
	return LOC_ReturnedValue;
}








