#ifndef FOOD_H
#define FOOD_H

#include"Draw.h"
#include"Define.h"


extern short int pointState[22][22];


class Food
{
public:

	//Food的构造函数，完成建立对象后的第一步工作。
	//fdtp是希望生成那个图片。
	Food(short int fdTp, short int col=VGA_BLACK);

	//用于随机生成一个食物的坐标。
	void setFoodPosition();

	//将图片在屏幕上画出来。
	void drawFood();

	//完成移动食物的工作。
	void moveFood();

private:

	//将生成食物的点后，将该点赋值为其相应的类型。
	void setPointAttribute();

	//设置所生成的食物的颜色。
	void stdSetFoodColor(short int col);

	//设置食物要移动的方向。
	short int setMoveDirection();
	//设置好方向后，完成改变下，
	//x，y的值并完成相应的擦除原来的不需要的图片。
	void afterSetDirsetXY();

	//擦除食物，并将该点还原为空。
	void erasureFood();

	//判断生成的食物的坐标是否合适。
	bool isASuitablePosition(pos i,pos j);


	pos x, y;//食物的坐标。
	short int foodType;//食物的类型
	short int color;//食物的颜色。
};


#endif