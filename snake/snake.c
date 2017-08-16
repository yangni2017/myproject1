/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  snake.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/16/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/16/2017 07:21:08 PM"
 *                 
 ********************************************************************************/
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h >
#include <time.h>

#define InitLEN   10
#define MAXLEN 100

#define HIGH 20
#define WIDTH  40

int SnakeLEN=0;
int score=0;       //得分
int barrier_num =0;  //所有障碍物组成点的个数

int half;       
//#define HPRIZON       1
//#define VERTICAL  2

COORD arr[MAXLEN];
COORD tmp_arr[50];

COORD food_pos;
COORD map_pos;
COORD tmp_wall;
COORD tmp_barrier;

#define RIGHT 39
#define LEFT  37
#define UP    38
#define DOWN  40



HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);

void clearSnake();
void showSnake();
void creatFood();
void creatMap();
void die();
void barrier_save();

void creatBarrier(COORD pos,int dir,int len);
void crossWall();

struct wall{
    int dir;
    int len;
    COORD bPos;
};

struct wall wall_arr[50];



void draw_frame(int W,int H,int initX,int initY)   //顺时针画框函数W、H为长度高度；initX ,initY为其实坐标 
{
    COORD pos1={initX,initY};
    int i;

    for(i= 0; i< W;i++)
    {
        pos1.X++;
        SetConsoleCursorPosition(hOut,pos1);
        printf(".");
    }

    for(i= 0; i< H;i++)
    {
        pos1.Y++;
        SetConsoleCursorPosition(hOut,pos1);
        printf(".");
    }

    for(i= 0; i< W;i++)
    {
        pos1.X--;
        SetConsoleCursorPosition(hOut,pos1);
        printf(".");
    }

    for(i= 0; i< H;i++)
    {
        pos1.Y--;
        SetConsoleCursorPosition(hOut,pos1);
        printf(".");
    }

}


void InitSnake(COORD SnakeHead)
{
    int i;
    COORD temp = SnakeHead;
    for( i=0 ; i< InitLEN ; i++ )
    {   
        arr[i]=temp;
        SetConsoleCursorPosition(hOut,temp);

        printf("@");

        temp.X--;
    }

    SnakeLEN = InitLEN;
}

void move(int dir)
{
    int i;
    Sleep(100);
    clearSnake();


    //将蛇头状态给蛇身
    for( i=0;i<SnakeLEN-1;i++)
    {
        arr[SnakeLEN-1-i] = arr[SnakeLEN-2-i];
    }


    switch(dir){
    case RIGHT:
        {
            arr[0].X++;   //蛇头运动
            break;  
        }
    case LEFT:
        {
            arr[0].X--;
            break;  
        }

    case UP:
        {
            arr[0].Y--;
            break;  
        }

    case DOWN:
        {
            arr[0].Y++;
            break;  
        }
    default:
        break;
    }

    die();


    if(food_pos.X == arr[0].X && food_pos.Y == arr[0].Y )    //头的坐标和食物坐标相同（吃食物变长）
    {

        creatFood();
        SnakeLEN++;

        COORD pos2={WIDTH+12,2};   //写计分位置的初始坐标，因为之前方框的起始坐标为(10,1)，所以这里都加1。
        SetConsoleCursorPosition(hOut,pos2);

        score++;
        printf("%d",score);
        printf(" ");        //打印空白用于覆盖上一次计分


    }




 //show snake
    showSnake();


}


void showSnake()
{   
    int i;
    for( i=0; i < SnakeLEN;i++)
    {
        SetConsoleCursorPosition(hOut,arr[i]);
        if(i == 0)
        {
            printf("@");
        }
        else
        {

            printf("*");
        }
    }
}

void clearSnake()   
{   
    int i;
    for( i=0; i < SnakeLEN;i++)
    {
        SetConsoleCursorPosition(hOut,arr[i]);
        printf(" ");
    }
}


void barrier_save()      //保存所有生成的障碍物的点（所有障碍物由点组成）
{
    tmp_arr[barrier_num]=tmp_barrier;
    barrier_num++;           //全局变量
}

