#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

char _7sigment[10] = {0x7f,0x0c,0xb6,0x9e,0xcc,0xda,0xfa,0x0e,0xfe,0xde};
void seg(int i,int j){
	PORTC |=(1<<6);
	PORTC &=~(1<<7);
	PORTA = _7sigment[i];
	_delay_ms(10);
	PORTC |=(1<<7);
	PORTC &=~(1<<6);
	PORTA = _7sigment[j];
	_delay_ms(10);
}
void display(int i, int j){
	for(int s = 0 ; s < 50 ; s++){
		seg(j,i);
	}
}
int main(){
	DDRD = 0x00;
	DDRA = 0xFF;
	PORTA = 0;
	DDRC |=(1<<6)|(1<<7);
	PORTC |=(1<<6)|(1<<7);
	PORTD |=0;
	while(1){
		for(int i = 0 ; i < 10 ; i++){
			for(int j = 0 ; j < 10 ; j++){
				display(i,j);
			}
			if(i == 9)
				i = 0;
		}
	}


}
