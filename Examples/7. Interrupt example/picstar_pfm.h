/*
   Title:    Picstar Simple Motor driver
   Purpose:  driver for M1 + M2 using pwm to change speed
   File name: Picstar_MotServ.h
   Version: 1.0

   Description:

				Call this routine every 20ms
				pfmXcnt has to be increased by the main routine

				pfm1 and pfm2 (signed integer 8 ) are used to set the pwm ration
				from -128 to +127
				
   by: Rolf Ziegler accoding to Didel BsMotSer.asi code
   date: April 2010
*/
#define Carry STATUSbits.C

volatile u8 pfm1cnt;
volatile u8 pfm2cnt;
u8 tmp;


void init_motor(void)
{
// Set output of all motor lines
	Dir_Motor_P1=0;
	Dir_Motor_N1=0;
	Dir_Motor_P2=0;
	Dir_Motor_N2=0;
}


void StepPfm(s8 pfm1,s8 pfm2)
{
// init cycle, all lines are cleared
//
	Motor_P1=0;
	Motor_N1=0;
	Motor_P2=0;
	Motor_N2=0;

// initial state of both motor lines is 0
// direction is given by 1st bit
// according to this bit, Line P or Line N is pulsed.

// motor 1
	tmp=(u8)pfm1<<1;  // we change range 0-127 to 2-255 full speed
if(bit_test(pfm1,7))
	{
	// we check when the counter overruns, and set the motor to on.
	// on will remain until next cycle, means 1ms
	// as lower the pfmX variable, as longer it till take to enable the motor
	// in opposition as higher pfmX, as faster we reach saturation and as faster the motor is switched to on.
	pfm1cnt+=tmp;
	if(!Carry) Motor_P1=1;
	}
else
	{
	pfm1cnt+=tmp;
	if(Carry)Motor_N1=1;
	}
// end motor 1 pfm


// motor 2
	tmp=(u8)pfm2<<1;
if(bit_test(pfm2,7))
	{
	pfm2cnt+=tmp;
	if(!Carry) Motor_P2=1;
	}
else
	{
	pfm2cnt+=tmp;
	if(Carry) Motor_N2=1;
	}
// end motor 2 pfm
} 
// end StepPfm

void init_servo12(void)
{
	Dir_Z1=0;
	Dir_Z2=0;
}

// call every 1ms, pulse varies from 1-2ms
void PulseServo(volatile s8 Cx1, volatile s8 Cx2)
{
	
// Servo1
	Cx1>>=1;
	Cx1+=128;
	Z1=1;
	while(Cx1--)delay_us(4);
	Z1=0;
// Servo2
	Cx2>>=1;
	Cx2+=128;
	Z2=1;
	while(Cx2--)delay_us(4);
	Z2=0;
}// end PulseServo





