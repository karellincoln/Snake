#include"Map.h"




//记录图中各点的状态。是蛇，食物，还是墙。
short int pointState[22][22];

//构造地图，difficulty为地图的难度。
//initalize为是否要对数组pointState进行赋值，默认为是。
Map::Map(short int difficulty,bool initalize)
{
	if (initalize)
	{
		initalizePointState();
	}
	creatBolck(difficulty);
}

Map::Map(short int a[],short int length)
{
	initalizePointState();
	pos x, y;
	for (pos i = 0; i < length; i++)
	{
		y = a[i] / 22;
		x = a[i] - y * 22;
		pointState[x][y] = WALL_AND_BLOCK;
		drawBlock(x, y);
	}
}


void Map::creatBolck(short int num)
{
	pos x, y;
	for (short int i = 0; i < num; i++)
	{
		do{
			x = random(1, 21);
			y = random(2, 21);
		} while (!IsASuitablePoint(x, y));
		pointState[x][y] = WALL_AND_BLOCK;
		drawBlock(x, y);

	}

}

void Map::destroyBlock()
{
	
	for (pos i = 1; i < 21; i++)
	{
		for (pos j = 1; j < 21; j++)
		{
			if (pointState[i][j] == WALL_AND_BLOCK)
				cleanBlock(i,j);
		}
	}
}


//void Map::drawAMap()
//{
//	drawWall();
//	drawBlock();
//}

void Map::drawBlock(pos x, pos y)
{
	draw.fillASquare(x * 8, y * 8, 8);
}
void Map::cleanBlock(pos x, pos y)
{
	draw.fillASquare(x * 8, y * 8, 8, VGA_BLACK);
	pointState[x][y] == EMPTY;
}


void Map::initalizePointState()
{
	for (pos i = 0; i < 22; i++)
	{
		for (pos j = 0; j < 22; j++)
		{
			if (i == 0 || j == 0 || i == 21 || j == 21)
			{
				pointState[i][j] = WALL_AND_BLOCK;
				drawBlock(i, j);
			}
			else pointState[i][j] = EMPTY;
		}
	}
}


bool Map::IsASuitablePoint(pos x, pos y)
{
	if (pointState[x][y] == EMPTY)
	{
		if (pointState[x + 1][y]==WALL_AND_BLOCK || pointState[x - 1][y]==WALL_AND_BLOCK
			||pointState[x][y + 1] == WALL_AND_BLOCK || pointState[x][y - 1] == WALL_AND_BLOCK)
			return 1;
		for (pos i = x - 2; i <= x + 2; i++)
		{
			for (pos j = y - 2; j <= y + 2; j++)
			{
				if ((i == x - 2 && i >= 0) || (i == x + 2 && i <= 21) ||
					(j == y - 2 && j >= 0) || (j == y + 2 && j <= 21)){
					if (pointState[i][j] != EMPTY)return 0;//条件可以改成pointState[i][j]==WALL_AND_BLOCK.
				}
			}
		}
		return 1;
	}
	else return 0;
}



