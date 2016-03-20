/*
   Title:    test poussoir /push button
   Purpose:  Test and show usage of push bottons on picstar
   File name: PsTestPoussoir.c
   Version: 1.0

   by: Rolf Ziegler
   date: April 2010

   description:
		
	Test a switch and generate beep sound according to the number of pushes
	on the push button1, 1 push = 1 bip, 3 pushes = 3 bip etc.
 
*/
#include <p18f4550.h>
#include <delays.h>
#include "..\shared\picstar_def.h"
#include "..\shared\picstar_ini.h"
#include "..\shared\picstar_delays.h"
#include "..\shared\picstar_sound.h"
#include "..\shared\picstar_pushbutton.h"

void main()
{
extern u8 cnton, cntoff;

	init_picstar();
	init_buzzer();

	TRISD=0; // set port as output for debugging

	while(1)
	{
	u8 cnt=0;
		
	PORTD=0xff; // show that you can press again
	
	cnt=get_pushb(BUTTON1);	
	
	PORTD=cnton;
	Xbip(cnt);

	} 
// end main loop
} 
// end main	
