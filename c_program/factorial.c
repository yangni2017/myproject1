/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  jiecheng.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/11/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/11/2017 10:26:29 AM"
 *                 
 ********************************************************************************/

#include <stdio.h>

int func(int n)
{
    while (n > 1)
    {
        sleep(2);
        return n*func(n-1);
        //sleep(5);
    }

}

int main()
{
    //int num;
    //scanf("%d",&num);
    printf("%d",func(5));
}
