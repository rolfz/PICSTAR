/*
   Name:    picstar_ini.h       // picstar_set in calm
   Title:   PICSTAR HEADER FILE FOR C18 compiler
   Purpose: For PICSTAR Hardware version 1.1

   by: Rolf Ziegler
   date: February 2010

   description:	The header file is intented to simplify programming of
				the PICSTAR board with C18. 
              
                the file includes the code relocation to 0x1000
                and the pic initalization routine

*/

#ifndef __PICSTAR_SET_H
#define __PICSTAR_SET_H

///////////////////////  relocate code to 0x1000 for bootloader use /////////////////////////////////
extern void _startup (void);        // See c018i.c in your C18 compiler dir
#pragma code _RESET_INTERRUPT_VECTOR = 0x001000
void _reset (void)
{
    _asm goto _startup _endasm
}
#pragma code

///////////////////////// interrupt initalisation, maybe moved to other file ///////////////

#ifdef ENABLE_INTERRUPT

#pragma code _HIGH_INTERRUPT_VECTOR = 0x001008
void _high_ISR (void)
{
    InterruptHandlerHigh();

}

/*
#pragma code _LOW_INTERRUPT_VECTOR = 0x001018
void _low_ISR (void)
{
	;
}
*/
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////

// to be checked if relevant
/*
#define IniTmr0	= -500/4	; tous les 500 us
#define IniOption = 2'00000001  ; div 4
#define IniIntCon = 2'10100000  ; GIE and TOIE on
#define IniT1Con	= 2'00110001  ; Timer1
#define IniCnt500 = 33	; 20ms Prediv timers
#define IniCnt20	= 50

#define IniCntMes	= 50 ;Durée max charge condo

#define Per20ms	= 78
#define IniCntLed	= 15

#define IniCntDis	= 20 ; Periode balayage  x 0.6ms
#define IncSpinLed	= 3
#define DureePause	= 20	; secondes

#define DMax	= 150	; 2,1 ms
#define DMin	= 45	; 0.850ms
#define IniTimOut	= 200

#define MinDur	= 64
#define MaxDur	= 63

#define MaxEcartAddr	= 10	;?
#define MaxEcartInitAddr	= 5	;

#define User1	= 63	; 1.0
#define User2	= 84	; 1.35 ms
#define User3	= 105
#define User4	= 126	; 1.95 ms
#define MaxErAddr = 8  ; 60+/-8


#define IniDurPul	= 120
#define IniDurPdiv	= 5	; durée pas env 0.5s

#define CwaitIni	= 10
#define HalfPowerDelay	= 60
#define NoPowerDelay	= 118
*/

void output_portc(u8 mydata)
{
   PORTC=mydata;
   PORTE=0;
   if(mydata & 0b000001000)PORTE |=1;
   if(mydata & 0b000010000)PORTE |=2;
   if(mydata & 0b000100000)PORTE |=4;
}

void init_outputc(void)
{
	TRISC=0;
	TRISE=0;
}

// maybe usefull to init the pic if you get some strange behaviour
// please do not use until required
void init_picstar(void)
{
     TBLPTRU=0;
     RCONbits.IPEN=0;
     FSR0H=0;
     FSR0L=0;
//....................    setup_adc_ports(NO_ANALOGS|VSS_VDD);
     ADCON1&=0xC0;
     ADCON1|=0x0F;
//                        setup_adc(ADC_CLOCK_DIV_2);
     CMCON=07;
//
     ADCON2bits.ADCS0=0;
     ADCON2bits.ADCS1=0;
     ADCON2bits.ADCS2=0;
     ADCON2bits.ADFM=0;
     ADCON0bits.ADON=1;
//....................    setup_psp(PSP_DISABLED);
//     TRISEbits.4=0;
//....................    setup_spi(SPI_SS_DISABLED);
     SSPCON1bits.SSPEN=0;
//     TRISCbits.7=0;
//     TRISBbits.0=1;
//     TRISBbits.1=0;
     SSPCON1=1;
     SSPSTAT=0;
//....................    setup_wdt(WDT_OFF);
     WDTCONbits.SWDTEN=0;
//....................    setup_timer_0(RTCC_INTERNAL);
     T0CON=0x80;
//....................    setup_timer_1(T1_DISABLED);
     T1CON=0;
//....................    setup_timer_2(T2_DISABLED,0,1);
     T2CON=0;
     PR2=0;
//....................    setup_comparator(NC_NC_NC_NC);
     CMCON=0;
//  MOVF   TRISA,W
//  MOVWF  TRISA
//  MOVLW  0x27
//  MOVWF  00
//  DECFSZ 00,F
//  BRA    1086
//  BRA    108C
     PIR2bits.CMIF=0;
//....................    setup_vref(FALSE);
     CVRCON=0;
//.................... //Setup_Oscillator parameter not selected from Intr Oscillator Config tab
	 INTCON=0;
	 WDTCON=0;
}

void init_led(void)
{
	Dir_LedR=0;
	Dir_LedG=0;
}
#endif