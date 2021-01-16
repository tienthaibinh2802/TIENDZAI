#include<p18f4520.h> 
#include<delays.h> 

#pragma config OSC =HS  
#pragma config MCLRE =ON 
#pragma config WDT =OFF 

#define key PORTBbits.RB7

unsigned char ma[]={0x00,0x01,0x02,0x04,0x08};

void main(void)
{
	int i;
	ADCON1=0x0f;
	TRISB=0b10000000;
	TRISD=0x00;
	PORTD=0x00;
	
	while(1)
	{
		for(i=1;i<5;i++)
		{	
		if(key==0)
		{
			Delay10KTCYx(100);
			if(key==0)
			{
				PORTD=0x00;
				while(key==0);	
			}
		}
		PORTD=ma[i];
		Delay10KTCYx(100);
		}		
	}	
}