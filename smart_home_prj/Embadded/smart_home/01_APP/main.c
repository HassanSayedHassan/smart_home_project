#include "../04_LIB/BIT_MATH.h"
#include "../04_LIB/STD_TYPES.h"
#include "../03_MCAL/DIO_Driver/DIO_Interface.h"
#include "../03_MCAL/GIE_Driver/GIE_Interface.h"
#include "../03_MCAL/PORT_Driver/PORT_Interface.h"
#include "../03_MCAL/EXTI_Driver/EXTI_Interface.h"
#include "../03_MCAL/UART_Driver/UART_Interface.h"
#include "local_data.h"
#include <avr/delay.h>
#include <stdlib.h>


u8 isSwitchPressed=0;                                // Global Variable used to check if the stopBuzzer Btn is Pressed Or not
u8 numberOfErrorTrials=0;                           // Global Variable To Count Number of Errors
u8 buzzerIsSounding=0;                              // Global Variable To check if the buzzer is make sound currently or not
void Uart_rx_int(void);                            // Interrupt UART  Call Back Function
void logInFun(void);
void buzzerAlarm(void);                           // Buzzer Sound  Function
void stopBuzzer(void);                           //Buzzer Stop Function
u8 checkUser(u8* userName, u8 *userPass);        // Function To Check if the logged user was saved is system or not


int main(void)
{
    PORT_VoidInit();                                  // Initialize input output port
    UART_voidInitUART();                           // Initialize UART
    GIE_VoidEnable();                               // Initialize  Global Interrupt Enable
	UART_u8SetRXCallBack(&Uart_rx_int);           // Set Call Back Func of UART
    EXTI_VoidINTInit(INT0);                      // Initialize Interrupt zero
    EXTI_VoidINTSetCallBackFunc(INT0,stopBuzzer);        // Set Call Back Func of INT0

    UART_VoidSendString("====== Welcome in Your Smart Home App ======\n");
    logInFun();         // Log in function
    while (1)
    {

    }
    return 0;
}

void logInFun(void)
{
	GIE_VoidDisable();
	UART_VoidSendString("Please Enter your Name\n");
    u8 nameCounter=0;
    u8 passCounter=0;
    u8 userName[25];
    u8 userPass[25];
    u8 readChar='?';
	    while (readChar!=59)  // Read Char till ;  as end of string
	    {
	        readChar = UART_U8ReceiveData();
	    	if(readChar>=25 &&readChar<=200 &&readChar!=59)
	    	{
                userName[nameCounter]=readChar;
                nameCounter++;
                UART_voidSendData(readChar);
	    	}

	    }
    userName[nameCounter]='\0';
    UART_VoidSendString("\nName was Entered \n");


    UART_VoidSendString("Please Enter your Pass\n");
     readChar='?';
    while (readChar!=59)    // Read Char till ;  as end of string
    {
        readChar = UART_U8ReceiveData();
        if(readChar>=25 &&readChar<=200 &&readChar!=59)
        {
            userPass[passCounter]=readChar;
            passCounter++;
            UART_voidSendData(readChar);
        }

    }
    userPass[passCounter]='\0';
    UART_VoidSendString("\nPass was Entered \n");


  u8 returnedValue=  checkUser(userName,userPass);

  if(returnedValue==1)
  {
      numberOfErrorTrials=0;
	  GIE_VoidEnable();
	  UART_VoidSendString("\n Welcome ");
      UART_VoidSendString(userName);
      UART_VoidSendString(" , You can now control your Room \n");

      UART_VoidSendString("=============================\n");
      UART_VoidSendString("Press \'n\' ==> To Led On\n");
      UART_VoidSendString("Press \'f\' ==> To Led Off\n");
      UART_VoidSendString("Press \'r\' ==> To Open Door\n");
      UART_VoidSendString("Press \'l\' ==> To Close Door\n");
      UART_VoidSendString("Press \'0\' ==> To Sign Out\n");
      UART_VoidSendString("=============================\n");
  }
  else
  {
      UART_VoidSendString("Log in Failed\n\n");
	  logInFun();
  }


}


u8 checkUser(u8* userName, u8 *userPass)
{

	numberOfErrorTrials++;
	if(numberOfErrorTrials<3)
        {
        for (int i = 0; i < 10; i++)
            {
                int resultName = strcmp(array[i].name, userName);
                int resultPass = strcmp(array[i].password, userPass);

                if ( resultName == 0 && resultPass==0)
                {
                   return 1;
                }
            }
        return 0;
        }
	else
        {
		  UART_VoidSendString("Buzzer sound \n");
            buzzerAlarm();
            numberOfErrorTrials=0;
            return 0;
        }

}

void Uart_rx_int(void)
{
	u8 	ReadedData = UART_U8ReceiveData();
	if(ReadedData>=48 &&ReadedData<=200 && buzzerIsSounding==0)
	{
		if(ReadedData=='n') //LED ON
		{
            UART_VoidSendString("LED ON\n");
			DIO_VoidSetPinValue(DIO_PORTB, DIO_PIN1, DIO_HIGH);
			DIO_VoidSetPinValue(DIO_PORTB, DIO_PIN2, DIO_HIGH);
			DIO_VoidSetPinValue(DIO_PORTB, DIO_PIN3, DIO_HIGH);

		}
		else if(ReadedData=='f') //LED OFF
		{
            UART_VoidSendString("LED OFF\n");
			DIO_VoidSetPinValue(DIO_PORTB, DIO_PIN1, DIO_LOW);
			DIO_VoidSetPinValue(DIO_PORTB, DIO_PIN2, DIO_LOW);
			DIO_VoidSetPinValue(DIO_PORTB, DIO_PIN3, DIO_LOW);
		}
        else if(ReadedData=='r') //OPEN DOOR
        {
            UART_VoidSendString("Opening door\n");
            DIO_VoidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_LOW);
            DIO_VoidSetPinValue(DIO_PORTB, DIO_PIN5, DIO_HIGH);
            _delay_ms(2500);
            DIO_VoidSetPinValue(DIO_PORTB, DIO_PIN5, DIO_LOW);
        }
        else if(ReadedData=='l') //CLOSE DOOR
        {
            UART_VoidSendString("closing door\n");
            DIO_VoidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_HIGH);
            DIO_VoidSetPinValue(DIO_PORTB, DIO_PIN5, DIO_LOW);
            _delay_ms(2500);
            DIO_VoidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_LOW);

        }
		else if(ReadedData=='o')
        {
			UART_VoidSendString("Log out Successfully\n");
			numberOfErrorTrials=0;
            logInFun();
        }
	}
}

void buzzerAlarm(void)
{
    GIE_VoidEnable();
    /// Time out
    while(isSwitchPressed==0)
    {
        DIO_VoidTogglePin(DIO_PORTB,DIO_PIN0);
        _delay_ms(500);
        buzzerIsSounding=1;
    }
    isSwitchPressed=0;
    buzzerIsSounding=0;
}
void stopBuzzer(void)
{
    DIO_VoidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_LOW);
    isSwitchPressed=1;
}
