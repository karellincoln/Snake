#ifndef DEFINE_H
#define DEFINE_H





//����һЩ���õ����ͱ�����
typedef short int pos;
typedef unsigned long time;

//����������ȵ����ŵĺ궨�塣
#define MUSIC 3
#define TO_UP 4
#define TO_DOWN 5
#define TO_LEFT 6
#define TO_RIGHT 7



//����ͼƬ�ĺ궨�壬������⡣

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


//��Ϸ�����ϵĸ��ֲ�ͬ������໥����
#define WALL_AND_BLOCK 8
#define SNAKE_HEAD 9
#define SNAKE_BODY 10
#define EMPTY -1

//�����ͼ�ϵĸ��ӳ̶ȡ�
#define MAP_EMPTY 0
#define MAP_EASY 10
#define MAP_MIDDLE 20
#define MAP_HARD 30



//���õĺ궨�塣
#define MAX_SNAKE_LENGTH 100
#define SMALL_SNAKE 8
#define FAT_SNAKE 16

#define SNAKE_DIE 0
#define SNAKE_ALIVE 1

//���ж�ʱ����ͷ�ķ����뷽����Ķ�������һ����
#define SNAKE_UP 4
#define SNAKE_DOWN 5
#define SNAKE_LEFT 6
#define SNAKE_RIGHT 7


//���忪�ص�״̬
#define SWITCHDOWN 1
#define SWITCHUP 2
#define TOUCHDOWN 1
#define TOUCHUP 2

//��Ϸ·����
#define BACK 20
#define GOIN 21

//��ͬ����Ϸģʽ��

#define HARD 0
#define MIDDLE 1
#define EASY 2
#define CLASSIC 3
#define MAGIC 4
#define EAT_IT 5
#define PATHS 6
#define GAMEMODE_NUM 7

//��Ϸ���ٶȵĺ궨��
#define START_SPEED 150
#define CUTOFF_SPEED 10  
#define FAST_SPEED  40

#include"Music.h"
#include"Function.h"


#endif