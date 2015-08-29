#ifndef MAP_H
#define MAP_H

#include"Draw.h"
#include"Define.h"




class Map
{
public:

	//�����ͼ��difficultyΪ��ͼ���Ѷȡ�
	Map(short int difficulty,bool initalize=true);

	//void drawAMap();
	//��һ���������ʾ�ĵ�ͼ��������
	Map(short int a[],short int length);

	//numΪ����Ҫ���ϰ���ĸ�����������Ľ����Ǵ�ӡ������
	void creatBolck(short int num);

	//��ǽ���ڵ�block�������
	void destroyBlock();

private:

	//��һ�����ӡ������
	void drawBlock(pos x, pos y);
	void cleanBlock(pos x, pos y);

	//��ǽ���ڲ��յĵ㼰pointState[][]���и�ֵ���������ܵ�ǽ��ӡ������
	void initalizePointState();

	//�ж������ɵĵ��Ƿ���ʵ����֮����һ���ľ��롣
	bool IsASuitablePoint(pos x, pos y);

};







#endif