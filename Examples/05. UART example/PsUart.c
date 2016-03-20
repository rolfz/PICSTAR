/*
   Title:    UART TEST
   Purpose:  use the UART module with PICKIT2 on Starlet N2
   File name: St_Uart.c
   Version: 1.0

   by: Rolf Ziegler
	   date: June.2010

   description: PICKIT2 can be used to debug software, alternatively use the UART for other purposes

	The routine shows how to initalize the UART and various ways to print out data.

	Check the Microchip MCC18 library i.e. usart.h for more détails.
			
*/
#include <p18f4550.h>
#include <stdio.h>
#include <usart.h>
#include <delays.h>


#include "..\shared\picstar_def.h"
#include "..\shared\picstar_ini.h"
#include "..\shared\picstar_delays.h"
#include "..\shared\picstar_sound.h"
#include "..\shared\uart_baud.h"

// main application code
void main()
{
	u8 counter=0;
	char str[20];
//	TRISBbits.TRISB7=0;

	init_picstar();
	init_buzzer();
	init_bPous;


// Configure Hardware USART 
	OpenUSART( USART_TX_INT_OFF &
		USART_RX_INT_OFF &
		USART_ASYNCH_MODE &
		USART_EIGHT_BIT &
		USART_CONT_RX &
		USART_BRGH_LOW,
		BAUD19200);     //check the uard_baud.h file for available baud rates.

	bip();
// let's wait until we powered the PICKIT2
	delay_ms(2000); 

// print from ROM
    putrsUSART( "\r\nHello World!\r\n" ); 

// main loop
	while(1)
	{
		if(bPous==0)
		{
//	bip();

// print from variable string
	sprintf(str,"counter= %u \r\n", counter++);
	putsUSART(str);

	delay_ms(1000);
		}
	} // end of main loop
}
// end of program

