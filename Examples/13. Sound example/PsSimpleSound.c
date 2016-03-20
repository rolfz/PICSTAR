/*
   Title:    Blink Test
   Purpose:  Basic functional test for PORT activities
   File name: link_test.c
   Version: 1.0

   by: Rolf Ziegler
   date: Feb.2010

   description:
   PORTA,B,C,E will alternate with pattern 0x55 and 0xaa
   PORTD will count.
   Connecting an LED serie like microdule LB8 from Didel for example.
   Also you will notice buzzer to tick as it is connected to RA4

*/
#include <p18f4550.h>
#include <delays.h>
#include "..\shared\picstar_def.h"
#include "..\shared\picstar_ini.h"
#include "..\shared\picstar_delays.h"
#include "..\shared\picstar_sound.h"


void main()
{
	char counter=0;

	TRISD=0;
	PORTD=0xff;
// all output

	init_picstar();
//	init_motor();
	init_buzzer();

	delay_ms(1000);

	while(1)
	{
	// PORTD will show the program step, ie with Microdule-LED
	PORTD=1;	

	// test beep, various freqencies, various durations
	beep(400,1000);
	delay_ms(1000);
	beep(1000,500);
	delay_ms(1000);
	beep(5000,200);
	delay_ms(1000);

	PORTD=2;
	// test bip (1000hz, 1sec)
	bip();
	delay_ms(2000);

	PORTD=4;
	// test sirene
	sirene_up();
	delay_ms(1000);
	PORTD=8;
	sirene_down();
	delay_ms(1000);
	}
}
