#include<p18f4520.h>
#include<stdio.h>
#include<delays.h>
//c?u h�nh
#pragma config OSC=HS
#pragma config WDT=OFF
#pragma config MCLRE=ON
#pragma config PBADEN=OFF
//khai b�o t�n chuong tr�nh con ph?c v? ng?t (CTCPVN)
void ngat_ngoai(void);
//�i?m d?t chuong tr�nh ph?c v? ng?t c� m?c uu ti�n cao (vector 0008H)
#pragma code uu_tien_cao = 0x08
// N?u l� chuong tr�nh ph?c v? ng?t c� m?c uu ti�n th?p (vector 0018H):
// #pragma code uu_tien_thap = 0x18
//Vi?t 1 chuong tr�nh con (c� t�n t�y ch?n) d? g?i t?i CTCPVN
void ngat_cao(void)
{
 ngat_ngoai(); //g?i d?n CTCPVN
}
//�i?m vi?t CTCPVN
#pragma code
#pragma interrupt ngat_ngoai
void ngat_ngoai(void)
//Noi dung cua CTCPVN
{ 
	int i;
	if(INTCON3bits.INT1IF==1)
	{
		for(i=0;i<10;i++)
		{
			PORTCbits.RC1=~PORTCbits.RC1;
			Delay10KTCYx(50);
		}
		INTCON3bits.INT1IF=0;
	}
}
//Chuong tr�nh ch�nh
void main()
{
	ADCON1=0x0f;
	TRISC=0x00;
	TRISB=0b00000010;
	INTCONbits.GIE=1;
	INTCON3bits.INT1IE=1;
	INTCON2bits.INTEDG1=0;
	
	while(1)
	{
		PORTCbits.RC0=~PORTCbits.RC0;
		Delay10KTCYx(50);
	}
}