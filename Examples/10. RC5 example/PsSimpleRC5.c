/*
	Title: Simple Encoder + motor control
	Purpose: demonstrate how to program a motor with encoder

	File Name: PsSimpleEncoder.c

	By: Rolf Ziegler, Translated from Didel PFM CALM code
	Date: May 2010

*/

#include <p18f4550.h>
#include <delays.h>
#include "..\shared\picstar_def.h"
#include "..\shared\picstar_ini.h"
#include "..\shared\picstar_delays.h"

void main ()
{

	init_picstar();

#define IR_IN PORTBbits.RB4
#define LED PORTDbits.RD0

	TRISBbits.TRISB4=1;
	PORTD=0;
	TRISD=0;

	while(1)
		{
		PORTD=0;
		if(IR_IN)LED=1;
		else LED=0; 	
	
	} // end while 1
} // end main
