/*************************************
* Purpose: Understand GPIO registers
*
* DDRn
* PORTn
*************************************/

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	//PORTB의 모든 포터를 모두 출력으로 설정
	DDRB = 0xFF; 

	while(1)	{
		//PORTB의 상위 4비트에는 1을, 하위 4비트에는 0으로 설정
		PORTB = 0xF0; 
		//1초간 지연
		_delay_ms(1000); 

		PORTB = 0x0F;
		_delay_ms(1000);
	}
}
