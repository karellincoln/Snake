#ifndef FUNCTION_H
#define FUNCTION_H



//在SuperSanke.ino中定义的函数。
short int getMessage(short int pin);
bool afterTime(time &tim, int between);
short int songOfStart();
void soundOfTouchAndEat(short int d);
short int songOfDie();




//在start.cpp中定义的函数。
void start();
void startUI();
short int chooseAGame();
void drawOptionUI();
short int optionalGame(char *p[],short int choice);
void drawGameName(char *p[], short int choice,bool dir);





//在PartOfGame.cpp中定义的函数。
class Snake;
class Food;

short int differentMapMode(short int difficulty, bool isPansFinding = false,
	bool isTurnFat = false, bool isEatIt = false);
void gameUI();

short int touchWithBlock(bool &snkState);
short int killTheGame(short int score, time startTime, short int scale);

void touchWithApple(Snake &snk, Food &fd, time &foodTime, const short int direct,
	short int &score, short int &scale, short int &speed);

void  touchWithCrossWall(Snake &snk, Food &fd, short int &direct, short int &score,
	short int &scale, short int &speed, time &snakeTime, bool isEatIt);

void  touchWithMagnet(Snake &snk, Food &fd, short int &direct, short int &score,
	short int &scale, short int &speed, time &snakeTime, bool isEatIt);

void printScore(short int score, time tim, short int scal);
short int getKeyboardDirect();
short int getSnakeDirect(short int dir);
void creatASpecialFood(time &foodTime, short int foodType);


#endif