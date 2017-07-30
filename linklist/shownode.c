/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  shownode.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2017年07月30日)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "2017年07月30日 05时28分33秒"
 *                 
 ********************************************************************************/
#include <stdio.h>
#include "linklist.h"

void shownode(node *pNode)
{
    printf("\n打印：");
    while(pNode != NULL)
    {
        printf("%d,%d\n",pNode->num,pNode->data);
    }
    
    pNode=pNode->pNext;

}
