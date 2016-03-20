/*
   Title: I2C Test routine for Picstar
   Purpose: Test basic i2c fonctionnality
   File name: i2c_scanner_lcd.c
   Version: 1.0
   Autor: Rolf Ziegler
   Date: April 2010

   description: This routine will scan the I2c bus for slave presence
				and display the result on 2x16 char. LCD
				Once a slave is found, it will display the 1st 10
				memory locations.
*/

// includes
#include <p18f4550.h>
#include <stdio.h>
#include <delays.h>

#include "picstar_def.h" // def must be 1st include
#include "picstar_ini.h"
#include "picstar_delays.h"
#include "xlcd_driver.h"
#include "i2c_SW_driver.h"


void main()
{
   init_picstar();

  
   Dir_LedV=0;
   Dir_LedR=0;


   LedV=LED_OFF;
   
//   OpenXLCD( FOUR_BIT & LINES_5X7 ); 
   lcd_init();
   
   lcd_gotoxy(0,0);
   fprintf(_H_USER,"PICSTAR ZCONTROL");
   
   lcd_gotoxy(0,1);
   fprintf(_H_USER,"  i2c_scanner  ");
   
   LCD_BACKLIGHT=ON;
   delay_ms(1000);
   
	TRISC=0;
	TRISE=0;


   InitI2C();

//   PORTBbits.RB0=0;

   while(1)
   {
   u8 i=0,j=0;
   for(i=0;i<0xfe;i+=2)
   {
   
   if(i2c_rdy(i))
      {
      // found sensor
      lcd_gotoxy(0,0);
      fprintf(_H_USER, "Found I2C at %x   ",i);
      delay_ms(1000);
         {
         for(j=0;j<10;j++)
            {
            lcd_gotoxy(0,1);
            fprintf(_H_USER,"memory %x=0x%02x   ",j,i2c_read_byte(i,j));
			output_portc(j);
            delay_ms(500);
            }
         }
      }
      else 
      {
	   lcd_gotoxy(0,0);
   	   fprintf(_H_USER,"  i2c_scanner    ");
       lcd_gotoxy(0,1);
       fprintf(_H_USER,"Scanning loc:%02x   ",i);
       delay_ms(50);
      }
   }
  }  
// end while
}// end of program
