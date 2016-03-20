/*
	Title: LCD test routine with C18 compiler
	Autor: Rolf Ziegler
	Date: April 2010
*/

#include <p18f4550.h>
#include <stdio.h>

#include "..\shared\picstar_def.h"
#include "..\shared\picstar_ini.h"
#include "..\shared\picstar_delays.h"
#include "..\shared\xlcd_driver.h" // includes xlcd.h

/*
#pragma code _HIGH_INTERRUPT_VECTOR = 0x001008
void _high_ISR (void)
{
    user_interrupt();
}

#pragma code _LOW_INTERRUPT_VECTOR = 0x001018
void _low_ISR (void)
{
    ;
} 
*/

#define ON 1
#define OFF 0
void main()
{
	u8 counter=0;
	u8 LCD_buffer[16];

    init_picstar();
 
    init_lcd();

	LCD_BACKLIGHT=ON;

	while(1)
	{
	lcd_gotoxy(0,0);
	fprintf(_H_USER,"PICSTAR ZCONTROL");
	lcd_gotoxy(0,1);
	fprintf(_H_USER,"    %02u  ",counter++);
	
	delay_ms(10);
	}
}
