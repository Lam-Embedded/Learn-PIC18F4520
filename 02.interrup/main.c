#include<p18f4520.h> 
#include<stdio.h> 
#include<delays.h> 
 
//c?u hình 
#pragma config OSC=HS   
#pragma config WDT=OFF   
#pragma config MCLRE=ON   
#pragma config PBADEN=OFF   

#define Led5 PORTBbits.RB7
#define BUTTON_1 PORTBbits.RB0
#define BUTTON_2 PORTBbits.RB2
int dem = 0;
void ngat_ngoai(void); 
#pragma code uu_tien_cao = 0x08
void ngat_cao(void)  { 
	ngat_ngoai(); //g?i d?n CTCPVN 
} 
#pragma code 
#pragma interrupt ngat_ngoai 
void ngat_ngoai(void) { 
	if (INTCONbits.INT0IF == 1) {
		dem++;
		PORTB = dem << 3;
		INTCONbits.INT0IF = 0;
	}	
}

void main() { 
	TRISB = 0b00000101;
	ADCON1 = 0x0f;
	RCONbits.IPEN = 0;
	INTCON = 0b11010000;
	INTCON2bits.INTEDG0 = 0;
	//INTCON3
	while(1) {
		Led5 = 1;
		Delay10KTCYx(50);
		Led5 = 0;
		Delay10KTCYx(50);
	}	

} 