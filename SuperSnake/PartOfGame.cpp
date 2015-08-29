#include"Draw.h"
#include"Map.h"
#include"Food.h"
#include"Snake.h"
#include"Define.h"


extern UTFT myGLCD;
extern uint8_t SmallFont[];

short int differentMapMode(short int difficulty,bool isPansFinding=false,
		bool isTurnFat=false)
{
	draw.cleanScreen();

	Map map(difficulty);
	gameUI();
	Snake snk;
	bool snakeState = SNAKE_ALIVE;
	Food fd(APPLE);


	short int direct = TO_RIGHT;
	short int foodType;
	short int headTouch;

	short int scale = 0;
	short int score = 0;

	time snakeTime = millis();
	time creatFoodTime = millis();
	const time startTime = millis();

	short int speed=START_SPEED;

	while (1)
	{
		if (snakeState == SNAKE_DIE)break;
		direct = getSnakeDirect(direct);

		
		if (isTurnFat == true)//�Ƿ�Ҫ���֡�
			foodType = random(1, 5);
		else foodType = random(1, 4);
		creatASpecialFood(creatFoodTime, foodType);//��ɲ���һ�������ʳ�
		
		if (isPansFinding == true)//�Ƿ��Ǵ���ģʽ��
		{

		}
		
		if (afterTime(snakeTime, speed))//�Ƿ����ƶ���ʱ�䡣
		{
			headTouch = snk.getDirection(direct, true);
			switch (headTouch)
			{
			case WALL_AND_BLOCK:
				return touchWithBlock(snakeState);
				break;
			case EMPTY:
				snk.moveSnake(direct);
				break;
			case APPLE:
				touchWithApple(snk, direct, score, scale, speed);
				break;
			case CROSS_WALL:
				
				
				break;
			case CONVERT_HEAD:


				break;
			case MAGNET:

				break;
			case FAT_BODY:

				break;
			default:
				break;
			}

		}

	}

}


void gameUI()
{
	draw.fillARect(176, 0, 219, 7);
	draw.fillARect(176, 56, 219, 63);
	draw.fillARect(176, 112, 219, 119);
	draw.fillARect(176, 168, 219, 175);
	draw.fillARect(216, 0, 219, 175);
	myGLCD.setFont(SmallFont);
	myGLCD.setColor(VGA_FUCHSIA);
	myGLCD.print("SCORE", 176, 16);
	myGLCD.print("TIME", 176, 72);
	myGLCD.print("SCALE", 176, 128);

}

short int touchWithBlock(bool &snkState)
{
	snkState = SNAKE_DIE;
	draw.erasureRect(10, 80, 160, 112);
	myGLCD.setColor(VGA_FUCHSIA);
	myGLCD.print("YOU ARE DEAD!", 40, 80);
	myGLCD.print("CONTINUE OR NOT?", 26, 96);
	return songOfDie();
}
void touchWithApple(Snake &snk, const short int direct,
	short int &score, short int &scale, short int &speed) 
{
	snk.addLengthAndMove(direct);
	++score;
	if (score % 10 == 0)
	{
		++scale;
		speed -= scale*CUTOFF_SPEED;
	}
}
short int touchwithCrossWall(Snake &snk,short int direct,short int &score,
	short int &scale,short int &speed,short int &startTime,
	bool &isTurnFat,bool &isPansFinding)
{
	short int foodType;
	short int headTouch;
	time snakeTime = millis();
	time creatFoodTime = millis();

	while (1)
	{

		if (afterTime(snakeTime, speed))//�Ƿ����ƶ���ʱ�䡣
		{
			headTouch = snk.getDirection(direct, true);
			switch (headTouch)
			{
			case WALL_AND_BLOCK:
				
				break;
			case EMPTY:
				snk.moveSnake(direct);
				break;
			case APPLE:
				touchWithApple(snk, direct, score, scale, speed);
				break;
			case CROSS_WALL:

				break;
			case CONVERT_HEAD:


				break;
			case MAGNET:

				break;
			case FAT_BODY:

				break;
			default:
				break;
			}

		}

		direct = getSnakeDirect(direct);
		if (isTurnFat == true)//�Ƿ�Ҫ���֡�
			foodType = random(1, 5);
		else foodType = random(1, 4);
		creatASpecialFood(creatFoodTime, foodType);//��ɲ���һ�������ʳ�

		if (isPansFinding == true)//�Ƿ��Ǵ���ģʽ��
		{

		}

	}
}




void printScore(short int score, time tim, short int scal)
{
	myGLCD.setColor(VGA_FUCHSIA);
	myGLCD.printNumI(score, 176, 40);
	myGLCD.printNumI((millis() - tim) / 1000, 176, 96);
	myGLCD.printNumI(scal, 176, 152);
}


//�Ӽ����л�ȡ������Ӧ�����ĸ������ߡ�
short int getKeyboardDirect()
{
	if (getMessage(TO_RIGHT) == TOUCHDOWN)
		return SNAKE_RIGHT;
	if (getMessage(TO_LEFT) == TOUCHDOWN)
		return SNAKE_LEFT;
	if (getMessage(TO_UP) == TOUCHDOWN)
		return SNAKE_UP;
	if (getMessage(TO_DOWN) == TOUCHDOWN)
		return SNAKE_DOWN;
}

short int getSnakeDirect(short int dir)
{
	short int keyDirect = getKeyboardDirect();
	switch (dir){
	case SNAKE_UP:
	case SNAKE_DOWN:
		if (keyDirect == SNAKE_LEFT || keyDirect == SNAKE_RIGHT){
			dir = keyDirect;

			soundOfTouchAndEat(dir);

		}
		break;
	case SNAKE_RIGHT:
	case SNAKE_LEFT:
		if (keyDirect == SNAKE_UP || keyDirect == SNAKE_DOWN){

			dir = keyDirect;

			soundOfTouchAndEat(dir);

		}
		break;
	default:
		break;
	}
	return dir;
}

void creatASpecialFood(time &foodTime,short int foodType)
{
	time betw = random(10,30) * 1000;
	if (afterTime(foodTime, betw))
	{
		Food food(foodType);
	}
}