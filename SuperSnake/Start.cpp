#include"Draw.h"
#include"Define.h"


extern UTFT myGLCD;


//��Ϸ�ɴ˽��롣
void start()
{
	startUI();
	chooseAGame();
	differentMapMode(20);
	delay(5000);
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
	draw.drawWhichPictrue(100, 125, 8, 8, APPLE, 0X0FEA);
	myGLCD.setColor(VGA_FUCHSIA);
	myGLCD.print("START", 116, 120);
	songOfStart();
}


short int chooseAGame()
{
	drawOptionUI();
	char *p[GAMEMODE_NUM] = { ">HARD", "MIDDL", ">EASY",
		"EMPTY", "MAGIC", "EATIT", "PATHS" };
	short int choice = 3;
	drawGameName(p, choice,false);
	return optionalGame(p,choice);
}

void drawOptionUI()
{
	draw.cleanScreen();
	draw.drawWhichPictrue(32, 72, 64, 32, SNAKE_SHAPE_TWO,VGA_MAROON);
	draw.drawARect(110, 72, 210, 103, VGA_GREEN);

}

short int optionalGame(char *p[], short int choice)
{
	while (1)
	{
		if (getMessage(TO_LEFT) == TOUCHDOWN)return BACK;
		if (getMessage(TO_RIGHT) == TOUCHDOWN)return choice;
		if (getMessage(TO_UP) == TOUCHDOWN)
		{
			choice = --choice;
			if (choice == -1)choice = 6;
			drawGameName(p, choice,true);
		}
		if (getMessage(TO_DOWN) == TOUCHDOWN)
		{
			choice = ++choice;
			if (choice == 7)choice = 0;
			drawGameName(p, choice,false);
		}
	}
}

void drawGameName(char *p[], short int choice,bool dir)
{
	short int last = choice - 1;
	short int next = choice + 1;
	if (last == -1)last = 6;
	if (next == 7)next = 0;
	if (!dir)
	{
		myGLCD.setColor(VGA_OLIVE);
		myGLCD.print(p[next], 120, 111);
		delay(200);
		myGLCD.setColor(VGA_RED);
		myGLCD.print(p[choice], 120, 82);
		delay(200);
		myGLCD.setColor(VGA_OLIVE);
		myGLCD.print(p[last], 120, 52);
		delay(200);
	}
	else
	{
		myGLCD.setColor(VGA_OLIVE);
		myGLCD.print(p[last], 120, 52);
		delay(200);
		myGLCD.setColor(VGA_RED);
		myGLCD.print(p[choice], 120, 82);
		delay(200);
		myGLCD.setColor(VGA_OLIVE);
		myGLCD.print(p[next], 120, 111);
		delay(200);
	}
}