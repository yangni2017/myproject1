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

void find_num(int arr[])
{
    int i=0;
    for(;i<1024;i++)
    {
        if(arr[i] == 277)
        {
            printf("use the %d times to find it\n",i+1);
        }
    }
}


void half_find(int arr[])
{
    int first_num = 0;
    int last_num = 1023;
    int half_num = 0;
    int flags=0;
   // for(;i<1024;i++)
   // {    
        while (first_num < last_num)
        {
            half_num = (first_num + last_num)/2;
            if( arr[half_num] == 277)
            {
                flags++;
                printf("use %d times to find it\n",flags);
                break;
            }
            else if( arr[half_num] > 277)
            {
                flags++;
                last_num=half_num-1;
            }
            else
            {
                flags++;
                first_num=half_num+1;
            }
        }
   // }
}


void main()
{
    int arr[1024]={0};
    create_num(arr);
    find_num(arr);
    half_find(arr);
}
