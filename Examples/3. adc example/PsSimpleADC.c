/*
	Title: Simple ADC
	Purpose: demonstrate how to use the ADC function of a PIC

	File Name: PsSimpleADC.c

	By: Rolf Ziegler
	Date: May 2010

*/

#include <p18f4550.h>
#include <delays.h>
#include "..\shared\picstar_def.h"
#include "..\shared\picstar_ini.h"
#include "..\shared\picstar_delays.h"

#define ADC_GO 	ADCON0bits.GO
#define ADC_RESULT  ADRESH

void main ()
{

	// prepare the output to display the result of the adc conversion
	TRISD=0;
	TRISAbits.TRISA0=1; // our analog input

// setup ADC IO
	ADCON1&=0xC0;
	ADCON1|=0x0e;
// setup conversion speed
	ADCON2bits.ADCS0=0;		// setup divider, high-speed
	ADCON2bits.ADCS1=0;
	ADCON2bits.ADCS2=0;
	ADCON0bits.ADON=1;		// enable ADC

	ADCON0&=0xc3; //clear channel select =channel 0

	while(1)
	{

	ADCON0bits.GO=1; // start conversion

	while(ADC_GO); 	// wait until conversion is finished
					// when done, go will return to 0

	PORTD=ADC_RESULT;	

	delay_ms(100);

	} // end while 1
} // end main
