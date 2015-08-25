#ifndef FOOD_H
#define FOOD_H

#include"Draw.h"
#include"Define.h"


extern short int pointState[22][22];


class Food
{
public:

	//Food�Ĺ��캯������ɽ��������ĵ�һ��������
	//fdtp��ϣ�������Ǹ�ͼƬ��
	Food(short int fdTp, short int col=VGA_BLACK);

	//�����������һ��ʳ������ꡣ
	void setFoodPosition();

	//��ͼƬ����Ļ�ϻ�������
	void drawFood();

	//����ƶ�ʳ��Ĺ�����
	void moveFood();

private:

	//������ʳ��ĵ�󣬽��õ㸳ֵΪ����Ӧ�����͡�
	void setPointAttribute();

	//���������ɵ�ʳ�����ɫ��
	void stdSetFoodColor(short int col);

	//����ʳ��Ҫ�ƶ��ķ���
	short int setMoveDirection();
	//���ú÷������ɸı��£�
	//x��y��ֵ�������Ӧ�Ĳ���ԭ���Ĳ���Ҫ��ͼƬ��
	void afterSetDirsetXY();

	//����ʳ������õ㻹ԭΪ�ա�
	void erasureFood();

	//�ж����ɵ�ʳ��������Ƿ���ʡ�
	bool isASuitablePosition(pos i,pos j);


	pos x, y;//ʳ������ꡣ
	short int foodType;//ʳ�������
	short int color;//ʳ�����ɫ��
};


#endif