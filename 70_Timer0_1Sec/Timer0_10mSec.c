/*************************************
* Purpose: Timer0�� �̿��Ͽ� 1�ʸ��� overflow
* interrupt�� ���� LED Shift
*
* TIMSK
* TCCR1B
* TCNT1
*************************************/
#include <avr/io.h>
#include <avr/interrupt.h>

#define cDelay 144

unsigned char FND[10]= {0XC0, 0XF9, 0XA4, 0XB0, 0X99, 0X92, 0X82, 0XD8, 0X80, 0X90};

volatile int sec =0;
volatile int msec =0;

ISR (TIMER0_OVF_vect)
{
	msec++;
	if(msec == 100)	{
		sec++;
		msec = 0;
		PORTE = FND[sec];
	}
	if (sec==10) {
		sec = 0;
	}

	PORTF = FND[msec%10];

	TCNT0 = 0xFF-cDelay+1;    //�ʱⰪ
}

int main(void)
{
	DDRE  = 0xFF;
	DDRF  = 0xFF;

	PORTF = FND[msec];
	PORTF = FND[msec];
	
	cli();

	TIMSK |= (1<<TOIE0);    // Timer0 �����÷� ���ͷ�Ʈ ���̺�
	
	// Normal, 1/1024 for ����������
	TCCR0 |= (1<<CS02);
	TCCR0 |= (1<<CS01);
	TCCR0 |= (1<<CS00);
	 
	TCNT0 = 0xFF-cDelay+1;    // 10msec

	sei();         //SRGE  = 0x80;
	while(1)
   {
   }
}
