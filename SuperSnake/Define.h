#ifndef DEFINE_H
#define DEFINE_H





//定义一些常用的类型别名。
typedef short int pos;
typedef unsigned long time;

//方向键和喇叭的引脚的宏定义。
#define MUSIC 3
#define TO_UP 4
#define TO_DOWN 5
#define TO_LEFT 6
#define TO_RIGHT 7



//各种图片的宏定义，方便理解。

#define APPLE 0
#define CROSS_WALL 1
#define CONVERT_HEAD 2
#define MAGNET 3
#define FAT_BODY 4
#define SNAKE_SHAPE_ONE 5
#define SNAKE_SHAPE_TWO 6
#define S_OF_SNAKE 7
#define N_OF_SNAKE 8
#define A_OF_SNAKE 9
#define K_OF_SNAKE 10
#define E_OF_SNAKE 11


//游戏界面上的各种不同物体的相互区别。
#define WALL_AND_BLOCK 8
#define SNAKE_HEAD 9
#define SNAKE_BODY 10
#define EMPTY -1

//定义地图上的复杂程度。
#define MAP_EMPTY 0
#define MAP_EASY 10
#define MAP_MIDDLE 20
#define MAP_HARD 30



//蛇用的宏定义。
#define MAX_SNAKE_LENGTH 100
#define SMALL_SNAKE 8
#define FAT_SNAKE 16

#define SNAKE_DIE 0
#define SNAKE_ALIVE 1

//蛇行动时，蛇头的方向与方向键的定义数字一样。
#define SNAKE_UP 4
#define SNAKE_DOWN 5
#define SNAKE_LEFT 6
#define SNAKE_RIGHT 7


//定义开关的状态
#define SWITCHDOWN 1
#define SWITCHUP 2
#define TOUCHDOWN 1
#define TOUCHUP 2

//游戏路径。
#define BACK 20
#define GOIN 21

//不同的游戏模式。

#define HARD 0
#define MIDDLE 1
#define EASY 2
#define CLASSIC 3
#define MAGIC 4
#define EAT_IT 5
#define PATHS 6
#define GAMEMODE_NUM 7

//游戏的速度的宏定义
#define START_SPEED 150
#define CUTOFF_SPEED 10  
#define FAST_SPEED  40

#include"Music.h"
#include"Function.h"


#endif