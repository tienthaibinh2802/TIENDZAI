#include<p18f4520.h>
 #include<stdio.h>
 #include<delays.h> 
  
 #pragma config OSC=HS   
 #pragma config WDT=OFF  
 #pragma config MCLRE=ON  
 #pragma config PBADEN=OFF 
 void ngat_ngoai(void);
 #pragma code uu_tien_cao = 0x08
 #pragma code uu_tien_thap = 0x18 
 void ngat_cao(void)  {  ngat_ngoai();
 #pragma code
 #pragma interrupt ngat_ngoai 
 void ngat_ngoai(void)
 {
 	
 }

  void main() 
  { 
	  TRISB=0b00000001;
	  TRISC=0x00;
	  
	  while(1)
	  {
	  	PORTCbits.RC0=1; Delay10KTCYx(100);
	  	PORTCbits.RC0=0; Delay10KTCYx(100);
	  }
  
   } 