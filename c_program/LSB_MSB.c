/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  test.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/11/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/11/2017 01:33:45 PM"
 *                 
 ********************************************************************************/
#include <stdio.h>
void main()
{
     
    unsigned int a = 0x12345678;
    unsigned char i = (unsigned char)a;
    
    if (i == 0x12)
    {
        printf("MSB");
    }
    else
    {
        printf("LSB");
    }
    
/* 
    union
    {
        char             c;
        unsigned short   s;    
    }A;

    A.s = 0x1234;
    if(A.c == 0x12)
    {
        printf("It's MSB");    // 1  0x34
                               // 0  0x12
    }
    else
    {
        printf("It's LSB");    // 1  0x12
                               // 0  0x34
    }
*/    
}

