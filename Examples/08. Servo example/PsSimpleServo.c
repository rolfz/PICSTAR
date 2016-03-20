/*
	Title: Simple PFM for motor control
	Purpose: demonstrate how to program a simple Frequence Modulation

	File Name: PsSimplePfm.c

	By: Rolf Ziegler, Translated from Didel PFM CALM code
	Date: April 2010

*/

#include <p18f4550.h>
#include <delays.h>
#include "..\shared\picstar_def.h"
#include "..\shared\picstar_ini.h"
#include "..\shared\picstar_delays.h"
#include "..\shared\picstar_pfm.h"

void main ()
{
	u8 timer;
	u8 Pos1, Pos2;

	init_picstar();
	init_servo12();
	ADCON1=0x0f;
	TRISD=0;

	while(1)
		{
// position1
PORTD=0x01;
	    Pos1=0;
		Pos2=255;
		timer=200;
		while(timer--)
		{
		PulseServo(Pos1,Pos2);
		delay_ms(18);
		}
// position2
PORTD=0x02;
	    Pos1=128;
		Pos2=128;
		timer=200;
		while(timer--)
		{
		PulseServo(Pos1,Pos2);
		delay_ms(18);
		}
// position 3
PORTD=0x04;
	    Pos1=255;
		Pos2=0;
		timer=200;
		while(timer--)
		{
		PulseServo(Pos1,Pos2);
		delay_ms(18);
		}
	
	} // end while
} // end main

