#ifndef FUNCTION_H
#define FUNCTION_H



//��SuperSanke.ino�ж���ĺ�����
short int getMessage(short int pin);
bool afterTime(time &tim, int between);
short int songOfStart();
void soundOfTouchAndEat(short int d);
short int songOfDie();




//��start.cpp�ж���ĺ�����
void start();
void startUI();
short int chooseAGame();
void drawOptionUI();
short int optionalGame(char *p[],short int choice);
void drawGameName(char *p[], short int choice,bool dir);





//��PartOfGame.cpp�ж���ĺ�����
short int differentMapMode(short int difficulty, bool isPansFinding = false,
	bool isTurnFat = false);
void gameUI();




#endif