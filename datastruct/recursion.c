/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  recursion.c
 *    Description:  递归
 *                 
 *        Version:  1.0.0(07/24/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "07/24/2017 08:49:06 PM"
 *                 
 ********************************************************************************/

#include <stdio.h>
int a[10]={1,2,3,4,50,6,7,8,9,10};
int isadd(int n)
{
     if(n == 8)
     {
          return a[n] < a[n+1];      
     }
     else
     {
          return ( a[n] < a[n+1])  &&  isadd(n+1);
     }

}

void main()
{
  printf("%d\n",isadd(0));
}
