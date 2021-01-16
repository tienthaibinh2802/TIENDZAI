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
	T2CON=0b00001101;
	
	while(1)
	{
		TMR2=(256-187)/256;
	
		
		while(PIR1bits.TMR2IF==0);
		xung=~xung;
		PIR1bits.TMR2IF=0;
	}

}