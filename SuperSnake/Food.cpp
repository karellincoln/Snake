#include"Food.h"


Food::Food(short int fdTp, short int col)
{
	foodType = fdTp;
	setFoodPosition();
	setPointAttribute();
	stdSetFoodColor(col);

	drawFood();
}



void Food::drawFood()
{
	draw.drawWhichPictrue(x*8, y*8, 8, 8, foodType, color);
}

void Food::moveFood()
{
	afterSetDirsetXY();
	if (pointState[x][y] == EMPTY)
	{
		setPointAttribute();
		drawFood();
	}
}


void Food::setFoodPosition()
{
	pos i, j;
	do{
		i = random(1, 21);
		j = random(1, 21);
	} while (!isASuitablePosition(i,j));
	x = i; y = j;

}


void Food::setPointAttribute()
{
	pointState[x][y] = foodType;
}
void Food::stdSetFoodColor(short int col)
{
	if (col == VGA_BLACK)
	{
		switch (foodType)
		{
		case APPLE:
			color = VGA_RED;
			break;
		case CROSS_WALL:
			color = VGA_MAROON;
			break;
		case CONVERT_HEAD:
			color = VGA_BLUE;
			break;
		case MAGNET:
			color = VGA_FUCHSIA;
			break;
		default:
			color = VGA_GREEN;
			break;
		}
	}
	else color = col;

}


short int Food::setMoveDirection()
{
	short int direct = random(TO_UP, TO_RIGHT + 1);
	return direct;
}

void Food::afterSetDirsetXY()
{
	int dir = setMoveDirection();

	//一定要注意pointState[][]数组的值。
	if (pointState[x][y] == foodType)
	{
		erasureFood();
	}

	switch (dir)
	{
	case TO_UP:
		if (y == 1)y = 20;
		else y--;
		break;
	case TO_DOWN:
		if (y == 20)y = 1;
		else y++;
		break;
	case TO_LEFT:
		if (x == 1)x = 20;
		else --x;
		break;
	case TO_RIGHT:
		if (x == 20)x = 1;
		else ++x;
		break;
	default:
		break;
	}
}

void Food::erasureFood()
{
	pointState[x][y] = EMPTY;
	draw.erasureSquare(x*8, y*8, 8);
}

bool Food::isASuitablePosition(pos i, pos j)
{
	if (pointState[i][j] == EMPTY)return true;
	else return false;
}
