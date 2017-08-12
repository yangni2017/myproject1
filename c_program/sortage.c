/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  sortage.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/11/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/11/2017 03:04:35 PM"
 *                 
 ********************************************************************************/

#include <stdio.h>
void sortage(int arr[],int len)
{
    int i=0;
    if (arr == NULL || len <= 0)
    {
        return;
    }

    const int oldestAge = 99;     //最大年龄
    int timeofAge[oldestAge+1];   //每个年龄次数

    //初始化数组
    for(i = 0;i <= oldestAge;i++)
    {
        timeofAge[i] = 0;
    }

    for (i = 0;i < len;i++)
    {
        int age = arr[i];
        if(age < 0 || age > oldestAge )
        {
            printf("age is not in the range");
        }
        timeofAge[age]++;
    }
    
    int index=0;
    int j=0;
    for (i = 0;i <= oldestAge;i++)
    {
        for (j = 0;j < timeofAge[i];j++) 
        {
            arr[index] = i;
            ++index;
        }
    }

}
void main()
{
    int i=0;
    int arr[7]={22,18,23,22,50,34,19};
    sortage(arr,7);
    for(i = 0;i < 7;i++)
    {
        printf("%d ",arr[i]);
    }
}



