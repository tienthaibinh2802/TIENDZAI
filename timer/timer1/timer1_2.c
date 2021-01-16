#include<p18f4520.h>
#include<stdio.h>
#include<delays.h>
//c?u hình
#pragma config OSC=HS
#pragma config WDT=OFF
#pragma config MCLRE=ON 
#define xung PORTBbits.RB0

void main()
{
	ADCON1=0x0f;
	TRISB=0;
	T1CON=10000001;
	
	while(1)
	{
		TMR1H=(65536-1500)/256;
		TMR1L=(65536-1500)%256;
		
		while(PIR1bits.TMR1IF==0);
		xung=~xung;
		PIR1bits.TMR1IF=0;
	}

}