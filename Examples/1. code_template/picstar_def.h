/*
    Name: Picstar_def.h
    Purpose: PICSTAR definitions
    DATE: April 2010
    By: Rolf Ziegler

*/
#ifndef __Picstar_def
#define __Picstar_def


typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;
typedef signed char s8;
typedef signed int s16;
typedef signed long s32;



#define bit_test(var,bit)			((unsigned char)(((unsigned char)(var)) & ((unsigned char)(1U << (bit)))))
#define bit_set(var,bit)			((var)|=(1U << (bit)))
#define bit_clear(var,bit)		    ((var)&=0xFF ^ (1U << (bit)));

// LED definitions

#define LedR	PORTBbits.RB6  //Led L1 rouge a gauche
#define LedG	PORTBbits.RB7  //Led L2 green led droite
#define LedV	PORTBbits.RB7	//Led L2 verte a droite

#define Dir_LedR TRISBbits.TRISB6
#define Dir_LedG TRISBbits.TRISB7
#define Dir_LedV TRISBbits.TRISB7

#define LED_ON 0
#define LED_OFF 1

// not for the led's !! but for general use

#define ON 1
#define OFF 0
// Infrared receiver

#define IR_sensor     PORTB.RB5
#define test_IR       bit_test(PORTB,5);
#define Dir_IR_sensor  TRISBbits.RB5

// Motor definitions
// motor turn in opposit sense

#define Motor_P1     PORTBbits.RB2
#define Motor_N1     PORTBbits.RB3
#define Dir_Motor_P1     TRISBbits.TRISB2
#define Dir_Motor_N1     TRISBbits.TRISB3

#define Motor1_av    Motor_P1=0;Motor_N1=1;
#define Motor1_re    Motor_P1=1;Motor_N1=0;
#define Motor1_st    Motor_P1=0;Motor_N1=0;

//...
#define Motor_P2     PORTEbits.RE2
#define Motor_N2     PORTCbits.RC2
#define Dir_Motor_P2     TRISEbits.TRISE2
#define Dir_Motor_N2     TRISCbits.TRISC2

#define Motor2_av    Motor_P2=0;Motor_N2=1;
#define Motor2_re    Motor_P2=1;Motor_N2=0;
#define Motor2_st    Motor_P2=0;Motor_N2=0;

// Switch definitions

#define BUTTON1 1
#define BUTTON2 2

#define PushB1     PORTBbits.RB6
#define PushB2     PORTBbits.RB7


#define Dir_PushB1  TRISBbits.TRISB6
#define Dir_PushB2  TRISBbits.TRISB7

#define Pouss1   PORTBbits.RB6
#define Pouss2   PORTBbits.RB7

#define Dir_Pous1  TRISBbits.TRISB6
#define Dir_Pous2  TRISBbits.TRISB7


// Buzzer

#define Buzzer       PORTAbits.RA4
#define Dir_Buzzer   TRISAbits.TRISA4

#define Buzzer_on    Buzzer=1;
#define Buzzer_off   Buzzer=0;

#define Bzzer_inv    if(bit_test(PORTA,4)


// Servos

#define TRIS_Z1 TRISAbits.TRISA0
#define TRIS_Z2 TRISAbits.TRISA1
#define TRIS_Z3 TRISAbits.TRISA2
#define TRIS_Z4 TRISAbits.TRISA3
#define TRIS_Z5 TRISAbits.TRISA4
#define TRIS_Z6 TRISAbits.TRISA5

#define Z1 PORTAbits.RA0
#define Z2 PORTAbits.RA1
#define Z3 PORTAbits.RA2
#define Z4 PORTAbits.RA3
#define Z5 PORTAbits.RA4
#define Z6 PORTAbits.RA5

// Bus Perta

#define Perta  PORTAbits.RA5

// Encoder

#define Encoder_1a PORTCbits.RC1
#define Encoder_1b PORTCbits.RC0
#define Encoder_2a PORTBbits.RB4
#define Encoder_2b PORTBbits.RB5

#define Init_Dir_Encoder1 TRISB|=0b00110000;
#define Init_Dir_Encoder2 TRISC|=0b00000011;

// UART port, Port Sérielle

/* to be modified, use C18 routines for UART init
IniRcSta = 2'10011000
IniTxSta = 2'00100100
IniSpBrg = 26  ; 9600
*/

// I2C port, use C18 standard routines or SW driver
// SPI port, use C18 standard routines or SW driver

#endif