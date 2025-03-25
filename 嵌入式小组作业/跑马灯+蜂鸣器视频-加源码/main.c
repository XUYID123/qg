#include"REG51.h"
sbit buzzer = P1^3;
sbit num1 = P2^6;
sbit num2 = P2^7;
void delay(unsigned int l){
	 unsigned char i;
	for(;l >0;l--){
		for(i = 100;i>0;i--);
	}
}
void main(void){
unsigned char h,m;
buzzer = 0;
while(1){
for ( h = 0; h<= 7; h++ ){
	P2 = ~(0x01 << h);
	delay(1000);
	}
	}
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
