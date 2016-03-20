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

#define INICNT1 100 // to slow down the pwm, we repeat this amount of time each step

void main ()
{
	s8 Speed_M1=0, Speed_M2=0;
	u8 Cnt1; // counter to count 100x 1ms = 0.1sec
	u8 Cnt2;  // ie 100x50 = 5000ms = 5 sec.
	TRISD=0; // let's use PORTD to follow each step, 

	init_picstar();
	init_motor();
	LedV=LED_ON;

	while(1)
	{


//LET's SPEED UP  0x01

	do 
	{
		Cnt1=INICNT1;
		PORTD=0x01;
		while(Cnt1--){ 	StepPfm(Speed_M1,Speed_M2);
						delay_ms(1); }
		Speed_M1+=1;   // increase speed
		Speed_M2+=1;		
		// in order not to stop at 0 speed, we speed up to max speed only.
	} while(Speed_M1<127); // after couting up to 254


// LETS KEEP SPEED FOR 5 SEC 0x02

		Cnt1=100; // we want to stay at top speed for 5sec.
		Cnt2=50;
		PORTD=0x02;
		while(Cnt2--)
		{
			while(Cnt1--)
	    	{
				StepPfm(Speed_M1,Speed_M2);
				delay_ms(1);
			} // we stop when counter reaches 0
		}


//LET'S SPEED DOWN AND STOP 0x04
		PORTD=0x04;
	do 
    {
		Cnt1=100;
		while(Cnt1--){	StepPfm(Speed_M1,Speed_M2);
						delay_ms(1);}
		Speed_M1-=1;   // decrease speed
		Speed_M2-=1;		
	} while(Speed_M1); // after couting up to 255, pf2 will be again 0 and stop the loop	
					  // this is for demonstration only
	

// Stop for 3 second  0x08

		Cnt1=100; // we want to stay at top speed for 5sec.
		Cnt2=30;
		PORTD=0x08;
		while(Cnt2--)
		{
			while(Cnt1--)
	    	{
				StepPfm(Speed_M1,Speed_M2);
				delay_ms(1);
			} // we stop when counter reaches 0
		}


	Speed_M1=0;
	Speed_M2=0;

//LET'S go backwards STOP  0x10
	Speed_M1=0;
	Speed_M2=0;

		PORTD=0x10;

	do
    {
		Cnt1=100;
		while(Cnt1--){	StepPfm(Speed_M1,Speed_M2);
						delay_ms(1);}
		Speed_M1-=1;   // decrease speed
		Speed_M2-=1;		

	} while(Speed_M1>-128); // after couting up to 255, pf2 will be again 0 and stop the loop	
					  // this is for demonstration only

// Stop for 3 second  0x20

		Cnt1=100; // we want to stay at top speed for 5sec.
		Cnt2=30;
		PORTD=0x20;
		while(Cnt2--)
		{
			while(Cnt1--)
	    	{
				StepPfm(Speed_M1,Speed_M2);
				delay_ms(1);
			} // we stop when counter reaches 0
		}

// and slow down again to 0 speed  0x40
		PORTD=0x40;
		Cnt1=100;

	do 
    {
		Cnt1=INICNT1;
		while(Cnt1--){	StepPfm(Speed_M1,Speed_M2);
						delay_ms(1);}
		Speed_M1+=1;   // decrease speed
		Speed_M2+=1;		
	} while(Speed_M1<0 ); // after couting up to 255, pf2 will be again 0 and stop the loop	
					  // this is for demonstration only

//WE GO INTO SLEEP MODE
    Speed_M1=0;
	Speed_M2=0;
	
	 PORTD=0xff;
	while(1)
		{
		StepPfm(Speed_M1,Speed_M2);
		delay_ms(1);
		}
	} // end while 1
} // end main
