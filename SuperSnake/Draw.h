#ifndef DRAW_H
#define DRAW_H
#include<UTFT\UTFT.h>
#include"Define.h"

class Draw
{
public:
	//选择要画那一幅图片。
	void drawWhichPictrue(pos x, pos y, short int width, short int height,
		short int typ, short int color = VGA_SILVER);
	
	//分别在左上为（x0,y0),和右下为（x1,y1)的填满和空的矩形。
	void drawARect(pos x0, pos y0, pos x1, pos y1, short int color = VGA_SILVER);
	void fillARect(pos x0, pos y0, pos x1, pos y1, short int color = VGA_SILVER);
	
	//这两个是画正方形。
	void drawASquare(pos x, pos y, short int size, short int color = VGA_SILVER);
	void fillASquare(pos x, pos y, short int size, short int color = VGA_SILVER);

	//将一个矩形或正方形画成黑色。及将他们擦除。
	void erasureRect(pos x0, pos y0, pos x1, pos y1);
	void erasureSquare(pos x, pos y, short int size);

	//将整个屏幕清空。
	void cleanScreen();

private:

	//将一副指定的char tp[]中所储存的图片，
	//左上在（x,y)的位置将图片打印出来。
	void drawAPicture(pos x, pos y, short int width, short int height,
					  char tp[], short int color = VGA_SILVER);

	//下面数组储存了相应图片的信息。
	static char apple[], crossWall[], convertHead[], magnet[];
	static char s[], n[], a[], k[], e[];
	static char snake1[], snake2[];
};

extern Draw draw;



#endif