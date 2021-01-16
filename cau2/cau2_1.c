#include<p18f4520.h> 
#include<delays.h> 

#pragma config OSC =HS
#pragma config MCLRE = ON 
#pragma config WDT = OFF 

#define key PORTAbits.RA5


void main(void)
{
	int i=0;
	ADCON1=0x0f;
	TRISA=0b00100000;
	
	while(1)
	{
		if(key==0)
		{
			Delay10KTCYx(10);
			if(key==0)
			{
				while(key==0);
				i++;
				if(i>15)i=0;
			}
		
		
		}PORTA=i;
	}	
}