#ifndef MAP_H
#define MAP_H

#include"Draw.h"
#include"Define.h"




class Map
{
public:

	//构造地图，difficulty为地图的难度。
	Map(short int difficulty,bool initalize=true);

	//void drawAMap();
	//将一个用数组表示的地图画出来。
	Map(short int a[],short int length);

	//num为所想要的障碍物的个数，并合理的将他们打印出来。
	void creatBolck(short int num);

	//将墙壁内的block清除掉。
	void destroyBlock();

private:

	//将一个点打印出来。
	void drawBlock(pos x, pos y);
	void cleanBlock(pos x, pos y);

	//将墙和内部空的点及pointState[][]进行赋值。并将四周的墙打印出来。
	void initalizePointState();

	//判断所生成的点是否合适点与点之间有一定的距离。
	bool IsASuitablePoint(pos x, pos y);

};







#endif