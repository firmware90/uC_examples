#include <avr/io.h>
#include <util/delay.h>
int main(void) {
	DDRF = 0XFF;  // F��Ʈ�� ��� ����
	chart SEG[] = { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xD8, 0x80, 0x98,
			0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E }; // 0���� F���� ���� (ǥ ÷��)
	int num = 0;  // �ʱⰪ 0���� ����

	while (1) {             // while ���� ����� �ݺ� ����
		PORTF = SEG[num++]; // ���׸�Ʈ �ԷµǴ� �ڵ� �ϳ��� ������� �۵�
		if (num == 16)          //  16��° �ڵ� �۵���
			num = 0;              // �ٽ� 0���� �ʱ�ȭ
		_delay_ms(500);  // 500ms �����ð� ����
	}
}
