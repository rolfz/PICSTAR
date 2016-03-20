#ifndef __RC5_DECODER__
#define __RC5_DECODER__
/*
	RC5 Infrared Remote control decoder
	Pulse length to mesure 1778us

	With Picstar running at 48mhz (12mhz code speed)
	we calculate the limit puse lenth	
	Half pulse 889us with timer/8 we get 1.5mhz counting speed.
	889*1.5=1334 clock

*/

void Init_decoder(void)
{
// setup timer to mesure IR pulses.
	OpenTimer1 ( TIMER_INT_OFF 
				& T1_16BIT_RW 
				& T1_SOURCE_INT
				& T1_PS_1_8
				& T1_OSC1EN_OFF
				& T1_SYNC_EXT_OFF
				);

	Enable_INT0_Int;
	Enable_Global_Int;
}

#define SMALLPULSE 960 //48mhz 400 with 20mhz
#define LONGPULSE  1920 //48 mhz  800 with 20mhz

u8 get_RC5(void)
{
   u16 tmp,t;
   u8 i;
   u8 inp;

   WriteTimer1(0);
 
   while(IR_STATUS==1);
   t=ReadTimer1();

   if ((t<SMALLPULSE) || (t>LONGPULSE)) return 0;   // no RC5 code, abort decoding 4mhz

   for (i=0;i<13;i++)
   {
      inp=IR_STATUS;
 	  WriteTimer1(0);
      while (IR_STATUS==inp)
      {
         t=ReadTimer1 ();
         if (t>LONGPULSE) return 0;   // no RC5 code, abort decoding
      }
  
      tmp<<=1;
      if (inp==0) tmp++;

      WriteTimer1(0);
 	  while (ReadTimer1()<LONGPULSE-100);  // a simple delay would work here as well
   }

   tmp=tmp | 0x3000;
   tmp=tmp & 0x37ff; // cut off togglebit

   rc5.data[1]=tmp & 0x003f; // device address
   rc5.data[0]=(tmp>>6) & 0x001F;  // command code

   rc5.state = 1;

// disable external interrupt
	Disable_INT0_Int;

   return 1;
}

#endif
