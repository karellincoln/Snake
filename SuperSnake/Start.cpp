#include"Draw.h"
#include"Map.h"
#include"Food.h"
#include"Snake.h"
#include"Define.h"


extern UTFT myGLCD;


//游戏由此进入。
void start()
{
	startUI();
	chooseAGame();
}



void startUI()
{
	draw.cleanScreen();
	draw.drawWhichPictrue(10, 20, 32, 32, S_OF_SNAKE, 0x0ff0);
	draw.drawWhichPictrue(10 + 40, 20, 32, 32, N_OF_SNAKE, 0x0ff0);
	draw.drawWhichPictrue(10 + 80, 20, 32, 32, A_OF_SNAKE, 0x0ff0);
	draw.drawWhichPictrue(10 + 120, 20, 32, 32, K_OF_SNAKE, 0x0ff0);
	draw.drawWhichPictrue(10 + 160, 20, 32, 32, E_OF_SNAKE, 0x0ff0);

	draw.drawWhichPictrue(10, 80, 80, 80, SNAKE_SHAPE_ONE, 0x0ff0);
	draw.drawWhichPictrue(120, 120, 8, 8, APPLE, 0X0FEA);
	myGLCD.setColor(VGA_FUCHSIA);
	myGLCD.print("START", 136, 120);
	songOfStart();
}


short int chooseAGame()
{
	drawOptionUI();

	return 1;
}

void drawOptionUI()
{
	draw.cleanScreen();
	draw.drawWhichPictrue(32, 72, 64, 32, SNAKE_SHAPE_TWO, 0xfff0);
	draw.drawARect(110, 72, 165, 103, VGA_GREEN);
	
}