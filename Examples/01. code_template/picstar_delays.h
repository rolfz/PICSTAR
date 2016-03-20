/*
  Name: dealay.h
  Title: Simple delay routine without interrupt to 1st programming exercises
		 Can be replaced by user with better algoritmes

  By: Rolf Ziegler
  Date: Feb 2010

  Purpose: C18 delay routines are based on CPU cycle. This code allows user friendly delays
		   the routine anticipates the cpu to run at 48mhz application speed (original product setup).

*/
#ifndef __MYDELAY
#define __MYDELAY


void delay_ms(u16 del_ms)
{
    long i;

    while (del_ms--)
//   for (i=0; i < 854   ; i++) // was 330
     for (i=0; i < 450   ; i++) // was 330
            ;
}

/*
void delay_ms(u16 x)
{
    u8 y, z;
    for ( ; x > 0 ; x--)
        for ( y = 0 ; y < 4 ; y++)
//            for ( z = 0 ; z < 176 ; z++);
            for ( z = 0 ; z < 180 ; z++);
}
*/
// 1 nop == 0.8us
void delay_us(u16 us)
{

while(us--)
	{
	_asm
	nop
	_endasm
	}
}

