#include <P18f4520.h>            
#include <delays.h> 


#pragma config OSC=HS
#pragma config MCLRE=ON
#pragma config WDT=OFF

unsigned char ma[5]={0x00,0x01,0x02,0x04,0x08};

#define key PORTBbits.RB7

void main(void)
{
	int i=0;
	ADCON1=0x0f;
	TRISB=0b10000000;
	TRISC=0x00;
	PORTC=0x00;
	
	while(1)
	{
		if(key==0)
		{
			Delay10KTCYx(100);
			
			{
				while(key==0);
				i++;
				if(i>4)i=1;
			}
			PORTC=ma[i];
		}
	}	
}