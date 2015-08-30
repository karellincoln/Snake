#include"Draw.h"
#include"Map.h"
#include"Food.h"
#include"Snake.h"
#include"Define.h"


extern UTFT myGLCD;
extern uint8_t SmallFont[];

short int fatCount = 0;
short int foodCount = 0;


short int differentMapMode(short int difficulty,bool isPansFinding,
		bool isTurnFat,bool isEatIt)
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
	short int compare = 0;

	time snakeTime = millis();
	time creatFoodTime = millis();
	time foodTime = millis();

	const time startTime = millis();

	short int speed=START_SPEED;

	while (1)
	{
		if (snakeState == SNAKE_DIE)break;
		direct = getSnakeDirect(direct);

		
		if (isTurnFat == true)//是否要变胖。
			foodType = random(1, 6);
		else foodType = random(1, 4);
		creatASpecialFood(creatFoodTime, foodType);//完成产生一个特殊的食物。
		
		if (isPansFinding == true)//是否是闯关模式。
		{
			if (compare!=score&&score%8==0)
			{
				compare = score;
				map.destroyBlock();
				difficulty += 5;
				map.creatBolck(difficulty);
			}
		}

		if (score == 90)
		{
			return killTheGame(score,startTime,scale);/////////////////////////
		}
		
		if (afterTime(snakeTime, speed))//是否到蛇移动的时间。
		{
			if (isEatIt)
			{
				if (++foodCount % 2 == 0)
				{
					fd.moveFood();
					if (afterTime(foodTime, FOOD_TRUN_BLOCK))
					{
						fd.becomeABlock();
						fd.creatANewFood();
					}
				}
			}
			headTouch = snk.getDirection(direct, true);
			soundOfTouchAndEat(headTouch);
			switch (headTouch)
			{
			case SNAKE_BODY:
			case WALL_AND_BLOCK:
				printScore(score, startTime, scale);
				return touchWithBlock(snakeState);//////////////////
				break;
			case EMPTY:
				snk.moveSnake(direct);
				break;
			case APPLE:
				touchWithApple(snk, fd, foodTime, direct, score, scale, speed);
				break;
			case CROSS_WALL:
				snk.setHeadType(CROSS_WALL);
				snk.moveSnake(direct);
				touchWithCrossWall(snk,fd, direct, score, scale, speed, snakeTime,isEatIt);
				break;
			case CONVERT_HEAD:
				snk.moveSnake(direct);
				direct = snk.getTailDirection();
				snk.convertBody();
				break;
			case MAGNET:
				snk.setHeadType(MAGNET);
				snk.moveSnake(direct);
				touchWithMagnet(snk,fd, direct, score, scale, speed, snakeTime,isEatIt);
				break;
			case FAT_BODY:
				++fatCount;
				if (fatCount%2==1)
					snk.setBodySize(FAT_SNAKE);
				else snk.setBodySize(SMALL_SNAKE);
				snk.moveSnake(direct);

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


short int killTheGame(short int score, time startTime, short int scale)
{
	draw.erasureRect(10, 80, 160, 112);
	myGLCD.setColor(VGA_FUCHSIA);
	myGLCD.print("GREAT!", 80, 80);
	printScore(score, startTime, scale);
	while (1){
		if (getMessage(TO_RIGHT) == SWITCHDOWN)
			return GOIN;
		if (getMessage(TO_LEFT) == SWITCHDOWN)
			return BACK;
	}
}



void touchWithApple(Snake &snk,Food &fd, time &foodTime, const short int direct,
	short int &score, short int &scale, short int &speed) 
{
	snk.addLengthAndMove(direct);
	fd.creatANewFood();
	foodTime = millis();
	++score;
	if (score % 5 == 0)
	{
		++scale;
		speed -= scale*CUTOFF_SPEED;
	}
	myGLCD.setColor(VGA_FUCHSIA);
	myGLCD.printNumI(score, 176, 40);
	myGLCD.printNumI(scale, 176, 152);
}



void  touchWithCrossWall(Snake &snk, Food &fd, short int &direct,short int &score,
	short int &scale,short int &speed, time &snakeTime, bool isEatIt)
{
	short int foodType;
	short int headTouch;

	time foodTime = millis();
	time creatFoodTime = millis();
	
	bool eatOthers = false;
	const time statim = millis();
	bool getInBlock = false;

	while (millis()-statim<15000)
	{

		if (afterTime(snakeTime, speed))//是否到蛇移动的时间。
		{
			headTouch = snk.getDirection(direct, true);
			soundOfTouchAndEat(headTouch);
			switch (headTouch)
			{
			case SNAKE_BODY:
			case WALL_AND_BLOCK:
				snk.crossAllBlock(direct);
				getInBlock = true;
				break;
			case EMPTY:
				if (getInBlock)
				{
					snk.onlyMoveHead(direct);
					getInBlock = false;
				}
				else
					snk.moveSnake(direct);
				break;
			case APPLE:
				touchWithApple(snk, fd, foodTime, direct, score, scale, speed);
				break;
			case CROSS_WALL:
				eatOthers = true;
				break;
			case CONVERT_HEAD:
				snk.moveSnake(direct);
				direct = snk.getTailDirection();
				snk.convertBody();

				break;
			case MAGNET:
				eatOthers = true;
				break;
			case FAT_BODY:
				++fatCount;
				if (fatCount % 2 == 1){
					snk.setBodySize(FAT_SNAKE);
					speed *= 2;
				}
				else {
					snk.setBodySize(SMALL_SNAKE);
					speed /= 2;
				}
				snk.moveSnake(direct);
				break;
			default:
				break;
			}

		}
		if (eatOthers)break;
		
		direct = getSnakeDirect(direct);
		
		foodType = random(1, 4);
		creatASpecialFood(creatFoodTime, foodType);//完成产生一个特殊的食物。

		if (score == 90)
		{
			break;
		}

		if (isEatIt)
		{
			if (++foodCount % 2 == 0)
			{
				fd.moveFood();
				if (afterTime(foodTime, FOOD_TRUN_BLOCK))
				{
					fd.becomeABlock();
					fd.creatANewFood();
				}
			}
		}

	}
	snk.setHeadType(EMPTY);
}

void  touchWithMagnet(Snake &snk, Food &fd, short int &direct, short int &score,
	short int &scale, short int &speed, time &snakeTime,bool isEatIt)
{
	short int foodType;
	short int headTouch;
	time foodTime = millis();
	time creatFoodTime = millis();

	bool eatOthers = false;
	const time statim = millis();


	while (millis() - statim<15000)
	{

		if (afterTime(snakeTime, speed))//是否到蛇移动的时间。
		{
			headTouch = snk.getDirection(direct, true);
			soundOfTouchAndEat(headTouch);
			switch (headTouch)
			{
			case SNAKE_BODY:
			case WALL_AND_BLOCK:
				eatOthers = true;
				break;
			case EMPTY:
				snk.moveSnake(direct);
				headTouch = snk.isCloseWithFood();
				soundOfTouchAndEat(headTouch);
				break;
			default:
				break;
			}
			if (eatOthers == true)break;
			switch (headTouch)
			{
			case APPLE:
				touchWithApple(snk, fd, foodTime, direct, score, scale, speed);
				break;
			case CROSS_WALL:
				eatOthers = true;
				break;
			case CONVERT_HEAD:
				direct = snk.getTailDirection();
				snk.convertBody();

				break;
			case MAGNET:
				eatOthers = true;
				break;
			case FAT_BODY:
				++fatCount;
				if (fatCount % 2 == 1)
					snk.setBodySize(FAT_SNAKE);
				else snk.setBodySize(SMALL_SNAKE);
				snk.moveSnake(direct);
				break;
			default:
				break;
			}


		}
		if (eatOthers)break;

		direct = getSnakeDirect(direct);

		foodType = random(1, 4);
		creatASpecialFood(creatFoodTime, foodType);//完成产生一个特殊的食物。

		if (score == 90)
		{
			break;
		}

		if (isEatIt)
		{
			if (++foodCount % 2 == 0)
			{
				fd.moveFood();
				if (afterTime(foodTime, FOOD_TRUN_BLOCK))
				{
					fd.becomeABlock();
					fd.creatANewFood();
				}
			}
		}

	}
	snk.setHeadType(EMPTY);
}


void printScore(short int score, time tim, short int scal)
{
	myGLCD.setColor(VGA_FUCHSIA);
	myGLCD.printNumI(score, 176, 40);
	myGLCD.printNumI((millis() - tim) / 1000, 176, 96);
	myGLCD.printNumI(scal, 176, 152);
}



//从键盘中获取方向，蛇应该往哪个方向走。
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
	if (foodType >= 4)foodType = 4;
	if (afterTime(foodTime, betw))
	{
		Food food(foodType);
	}
}