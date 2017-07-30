/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  backadd.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(07/30/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "07/30/2017 03:24:58 AM"
 *                 
 ********************************************************************************/

#include <stdio.h>
#include <stdlib.h>   //for malloc
#include "linklist.h"

void backadd(node **ppnode,int num, datatype data)
{
    node *pNewnode = (node *)malloc (sizeof(node));

    //creat a  new node
    pNewnode->num =num;
    pNewnode->data=data;

    if(*ppnode == NULL)     //linklist is empty
    {
        *ppnode = pNewnode;    //
        pNewnode->pNext = NULL;
    }
    

    else
    {
        node *p = *ppnode;    //head 
        
        while(p->pNext != NULL)
        {
            p=p->pNext;
        }

        p=p->pNext = pNewnode;   //Insert        
    }
                
}
