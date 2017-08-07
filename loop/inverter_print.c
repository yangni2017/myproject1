/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  inverter_print.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/07/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/07/2017 02:05:48 PM"
 *                 
 ********************************************************************************/

#include <stdio.h>


int getLen(int num)
{
    int flags = 0;
    for (num; num >0 ; num/=10)
    {
        flags++;   
    }
    return flags;
}

int getIndex(int len)
{
    int i=0;
    int res = 1;
    for (i = 0; i < len ; i++)
    {
        res=res*10;
    }
    return res;
}


int main()
{
    int num,temp,LastNum;
    printf("please input a num:\n");
    scanf("%d",&num);
    
    int len = getLen(num);
    
    int i=0;   
    for(i = 0; i<len ; i++)
    {
        
        temp=num%10;
        num=num/10;
        
        LastNum+=temp*getIndex(len-i-1);
    }

    printf("the resault=%d\n",LastNum);


}

