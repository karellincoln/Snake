#ifndef SNAKE_H
#define SNAKE_H

#include"Draw.h"
#include"Define.h"

extern short int pointState[22][22];

class Snake
{
public:
	Snake();
	
	void moveSnake(short int direct,short int headColor,short int bodyColor);     
	void addLengthAndMove(short int direct, short int headColor, short int bodyColor);
	void crossAllBlock();
	void setHeadType(short int type);
	void setBodySize(short int siz);
	void eatBlock();

	short int attachWithWhat();

private:
	
	//设置移动后，蛇的坐标更新。
	bool inANewPointSnake(short int direct);



	void drawSnakeHead(short int color);
	void drawFirstBody(short int color);
	void erasureSnakeTail();
	void setPointAttribute(pos x,pos y,short int typ);


	
	short int snakeBody[MAX_SNAKE_LENGTH][2];
	short int head_type;
	short int length;
	short int body_size;

};







#endif