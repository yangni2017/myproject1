/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  merge_order.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/10/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/10/2017 01:53:07 PM"
 *                 
 ********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
void mergearray(int a[], int first, int mid, int last, int temp[])  
{  
    int i = first, j = mid + 1;  
    int m = mid,   n = last;  
    int k = 0;  
      
    while (i <= m && j <= n)  
    {  
        if (a[i] <= a[j])  
            temp[k++] = a[i++];  
        else  
            temp[k++] = a[j++];  
    }  
      
    while (i <= m)  
        temp[k++] = a[i++];  
      
    while (j <= n)  
        temp[k++] = a[j++];  
      
    for (i = 0; i < k; i++)  
        a[first + i] = temp[i];  
}  
void mergesort(int a[], int first, int last, int temp[])  
{  
    if (first < last)  
    {  
        int mid = (first + last) / 2;  
        mergesort(a, first, mid, temp);    //左边有序  
        mergesort(a, mid + 1, last, temp); //右边有序  
        mergearray(a, first, mid, last, temp); //再将二个有序数列合并  
    }  
}  
  
#if 0
bool MergeSort(int a[], int n)
{  
    int *p = (int *)malloc(sizeof int);  
    if (p == NULL)  
        return false;  
    mergesort(a, 0, n - 1, p);  
    free(p); 

    return true;  
}  
#endif

void main()
{
    int arr[10]={6,1,4,55,2,7,2,7};
 //   MergeSort(arr,8);
    
    int *p = (int *)malloc(sizeof(int));  
    mergesort(arr, 0, 7, p);  
    printf("%d ",arr);
    free(p);
}


