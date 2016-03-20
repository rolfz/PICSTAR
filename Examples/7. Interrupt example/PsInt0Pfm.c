/*
	Title: Main routine to call PFM with an interrupt routine
	Purpose: demonstrate how to program a simple Frequence Modulation using Int0

	File Name: PsInt0Pfm.c

	By: Rolf Ziegler, using the same picstar_pfm.h library
	Date: May 2010

	Description: Motor connected to M1 and M2
				 LED on PortD will show the program progress

				 0x01. Speed up to max speed
				 0x02. Keep speed 
				 0x04. Speed down to 0
				 0x08. stop with 0 speed
				 0x10. Reverse speed up
				 0x20. Keep speed for 3 sec
				 0x40. Speed down to 0
				 0xff. get into infinite loop
*/

#include <p18f4550.h>
#include <delays.h>
#include <timers.h>
#include <stdlib.h>

#include "..\shared\picstar_def.h"
#include "..\shared\picstar_delays.h"
#include "picstar_int.h"
#include "picstar_ini.h"
#include "picstar_pfm.h"

void IntRun1ms(void)
{
      StepPfm(Speed_M1,Speed_M2);

// check encoder status to be added

} 
// end IntRun1ms


void main ()
{
	u8 Cnt1; // counter to count 100x 1ms = 0.1sec

	TRISD=0; // let's use PORTD to follow each step, 

	init_picstar();
	init_motor(); // motor io as output
	init_led();	 // rb6 and rb7 as output	
	LedV=LED_ON;

	Init_Int0(); // initialize interrupt handler and Timer0 Interrupt

// init interrupt
    INTCONbits.GIEH = 1;          //enable interrupts

	while(1)
	{

		PORTD=0x01;

		Speed_M1=0;   // increase speed
		Speed_M2=0;		

		while(Speed_M1<127)
		{
			Cnt1=100;
			while(Cnt1--)delay_ms(1);
			Speed_M1++;
			Speed_M2++;
		};

// LETS KEEP SPEED FOR 5 SEC 0x02

		PORTD=0x02;
		// no need to update Speed, handled by interrupt
		delay_ms(5000);

//LET'S SPEED DOWN AND STOP 0x04
		PORTD=0x04;
		while(Speed_M1>0)
    	{
			Cnt1=100;
			while(Cnt1--)delay_ms(1);
			Speed_M1--;   // decrease speed
			Speed_M2--;		
		} 

// Stop for 3 second  0x08

	PORTD=0x08;
	delay_ms(3000);

// Speed up reverse side
	PORTD=0x10;
	while(Speed_M1>-128)
    {
		Cnt1=100;
		while(Cnt1--)delay_ms(1);
		Speed_M1-=1;   // decrease speed
		Speed_M2-=1;		

	}

// Stop for 3 second
	PORTD=0x20;
	delay_ms(3000);

// and slow down again to 0 speed  0x40
		PORTD=0x40;
		Cnt1=100;

	while(Speed_M1<0) // after couting up to 255, pf2 will be again 0 and stop the loop	
    {
		Cnt1=100;
		while(Cnt1--)delay_ms(1);
		Speed_M1+=1;   // decrease speed
		Speed_M2+=1;		
	} 


/* to test full speed
Speed_M1=127;
Speed_M2=-127;
delay_ms(4000);

Speed_M1=-127;
Speed_M2=127;
delay_ms(4000);
*/

//WE GO INTO SLEEP MODE
    Speed_M1=0;
	Speed_M2=0;
	
	 PORTD=0xff;
	while(1)
		{
		delay_ms(1);
		}
	} // end while 1
} // end main
