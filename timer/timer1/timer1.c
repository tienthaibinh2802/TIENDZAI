#include<p18f4520.h>
#include<stdio.h>
#include<delays.h>

#pragma config OSC=HS
#pragma config WDT=OFF
#pragma config MCLRE=ON 

#define xung PORTBbits.RB0
//fosc=12m, 1k, tmr1;
void main()
{
	ADCON1=0x0f;
	TRISB=0;
	T1CON=0b10010001;
	
	while(1)
	{
		TMR1H=(65536-1500)/256;
		TMR1L=(65536-1500)%256;
		
		while(INTCONbits.TMR1IF==0);
		xung=~xung;
		INTCONbits.TMR1IF=0;
	}
}