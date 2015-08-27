//#include"Draw.h"
#include<UTFT\UTFT.h>
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


//����ľ������ݣ������������ѭ����
void loop()
{
	start();
  /* add main program code here */

}



//pin��ʾ��Ҫ��������ţ������������ŵ�״̬��
short int getMessage(short int pin)
{
	static bool mess[4] = { 1, 1, 1, 1 };
	int i = 0;
	switch (pin)
	{
	case TO_UP:
		i = 0; break;
	case TO_DOWN:
		i = 1; break;
	case TO_LEFT:
		i = 2; break;
	case TO_RIGHT:
		i = 3; break;
	default:
		break;
	}
	if (mess[i] == 1){
		if (digitalRead(pin) == HIGH)return SWITCHUP;
		else { mess[i] = 0; return TOUCHDOWN; }
	}
	else {
		if (digitalRead(pin) == HIGH){ mess[i] = 1; return TOUCHUP; }
		else return SWITCHDOWN;
	}
}



//��tim���ڵ�ʱ���Ϲ�ȥbetween��ʱ�䡣
//����Ƿ���true����tim����Ϊ��ǰʱ�䣬���򷵻�false��
bool afterTime(time &tim, int between)
{
	if (millis() - tim >= between){
		tim = millis();
		return true;
	}
	else return false;

}




//��ʼʱ�ݳ������֡�
short int songOfStart()
{
	int melody[] = { NOTE_C4, NOTE_C4, NOTE_E4, NOTE_C4, NOTE_C4, NOTE_E4, 0, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_A4, NOTE_F4, NOTE_C4, NOTE_E4, 0,
		NOTE_C5, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_A4, NOTE_F4, NOTE_C4, NOTE_D4, 0, NOTE_B4, NOTE_B4, NOTE_F4, NOTE_E4, NOTE_F4 };
	int noteDurations[] = { 4, 4, 2, 8, 4, 4, 4, 4, 4, 8, 8, 4, 8, 4, 4, 4, 8, 8, 8, 8, 2, 8, 4, 4, 4, 2, 8, 8, 4, 1 };
	int i = 0;
	while (1)
	{
		int noteduration = 1000 / noteDurations[i];
		tone(MUSIC, melody[i], noteduration);
		int pause = noteduration*1.30;
		delay(pause);
		noTone(MUSIC);
		if (getMessage(TO_RIGHT) == SWITCHDOWN){ return GOIN; }
		if (++i == 30)i = 0;
	}

}



//��Ϸ����ʱ�����ŵ����֡�
short int songOfDie()
{
	int melody[] = { NOTE_A3, NOTE_D4, NOTE_E4, NOTE_A4, NOTE_E4, NOTE_A4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, 0, 0, 0,
		NOTE_A4, NOTE_D4, NOTE_E4, NOTE_A4, NOTE_E4, NOTE_A4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, 0, 0, 0, NOTE_D4, 0, NOTE_E4,
		NOTE_F4, NOTE_E4, NOTE_B3, NOTE_E4, NOTE_D4 };
	int noteDurations[] = { 4, 8, 8, 4, 4, 4, 8, 8, 8, 8, 8, 8, 4, 1, 4, 4, 4, 4, 4, 4, 8, 8, 4, 4, 4, 8, 8, 8, 8, 8, 8, 1, 4, 4, 4, 4, 2, 4, 8, 8, 4, 4, 4, 4 };//
	int i = 0;
	while (1)
	{
		int noteduration = 1000 / noteDurations[i];
		tone(MUSIC, melody[i], noteduration);
		int pause = noteduration*1.30;
		delay(pause);
		noTone(MUSIC);
		
		if (getMessage(TO_RIGHT) == SWITCHDOWN)
			return GOIN;
		if (getMessage(TO_LEFT) == SWITCHDOWN)
			return BACK;

		if (++i == 42)i = 0;
	}

}



//��Ϸ�з����κ��¼�ʱ����������ͬ��������
void soundOfTouchAndEat(short int d)
{
	switch (d){
	case SNAKE_UP:
		tone(MUSIC, NOTE_C5, 80);//noTone(MUSIC);
		break;//��һ��������ʾ��������ӿ�

	case SNAKE_DOWN:
		tone(MUSIC, NOTE_D5, 80);//noTone(MUSIC);
		break;//��һ��������ʾ��������ӿ�

	case SNAKE_LEFT:
		tone(MUSIC, NOTE_E5, 80);//noTone(MUSIC);

		break;//��һ��������ʾ��������ӿ�

	case SNAKE_RIGHT:
		tone(MUSIC, NOTE_F5, 80);

		//noTone(MUSIC);
		break;//��һ��������ʾ��������ӿ�
	case APPLE:
		tone(MUSIC, NOTE_A2, 100);
		break;
	case CROSS_WALL:
		tone(MUSIC, NOTE_B3, 100);
		break;
	case CONVERT_HEAD:
		tone(MUSIC, NOTE_C4, 100);
		break;
	case MAGNET:
		tone(MUSIC, NOTE_D6, 100);
		break;
	default:

		break;
	}

}