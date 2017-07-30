/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  main.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2017年07月30日)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "2017年07月30日 05时20分52秒"
 *                 
 ********************************************************************************/

#include <stdio.h>
#include <stdlib.h>  //for malloc
//#include "linklist.h" 
#define datatype int 

struct Node
{
    int num;
    datatype data;
    struct Node *pNext;
};
typedef struct Node node;

void shownode(node *pNode);
void backadd(node **pnode,int num,datatype data);
node *search(node *pNode,int num);
int change(node *pNode,int oldnum,int newnum,datatype data);
node *delete(node *pNode,int num);

void main()
{
    node *pNode = NULL;
    backadd(&pNode,1,11);
    backadd(&pNode,2,12);
    backadd(&pNode,3,13);
    backadd(&pNode,4,14);
    backadd(&pNode,5,15);
    
   // shownode(pNode);

//for change
/*
    int a=change(pNode,7,6,16);
    if(a == 1)
    {    
        shownode(pNode);
    }
*/

/*for find
 
    node *pFind= search(pNode,3);
    if(pFind == NULL)
    {
        printf("don't find it!");
    }
    else
    {
        printf("%d %d %p",pFind->num,pFind->data,pFind->pNext);
    }
*/

// for delete

    delete(pNode,2);
    shownode(pNode);
    

}


//printf the linklist
void shownode(node *pNode)
{
    printf("打印：\n");
    while(pNode != NULL)
    {
        printf("%d,%d\n",pNode->num,pNode->data);
        pNode=pNode->pNext;
    }
    
   // pNode=pNode->pNext;

}


//add on the back
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
        p->pNext = pNewnode;   //Insert        

    }
                
}


//search 

node *search(node *pNode,int num)
{
    node *p=pNode;
    for(;p!=NULL; p=p->pNext)
    {
        if(num == p->num)
        {
            return p;
            break;
        }
    }
    return NULL;
}

//modify

int change(node *pNode,int oldnum,int newnum,datatype newdata)
{
    while(pNode->pNext != NULL) 
    {
        if(pNode != NULL)
        {
            if(oldnum == pNode->num)
            {
                pNode->num=newnum;
                pNode->data=newdata;
                return 1;
            }
            pNode = pNode->pNext;
        }
    }
    
    printf("can't find the node,modify failed!");
    return 0;
}

//delete
node *delete(node *pNode,int num)
{
    node *p1 = NULL;
    node *p2 = NULL;
    
    p1=pNode;   //Save the infomation of the linklist

    while(p1 != NULL)
    {
        if(p1->num == num)
        {
            break;
        }
        else
        {
            p2=p1;  //Save the previous node 
            p1=p1->pNext;
        }
    }

    if(p1 == pNode) 
    {
        pNode=p1->pNext;
        free(p1);
    }

    else
    {
        p2->pNext=p1->pNext;  //ignore p1(delete it)
        free(p1);
    }
    
    return pNode;
}

node *insert(node *pNode,int findnum,int newnum,datatype newdata)
{

}





