#include <P18f4520.h>
#include <delays.h>
#include <adc.h>

#pragma config OSC = HS //ch? d? dao d?ng HS
#pragma config MCLRE = ON //s? d?ng RE3 làm chân reset (OFF: không s? d?ng)
#pragma config WDT = OFF 
int AD;
float x;
void main()
{
	
	TRISA=0b00000001;
	TRISD=TRISC=TRISE=0;
	OpenADC( ADC_FOSC_32 &
			 ADC_RIGHT_JUST &
			 ADC_12_TAD,
			 ADC_CH0 &
			 ADC_INT_OFF &
			 ADC_VREFPLUS_VDD &
			 ADC_VREFMINUS_VSS, 15 ); 
		ConvertADC();
		while(BusyADC());
		AD=ReadADC();
		PORTD=AD;
		PORTC=AD>>8;
	x=((1.0*(AD*5))/1023)*100;
	if(x>25 && x <35)
		PORTEbits.RE2=1;		
	else 
		PORTEbits.RE2=0;
			 
}