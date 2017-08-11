/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  tentotwo.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(07/25/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "07/25/2017 09:44:40 AM"
 *                 
 ********************************************************************************/
#include <stdio.h>

void tentotwo(int num)
{
     if(num!=0)
     {
          int m=num%2;
          num=num/2;
          tentotwo(num);   
          printf("%d",m);       
     }
}

int main()
{
   tentotwo(10); 
}
