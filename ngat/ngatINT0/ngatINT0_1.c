#include<p18f4520.h>
#include<stdio.h>
#include<delays.h>

#pragma config OSC=HS
#pragma config WDT=OFF
#pragma config MCLRE=ON
#pragma config PBADEN=OFF

void ngat_ngoai(void);

#pragma code uu_tien_cao = 0x08

void ngat_cao(void)
{
 ngat_ngoai(); //g?i d?n CTCPVN
}
//Ði?m vi?t CTCPVN
#pragma code
#pragma interrupt ngat_ngoai
void ngat_ngoai(void)
{ 
	int i;
	if(INTCONbits.INT0IF==1)
	{
		for(i=0;i<10;i++)
		{
			PORTCbits.RC1=~PORTCbits.RC1;
			Delay10KTCYx(50);	
		}
		INTCONbits.INT0IF=0;
	}
}

void main()
{
	ADCON1=0x0f;
	TRISC=0x00;
	TRISB=0b00000001;
	INTCONbits.GIE=1;
	INTCONbits.INT0IE=1;
	INTCON2bits.INTEDG0=0;
	
	while(1)
	{
		PORTCbits.RC0=~PORTCbits.RC0;
		Delay10KTCYx(50);
	}
} 