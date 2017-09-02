/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  test.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(09/02/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "09/02/2017 10:52:41 AM"
 *                 
 ********************************************************************************/

#include <stdio.h>
#include <string.h>
int main()
{
    char a[10] = "fabcdffgf";
    int i = 0;
    int j = 0;
    for (i = 0; i < strlen(a); i++)
    {
        if (a[i] != 'f')
        {
            a[j] = a[i];
            j++;
        }
    }
    a[j] = '\0';
    printf("%s",a);
    return 0;

}
