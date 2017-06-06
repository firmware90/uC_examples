/*=======================================================*/
// �ܺ� ���ͷ�Ʈ�� �̿��� 7 segment �� ����
// INT0 (PD0)�� Ȱ��ȭ
/*=======================================================*/
#include <avr/io.h>
#include <avr/interrupt.h>

unsigned int Index = 0;
unsigned char SEG[10]= {0XC0, 0XF9, 0XA4, 0XB0, 0X99, 0X92, 0X82, 0XD8, 0X80, 0X90};

// ���ͷ�Ʈ ���� �Լ��� �Ʒ��� ����
// SIGNAL(SIG_INTERRUPTn)���� �Ͽ� n�� ���ͷ�Ʈ ��ȣ
SIGNAL(SIG_INTERRUPT1)
{
	PORTF = SEG[Index++];    
	if (Index == 10) Index = 0;
}

int main(void)
{
    DDRF  = 0XFF;
    PORTF = 0xFF;
  
    EIMSK = 0b00000010;		//INT0 �� ��� ����
    //EIMSK = 0x01;
    EICRA = 0b00001000; 		//INT0 �ϰ��𼭸����� ���۵ǵ��� ����
    //EIMSK = 0x02;
    SREG = 0b10000000;
    //SREG = 0x80;

    while(1)
    { 
    }
}
