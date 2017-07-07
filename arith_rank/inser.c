/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  inser.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(07/06/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "07/06/2017 08:20:45 AM"
 *                 
 ********************************************************************************/
#include <stdio.h>
void insert_rank(int a[],int n)
{
    int i;
    for(i=1;i<n;i++)
    {
        int j=0;
        while( (a[j]<a[i]) && (j<i))
        {
            j++;
        }
    
        if(i !=j )     
        {
           int k;
           int temp=a[i];
           for(k=i;k>j;k--)
           {
                a[k]=a[k-1];
           }
           a[j]=temp;
        }
    }
}

int main()
{
    int i;
    int num[6]={7,6,5,8,3,17};
    insert_rank(num,6);

    for(i=0;i<6;i++)
    {
        printf("%d ",num[i]);
    }
    printf("\n");
    return 0;
}
