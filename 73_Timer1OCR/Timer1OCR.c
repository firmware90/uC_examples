//1초 마다 led 시프트(배열이용)
#include <avr/io.h>
#include <avr/interrupt.h>

#define cDelay	14400	// 1sec 14.7456MHz

unsigned char LED_ARRAY[9] = { 0xff, 0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf,
		0x7f };
unsigned char FND[10] = { 0XC0, 0XF9, 0XA4, 0XB0, 0X99, 0X92, 0X82, 0XD8, 0X80, 0X90 };

volatile unsigned int index = 0;

SIGNAL(SIG_OUTPUT_COMPARE1A) {
	PORTA = LED_ARRAY[index];
	PORTE = FND[index];
	
	index++;
	if (index == 9)
		index = 0;
	TCNT1 = 0;
}

void main(void) {
	DDRA = 0xFF;
	DDRE = 0xFF;

	TIMSK = 0x10;
	TCCR1B = 0x05;

	TCNT1 = 0;
	OCR1A = cDelay;

	sei();

	while (1) {
	};
}