void creatBarrier(COORD pos,int dir,int len)
{
    int i =0;
    tmp_barrier=pos;

    for(;i < len; i++)
    {
        static int j=0;
        SetConsoleCursorPosition(hOut,tmp_barrier);
        printf("+");
        if(dir == 1 )
        {
            tmp_barrier.X++;
            barrier_save();    //每次改变都会获得一个新的点，需要把这个点记录下来。
        }
        else 
        {
            tmp_barrier.Y++;
            barrier_save();
        }

        barrier_save();
    }



}


void kbctrl()
{   
    char ch = 'd';
    int dir=RIGHT;
    while(1)
    {   

        if(kbhit())      //加入键盘控制,判断是否有按键
        {
            ch=getch();
        }

        switch(ch)      //判断是否是 'a' 's'
        {
            case 'd':          
            {   
                dir = RIGHT;
                move(dir);
                break;
            }

            case 's':
            {
                dir = DOWN;
                move(dir);
                break;
            }

            case 'a':
            {
                dir = LEFT;
                move(dir);
                break;
            }

            case 'w':
            {   
                dir = UP;
                move(dir);
                break;
            }

            default:
            {
                move(dir);
                break;
            }
        }
    }

}


void creatFood()
{
    srand((unsigned)time(NULL));
    int x = (rand()%(WIDTH-1)+1);  //-1为了产生随机数小于WIDTH，+1为了使产生随机数大于0
    int y = (rand()%(HIGH-1)+1);
    food_pos.X =x;
    food_pos.Y =y;
    SetConsoleCursorPosition(hOut,food_pos);
    printf("o");
}


void myexit()
{
    COORD exit_pos={WIDTH+2,HIGH+2};
    SetConsoleCursorPosition(hOut,exit_pos);
    printf("GAME OVER!");
    exit(0);
}

//死亡的方式：
void die()
{
    int i;
    for(i = 1;i < SnakeLEN-1;i++ )   //吃到自己，就会死掉。
    {
        if(arr[0].X == arr[i].X && arr[0].Y == arr[i].Y)
        {
            myexit();   
        }
    }

    if(arr[0].X >= WIDTH || arr[0].X <= 0 || arr[0].Y >= HIGH || arr[0].Y <= 0 )   //撞墙就死掉
    {
        myexit();
    }


    for(i = 0;i < 50;i++ )   //撞到障碍物，死掉
    {

        if(arr[0].X == tmp_arr[i].X && arr[0].Y == tmp_arr[i].Y)
        {
            myexit();
        }
    }

}


void score_frame()
{
    //计分方框
    draw_frame(10,5,WIDTH+10,0);
    COORD pos1={WIDTH+11,1};
    SetConsoleCursorPosition(hOut,pos1);
    printf("得分：");

    //计分
    COORD pos2={WIDTH+12,2};   //写计分位置的初始坐标，因为之前方框的起始坐标为(10,1)，所以这里都加1。
    SetConsoleCursorPosition(hOut,pos2);

    printf("%d",score);
}



int main(int argc, char* argv[])
{

    system("title 贪吃蛇");
    COORD pos={5,3};
    crossWall();
    draw_frame(WIDTH,HIGH,0,0);
    score_frame();

    InitSnake(pos);


    creatFood();

/*  
    while(1)
    {
        move(RIGHT);
        if(kbhit())
        {
            ch=getch();
            break;
        }   
    }
*/  
    kbctrl();

    printf("\n");
    return 0;
}


void crossWall()
{
    srand((unsigned)time(NULL));
    int i =0;
    for ( ; i < 5 ; i++)
    {

        tmp_wall.X=(rand()%(WIDTH-3));
        tmp_wall.Y=(rand()%(HIGH-3));
    //  tmp_arr[i] = tmp_wall;

        half = (rand()%2+1);   //随机获得 1 或者 2 ，两者概率都为二分之一

        creatBarrier(tmp_wall,half,3);
    }
}
