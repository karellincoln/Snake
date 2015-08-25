#include"Snake.h"


Snake::Snake()
{
	length = 1;
	snakeBody[0][0] = 1;
	snakeBody[0][1] = 1;
	head_type = EMPTY;
	body_size = SMALL_SNAKE;
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
	drawSnakeHead(headColor);
	drawFirstBody(bodyColor);
}

void Snake::crossAllBlock()
{

}

void Snake::setHeadType(short int type)
{

}

void Snake::setBodySize(short int siz)
{

}

void Snake::eatBlock()
{

}

short int Snake::attachWithWhat()
{

}

bool Snake::inANewPointSnake(short int direct)
{

}

void Snake::drawSnakeHead(short int color)
{
	pos x = snakeBody[0][0];
	pos y = snakeBody[0][1];
	draw.fillASquare(x * 8, y * 8, body_size, VGA_RED);
	setPointAttribute(x, y, SNAKE_HEAD);
}

void Snake::drawFirstBody(short int color)
{
	pos x = snakeBody[1][0];
	pos y = snakeBody[1][1];
	draw.erasureSquare(x * 8, y * 8, body_size);
	draw.fillASquare(x * 8, y * 8, body_size, VGA_YELLOW);
	setPointAttribute(x, y, SNAKE_BODY);
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
		pointState[x][y] = type;
		pointState[x + 1][y] = type;
		pointState[x][y + 1] = type;
		pointState[x + 1][y + 1] = type;
	}
}