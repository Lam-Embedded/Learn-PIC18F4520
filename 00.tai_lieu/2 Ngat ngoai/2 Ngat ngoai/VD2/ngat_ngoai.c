//khai báo các thu vi?n, ví d?:
#include <P18f4520.h>
#include <delays.h>
//C?u hình cho vi di?u khi?n, ví d?:
#pragma config OSC = HS //ch? d? dao d?ng HS
#pragma config MCLRE = ON //s? d?ng RE3 làm chân reset (OFF: không s? d?ng)
#pragma config WDT = OFF //không dùng Watchdog timer
#pragma config PBADEN = OFF //PORTB<4:0> du?c c?u hình thành các chân vào/ra s?

#define LED1 PORTBbits.RB3
#define LED2 PORTBbits.RB4
#define LED3 PORTBbits.RB5
#define LED4 PORTBbits.RB6
#define LED5 PORTBbits.RB7

void ngat_ngoai();

#pragma code uu_tien_cao = 0x08
void ngat_cao(){	ngat_ngoai();}

#pragma code
#pragma interrupt ngat_ngoai
void ngat_ngoai()
{	if(INTCON3bits.INT1IF==1)
	{	//Lenh xu ly ngat
		INTCON3bits.INT1IF=0;//Xoa co ngat
	}
	if(INTCON3bits.INT2IF==1)
	{
		INTCON3bits.INT2IF=0;//Xoa co ngat
		LED5=1; 
		Delay10KTCYx(100);
		LED5=0;
	}



}

void main (void)
{
	TRISB=0b00000100;//Rb2 chieu vao
	ADCON1=0x0f;
	//Thiet lap ngat
	INTCONbits.GIE=1;//Cho phep ngat toan cuc
	INTCON3bits.INT2IE=1;//Cho phep ngat ngoai INT2
	INTCON2bits.INTEDG2=0;//Ngat bang suon am
    LED1=LED2=LED3=LED4=LED5=0;
	while(1)
	{
		LED1=1; LED2=LED3=LED4=0;
		Delay10KTCYx(100);
		LED2=1; LED1=LED3=LED4=0;
		Delay10KTCYx(100);
		LED3=1; LED2=LED1=LED4=0;
		Delay10KTCYx(100);
		LED4=1; LED2=LED3=LED1=0;
		Delay10KTCYx(100);
	}	
}