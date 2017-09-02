/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  abc.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/29/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/29/2017 08:25:38 PM"
 *                 
 ********************************************************************************/

#include <stdio.h>
#include <string.h>
void func(char *str,char s)
{
    char *p = str;
    char *temp=NULL;
    while ( *p != '\0' )
    {
        if (*p == s)
        {
            temp = p;
            while (*p != '\0' )
            {
                *p = *(p+1);
                p++;
            }
            p = temp-1;
        }
       
        p++;
    } 

}

int main()
{
    char a[10] = "fafffffgf";
    func(a,'a');
    printf("%s",a);
    return 0;

}






