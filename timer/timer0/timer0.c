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
	TRISB=0x00;
	T0CON=0b10001000;
	
	while(1)
	{
		TMR0H=(65536-1500)/256;
		TMR0L=(65536-1500)%256;
	
		while(INTCONbits.TMR0IF==0);
		xung=~xung;
		INTCONbits.TMR0IF=0;
	}	
}