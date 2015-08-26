#ifndef SNAKE_H
#define SNAKE_H

#include"Draw.h"
#include"Define.h"

extern short int pointState[22][22];

class Snake
{
public:
	//һ��ʼ��ʼ��������һ������Ϊ2�ġ�
	//ͷ�������������Ͻǵ�һ���ߡ�
	Snake();
	/*
	����direct�����Ϣ�����ж���ͷҪ���ĸ������ƶ�
	seewhat���ж�getDirection�Ƿ�Ҫ����
	�˽��ƶ�����ͷ����������ı�����ͷ������
	short intΪ����Ҫ�ƶ�ȥ�ĵ���������ԡ�
	*/
	short int getDirection(short int direct, bool seeWhat = false);

	//��ɽ����ƶ�������
	void moveSnake(short int direct,short int headColor = VGA_RED,short int bodyColor = VGA_YELLOW);     
	
	//�������߳Ե�ʳ��ʱ��Ҫ�����ߵ����������
	void addLengthAndMove(short int direct, short int headColor = VGA_RED, short int bodyColor = VGA_YELLOW);
	
	
	//����voidҲ�ã������ٿ�����
	//���Կ�Խһ���ϰ������Ҫ��֤�ƶ����ƻ��ϰ��
	short int crossAllBlock(short int direct);

	//�����������ͷ���ϰ�����ʱ��
	//����û�н�������ͷ���ϰ���ʱ�����ƶ���ͷ�Ϳ�����
	void onlyMoveHead(short int direct);

	//������ͷҪ��ʾ�����ͣ�������ͼƬ
	void setHeadType(short int type = EMPTY);

	//Ҫ��ʾ���ߵ������ȡ�
	void setBodySize(short int siz = SMALL_SNAKE);
	
	
	//�������û�б�Ҫ��
	void eatBlock();
	
	

private:
	
	//�����ƶ����ߵ�������¡�
	//
	short int inANewPointSnake(short int direct);



	void drawSnakeHead(short int color = VGA_RED);
	void drawFirstBody(short int color = VGA_YELLOW);
	void erasureSnakeTail();
	void setPointAttribute(pos x,pos y,short int typ);
	

	
	short int snakeBody[MAX_SNAKE_LENGTH][2];
	short int head_type;
	short int length;
	short int body_size;

};







#endif