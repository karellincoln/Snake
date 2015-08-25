#include<UTFT\UTFT.h>
#include"Draw.h"
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


extern short int pointState[22][22];

//程序的具体内容，将在里面进行循环。
void loop()
{
	Draw sn;
	sn.cleanScreen();
	sn.drawWhichPictrue(20, 20, 8, 8, APPLE, VGA_GREEN);
  /* add main program code here */

}
