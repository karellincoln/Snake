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







#endif