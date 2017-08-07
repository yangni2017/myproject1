/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  find_num.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/07/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/07/2017 01:14:20 PM"
 *                 
 ********************************************************************************/

#include <stdio.h>
void create_num(int arr[])
{
    int i=0,n=1;
    for (;i<1024;i++)
    {
        n++;
        arr[i]=n;
    }
}

void half_find(int arr[],int num,int first_num,int last_num)
{   
    
    int half_num = (first_num + last_num)/2;
    
    if( arr[half_num] == num)
    {
        printf("find it!\n");
        return;
    }
    
    else if( arr[half_num] > num)
    {
        last_num=half_num-1;
        half_find(arr,num,first_num,last_num);
    }
    
    else if( arr[half_num] < num)
    {
        first_num=half_num+1;
        half_find(arr,num,first_num,last_num);
    }
}

void main()
{
    int arr[1024]={0};
    create_num(arr);
    half_find(arr,49,3,500);
}
