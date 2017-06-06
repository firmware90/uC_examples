/*************************************
* Purpose: Understand GPIO registers
*
* DDRn
* PORTn
*************************************/

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	//PORTB�� ��� ���͸� ��� ������� ����
	DDRB = 0xFF; 

	while(1)	{
		//PORTB�� ���� 4��Ʈ���� 1��, ���� 4��Ʈ���� 0���� ����
		PORTB = 0xF0; 
		//1�ʰ� ����
		_delay_ms(1000); 

		PORTB = 0x0F;
		_delay_ms(1000);
	}
}
