#ifndef SNAKE_H
#define SNAKE_H

#include"Draw.h"
#include"Define.h"

extern short int pointState[22][22];

class Snake
{
public:
	//一开始初始化，构造一个长度为2的。
	//头和身体在最左上角的一条蛇。
	Snake();
	/*
	接收direct这个消息，并判断蛇头要往哪个方向移动
	seewhat是判断getDirection是否要仅仅
	了解移动后蛇头的坐标而不改变其蛇头的坐标
	short int为返回要移动去的点的坐标属性。
	*/
	short int getDirection(short int direct, bool seeWhat = false);

	//完成将蛇移动的任务。
	void moveSnake(short int direct,short int headColor = VGA_RED,short int bodyColor = VGA_YELLOW);     
	
	//完成如果蛇吃到食物时，要增长蛇的身体的需求。
	void addLengthAndMove(short int direct, short int headColor = VGA_RED, short int bodyColor = VGA_YELLOW);
	
	
	//返回void也好，等下再看看。
	//可以跨越一切障碍物，函数要保证移动后不破坏障碍物。
	short int crossAllBlock(short int direct);

	//这个是用来蛇头在障碍物中时，
	//身体没有进来，蛇头出障碍物时仅仅移动蛇头就可以了
	void onlyMoveHead(short int direct);

	//设置蛇头要显示的类型，及哪张图片
	void setHeadType(short int type = EMPTY);

	//要显示的蛇的身体宽度。
	void setBodySize(short int siz = SMALL_SNAKE);
	
	
	//发现这个没有必要。
	void eatBlock();
	
	

private:
	
	//设置移动后，蛇的坐标更新。
	//根据direct 的方向更新向前移动一格蛇的坐标。
	short int inANewPointSnake(short int direct);


	//绘画蛇头的并用color改变他的颜色
	//还要将pointState的相应的点改变其属性。
	void drawSnakeHead(short int color = VGA_RED);

	//绘画蛇头后的第一个点的并用color改变他的颜色
	//还要将pointState的相应的点改变其属性。
	void drawFirstBody(short int color = VGA_YELLOW);

	//将一个尾部的点删去并将pointState设置为EMPTY的属性
	void erasureSnakeTail();

	//根据typ设置坐标为（x，y）的点的属性。
	void setPointAttribute(pos x,pos y,short int typ);
	

	//用于存储身体每一节的坐标，
	short int snakeBody[MAX_SNAKE_LENGTH][2];
	
	//记录蛇的身体长度。
	short int length;

	//存储蛇头是哪一张图片。
	short int head_type;

	//存储蛇身体的尺寸。
	short int body_size;

};







#endif