/*

	Name	uart_baud.h
	By: Rolf Ziegler
	Date: June 2010
	
	Purpose: define the SBRG for the PICSTAR board, running at 48mhz clock rate

	Formula from datasheet
	SBRG = ((Fosc/baud)/64)-1
	SYNC=0
	BRG16=0
	BRGH=0
	
*/
#ifndef __UART_BAUD
#define __UART_BAUD
//					BRGL    BRGH (decimal)	error
#define BAUD1200	112 //	2			0
#define BAUD2400	55	//	1			.16%
#define BAUD4800	155	//  0			.16%
#define BAUD9600	77  //	0			.16%
#define BAUD19200	38	//	0	 		.16%
#define BAUD38400	19	//	0			-2.4%
#define BAUD57600	12	//	0			0.16%
#define BAUD115200  6	//	0			-7.6%  

#endif

