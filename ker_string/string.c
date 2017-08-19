/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  string.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/19/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/19/2017 01:18:47 PM"
 *                 
 ********************************************************************************/
#include <stdio.h>

size_t mystrlen(const char * s)
{
    const char *sc; 
    for (sc = s; *sc != '\0'; ++sc)
         /*  nothing */;
         return sc - s;
}

char *mystrcpy (char *dest,char *src)
{
    char *temp = dest;

    while( (*dest++ = *src++) != '\0' )
           ;    
    return temp;
}

char *mystrncpy (char *dest,char *src,size_t count)
{
    char *temp = dest;
    while ( count-- && (*dest++ = *src++) != '\0')
    {
        ;
    }
    return temp;
}

char *mystrcat (char *dest,char *src)
{
    char *temp = dest;
    while (*dest)
    {
        dest++;
    }
        
    while ((*dest++ = *src++) != '\0')
    {
        ;
    }
    return temp;
}

int mystrcmp(const char * cs,const char * ct)
{
     register signed char __res; //定义在寄存器中的变量，CPU不必访问内存，能很快的读取
 
     while (1) {
         if ((__res = *cs - *ct++) != 0 || !*cs++)
             break;
     }
 
     return __res;
}


int main()
{
    char arr[10]="abcde";
    char a[4]="ach";
    char b[10];

    printf("%d\n",mystrlen(arr));
   //test for strcpy
   // mystrcpy(b,arr);
   // printf("%s\n",b);
    
    //test for strncpy
  // mystrncpy(b,arr,3);
  // printf("%s\n",b);

  // mystrcat(arr,a);
  // printf("%s\n",arr);
    
   printf("%d\n",mystrcmp(a,arr));
}
