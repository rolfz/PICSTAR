/*
   Title: my1stproject.c
   Purpose: example to star C18 programming
   Version: 1.0
   Autor:
   Date: 

   description: my 1st program
*/
#include <p18f4550.h>   
#include "..\shared\picstar_def.h"
#include "..\shared\picstar_ini.h"
#include "..\shared\picstar_delays.h"

void main()
{
	init_picstar();
	PORTB=0; // we initalize PORTB
	TRISB=0x3F;   // we set PORTB  bits 6-7 as output

	while(1)
	{
	PORTB+=64;
	delay_ms(500);
	} // end while
}// fin of program
