#ifndef MAP_H
#define MAP_H

#include"Draw.h"
#include"Define.h"




class Map
{
public:

	//�����ͼ��difficultyΪ��ͼ���Ѷȡ�
	Map(short int difficulty);

	//void drawAMap();
	//��һ���������ʾ�ĵ�ͼ��������
	Map(short int a[],short int length);
	

private:

	//��һ�����ӡ������
	void drawBlock(pos x, pos y);

	//��ǽ���ڲ��յĵ㼰pointState[][]���и�ֵ���������ܵ�ǽ��ӡ������
	void initalizePointState();

	//numΪ����Ҫ���ϰ���ĸ�����������Ľ����Ǵ�ӡ������
	void creatBolck(short int num);

	//�ж������ɵĵ��Ƿ���ʵ����֮����һ���ľ��롣
	bool IsASuitablePoint(pos x, pos y);

};







#endif