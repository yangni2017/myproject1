/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  stack.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(07/25/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "07/25/2017 10:04:10 AM"
 *                 
 ********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define LEN 50
typedef struct mystack
{
     int top;        
     int data[LEN];
};

struct mystack selfstack ={-1, {0} };

int isempty ();  
void setempty();  
int push(int num);   
int pop();       

int isempty()
{
     if(selfstack.top == -1)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}

void setempty( )
{
     selfstack.top == -1;
}

int push(int num)
{
     if(selfstack.top == LEN-1 )  
     {
          printf("the stack is full!");
          return -1;   //栈溢出
     }
     selfstack.top+=1;   //下标往前移动
     selfstack.data[ selfstack.top] =num;
     return 0;
}

int pop( )
{
     if(selfstack.top == -1)
     {
          printf("the stack is empty!");
          return -1;//栈为空
     }
     else
     {
          selfstack.top  -=1;
          return selfstack.data[selfstack.top+1];
     }
}


void main()
{
     int a[10] = {1,2,3,4,5,6,7,8,9,10};
     int i;
     for(i=0;i<10;i++)
     {
          push(a[i]);   //压入数据
     }
     while( !isempty() )
     {
          printf("%d ",pop());  //输出数据
     }
}

