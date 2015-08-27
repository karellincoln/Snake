//#include"Draw.h"
#include<UTFT\UTFT.h>
#include"Define.h"



//声明一个外部的字体数组和屏幕的对象
extern uint8_t SmallFont[];
UTFT myGLCD(QD220A, A2, A1, A5, A4, A3);



//在开始程序时，完成设置工作只运行一次。
void setup()
{
	//设置随机数的种子。
	randomSeed(analogRead(0));

	//定义四个按钮开关输入引脚。
	pinMode(TO_UP, INPUT);
	digitalWrite(TO_UP, HIGH);

	pinMode(TO_DOWN, INPUT);
	digitalWrite(TO_DOWN, HIGH);

	pinMode(TO_LEFT, INPUT);
	digitalWrite(TO_LEFT, HIGH);

	pinMode(TO_RIGHT, INPUT);
	digitalWrite(TO_RIGHT, HIGH);

	//定义喇叭的输出引脚。
	pinMode(MUSIC, OUTPUT);


	//初始化屏幕和设置字体。
	myGLCD.InitLCD();
	myGLCD.InitLCD();
	myGLCD.setFont(SmallFont);


  /* add setup code here */

}


//程序的具体内容，将在里面进行循环。
void loop()
{
	start();
  /* add main program code here */

}



//pin表示所要接入的引脚，并返回所引脚的状态。
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



//在tim所在的时间上过去between的时间。
//如果是返回true并将tim设置为当前时间，否则返回false。
bool afterTime(time &tim, int between)
{
	if (millis() - tim >= between){
		tim = millis();
		return true;
	}
	else return false;

}




//开始时演唱的音乐。
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



//游戏结束时所播放的音乐。
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



//游戏中发生任何事件时，所发出不同的声音。
void soundOfTouchAndEat(short int d)
{
	switch (d){
	case SNAKE_UP:
		tone(MUSIC, NOTE_C5, 80);//noTone(MUSIC);
		break;//第一个参数表示音响输出接口

	case SNAKE_DOWN:
		tone(MUSIC, NOTE_D5, 80);//noTone(MUSIC);
		break;//第一个参数表示音响输出接口

	case SNAKE_LEFT:
		tone(MUSIC, NOTE_E5, 80);//noTone(MUSIC);

		break;//第一个参数表示音响输出接口

	case SNAKE_RIGHT:
		tone(MUSIC, NOTE_F5, 80);

		//noTone(MUSIC);
		break;//第一个参数表示音响输出接口
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