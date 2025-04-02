#include <P18f4520.h>                 
#include <delays.h> 
//C?u hình cho vi di?u khi?n: 
#pragma config OSC = HS  
#pragma config MCLRE = ON
#pragma config WDT = OFF  
#pragma config PBADEN = OFF  

void main (void) { 
	TRISA = 0b00000100;
	while(1){
		PORTAbits.RA0 = 1;
		Delay10KTCYx(50);// Tan so thach anh la 8MHz
		PORTAbits.RA0 = 0;
		Delay10KTCYx(50);	
	}	
}