#ifndef DEFINE_H
#define DEFINE_H






typedef short int pos;


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
#define SNAKE_SHAPE_ONE 4
#define SNAKE_SHAPE_TWO 5
#define SNAKE_SHAPE_THREE 6
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



//
#define MAX_SNAKE_LENGTH 100
#define SMALL_SNAKE 8
#define FAT_SNAKE 16





#endif