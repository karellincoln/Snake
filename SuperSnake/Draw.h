#ifndef DRAW_H
#define DRAW_H
#include<UTFT\UTFT.h>
#include"Define.h"

class Draw
{
public:
	//ѡ��Ҫ����һ��ͼƬ��
	void drawWhichPictrue(pos x, pos y, short int width, short int height,
		short int typ, short int color = VGA_SILVER);
	
	//�ֱ�������Ϊ��x0,y0),������Ϊ��x1,y1)�������Ϳյľ��Ρ�
	void drawARect(pos x0, pos y0, pos x1, pos y1, short int color = VGA_SILVER);
	void fillARect(pos x0, pos y0, pos x1, pos y1, short int color = VGA_SILVER);
	
	//�������ǻ������Ρ�
	void drawASquare(pos x, pos y, short int size, short int color = VGA_SILVER);
	void fillASquare(pos x, pos y, short int size, short int color = VGA_SILVER);

	//��һ�����λ������λ��ɺ�ɫ���������ǲ�����
	void erasureRect(pos x0, pos y0, pos x1, pos y1);
	void erasureSquare(pos x, pos y, short int size);

	//��������Ļ��ա�
	void cleanScreen();

private:

	//��һ��ָ����char tp[]���������ͼƬ��
	//�����ڣ�x,y)��λ�ý�ͼƬ��ӡ������
	void drawAPicture(pos x, pos y, short int width, short int height,
					  char tp[], short int color = VGA_SILVER);

	//�������鴢������ӦͼƬ����Ϣ��
	static char apple[], crossWall[], convertHead[], magnet[];
	static char s[], n[], a[], k[], e[];
	static char snake1[], snake2[];
};

extern Draw draw;



#endif