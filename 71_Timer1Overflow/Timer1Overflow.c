//1초 마다 led 시프트(배열이용)
#include <avr/io.h>
#include <avr/interrupt.h>

#define OneSecond	14400

unsigned char LED_ARRAY[9] = { 0xff, 0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf,
		0x7f };
unsigned int index = 0;

SIGNAL(SIG_OVERFLOW1) {
	PORTA = LED_ARRAY[index];
	index++;
	if (index == 9)
		index = 0;
	TCNT1 = 0xFFFF - OneSecond + 1;
}

void main(void) {
	DDRA = 0xFF;

	TIMSK |= 1 << TOIE1;
	//TIMSK = 0x04;
	TCCR1B = 0x04;  // /1024

	TCNT1 = 0xFFFF - OneSecond + 1;

	sei();
    //SREG |= 0b10000000;

	while (1) {
	};
}
