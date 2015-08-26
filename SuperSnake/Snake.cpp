#include"Snake.h"


Snake::Snake()
{
	length = 2;
	snakeBody[0][0] = 2;
	snakeBody[0][1] = 1;
	snakeBody[1][0] = 1;
	snakeBody[1][1] = 1;
	pointState[2][1] = SNAKE_HEAD;
	pointState[1][1] = SNAKE_HEAD;
	head_type = EMPTY;
	body_size = SMALL_SNAKE;
	drawSnakeHead();
	drawFirstBody();
}

//等下要注意是有引用是否有效，
short int Snake::getDirection(short int direct, bool seeWhat)
{
	pos x = snakeBody[0][0];
	pos y = snakeBody[0][1];
	pos i = body_size / 8;
	switch (direct)
	{
	case TO_UP:
		y-=i;
		break;
	case TO_DOWN:
		y+=i;
		break;
	case TO_LEFT:
		x-=i;
		break;
	case TO_RIGHT:
		x+=i;
		break;
	default:
		break;
	}
	if (seeWhat)
	{
		if (i == 1)
		{
			if(x>=0&&x<22&&y>=0&&y<22)return pointState[x][y];
			else return WALL_AND_BLOCK;
		}
		else{
			if (x<-1 || x>22 || y<-1 || y>22)return WALL_AND_BLOCK;
			for (int j = 0; j != 2; j++)
			{
				for (int k = 0; k != 2;k++)
				if (x+j>=0&&x+j<=21&&y+k>=0&&y+k<=21)
					if (pointState[x + j][y + k] != EMPTY)
						return pointState[x + j][y + k];
			}
			return EMPTY;
		}
	}
	snakeBody[0][0] = x;
	snakeBody[0][1] = y;
	if (i == 1)
	{
		if (x >= 0 && x<22 && y >= 0 && y<22)return pointState[x][y];
		else return WALL_AND_BLOCK;
	}
	else{
		if (x<-1 || x>22 || y<-1 || y>22)return WALL_AND_BLOCK;
		for (int j = 0; j != 2; j++)
		{
			for (int k = 0; k != 2; k++)
			if (x + j >= 0 && x + j <= 21 && y + k >= 0 && y + k <= 21)
			if (pointState[x + j][y + k] != EMPTY)
				return pointState[x + j][y + k];
		}
		return EMPTY;
	}

}

void Snake::moveSnake(short int direct, short int headColor, short int bodyColor)
{
	erasureSnakeTail();
	inANewPointSnake(direct);
	drawSnakeHead(headColor);
	drawFirstBody(bodyColor);

}

void Snake::addLengthAndMove(short int direct, short int headColor, short int bodyColor)
{
	length++;
	inANewPointSnake(direct);
	setPointAttribute(snakeBody[length - 1][0], snakeBody[length - 1][1], SNAKE_BODY);
	drawSnakeHead(headColor);
	drawFirstBody(bodyColor);
}

void Snake::onlyMoveHead(short int direct)
{
	getDirection(direct);
	drawSnakeHead();
}


short int Snake::crossAllBlock(short int direct)
{
	short int type;
	pos x = snakeBody[0][0];
	pos y = snakeBody[0][1];
	if (pointState[x][y] == SNAKE_HEAD)
	{
		erasureSnakeTail();
		type=inANewPointSnake(direct);
		drawFirstBody();
		
	}
	else type=getDirection(direct);
	x = snakeBody[0][0];
	y = snakeBody[0][1];
	switch (x)
	{
	case -3:
	case -1:
		snakeBody[0][0] = 21;
		break;
	case 23:
		snakeBody[0][0] = -1;
		break;
	case 22:
		snakeBody[0][0] = 0;
		break;
	default:
		break;
	}
	switch (y)
	{
	case -3:
	case -1:
		snakeBody[0][1] = 21;
		break;
	case 23:
		snakeBody[0][1] = -1;
		break;
	case 22:
		snakeBody[0][1] = 0;
		break;
	default:
		break;
	}

	return type;
}

void Snake::setHeadType(short int type)
{
	head_type = type;
}


void Snake::setBodySize(short int siz)
{
	body_size = siz;
}

void Snake::eatBlock()
{
	
}


short int Snake::inANewPointSnake(short int direct)
{
	short int temp;
	for (int i = length - 1; i > 0; i--)
	{
		for (int j = 0; j < 2; j++)
		{
			snakeBody[i][j] = snakeBody[i - 1][j];
		}
	}
	return getDirection(direct);
}


void Snake::drawSnakeHead(short int color)
{
	pos x = snakeBody[0][0];
	pos y = snakeBody[0][1];
	draw.drawWhichPictrue(x*8, y*8, body_size, body_size, head_type, color);
	setPointAttribute(x, y, SNAKE_HEAD);
}

void Snake::drawFirstBody(short int color)
{
	if (length != 1)
	{
		pos x = snakeBody[1][0];
		pos y = snakeBody[1][1];
		if (pointState[x][y] == SNAKE_HEAD)
		{
			draw.erasureSquare(x * 8, y * 8, body_size);
			draw.fillASquare(x * 8, y * 8, body_size, color);
			setPointAttribute(x, y, SNAKE_BODY);
		}
	}
}

void Snake::erasureSnakeTail()
{
	pos x = snakeBody[length - 1][0];
	pos y = snakeBody[length - 1][1];
	draw.erasureSquare(x*8, y*8, body_size);
	setPointAttribute(x, y, EMPTY);

}

void Snake::setPointAttribute(pos x, pos y, short int type)
{
	if (body_size == SMALL_SNAKE)pointState[x][y] = type;
	else
	{
		//保证点在数组中。
		if ((x >= 0 && x<22) && (y>=0 && y < 22))
		{
			pointState[x][y] = type;
			pointState[x + 1][y] = type;
			pointState[x][y + 1] = type;
			pointState[x + 1][y + 1] = type;
		}
	}
}