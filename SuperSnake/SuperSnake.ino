#include<UTFT\UTFT.h>
#include"Draw.h"
#include"Define.h"

//����һ���ⲿ�������������Ļ�Ķ���
extern uint8_t SmallFont[];
UTFT myGLCD(QD220A, A2, A1, A5, A4, A3);



//�ڿ�ʼ����ʱ��������ù���ֻ����һ�Ρ�
void setup()
{
	//��������������ӡ�
	randomSeed(analogRead(0));

	//�����ĸ���ť�����������š�
	pinMode(TO_UP, INPUT);
	digitalWrite(TO_UP, HIGH);

	pinMode(TO_DOWN, INPUT);
	digitalWrite(TO_DOWN, HIGH);

	pinMode(TO_LEFT, INPUT);
	digitalWrite(TO_LEFT, HIGH);

	pinMode(TO_RIGHT, INPUT);
	digitalWrite(TO_RIGHT, HIGH);

	//�������ȵ�������š�
	pinMode(MUSIC, OUTPUT);


	//��ʼ����Ļ���������塣
	myGLCD.InitLCD();
	myGLCD.InitLCD();
	myGLCD.setFont(SmallFont);


  /* add setup code here */

}


extern short int pointState[22][22];

//����ľ������ݣ������������ѭ����
void loop()
{
	Draw sn;
	sn.cleanScreen();
	sn.drawWhichPictrue(20, 20, 8, 8, APPLE, VGA_GREEN);
  /* add main program code here */

}
