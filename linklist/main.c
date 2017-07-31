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
node *insert(node *pNode,int findnum,int newnum,datatype newdata);
node *inverted(node *pNode);

void link_sort(node *pNode);
void link_destory(node *pNode);

void main()
{
    node *pNode = NULL;
    backadd(&pNode,1,11);
    backadd(&pNode,3,12);
    backadd(&pNode,2,13);
    backadd(&pNode,5,14);
    backadd(&pNode,4,15);
    
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


//for Insert
  //  node *p=insert(pNode,1,7,17);

  //  insert(pNode,3,8,18);
  //  node *p2 = inverted(pNode);
  //  shownode(p2);
       
//for sort 
  //  link_sort(pNode);
    shownode(pNode);

    
    link_destory(pNode);

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
    node *p1,*p2;
    p1=p2=NULL;
    p1=pNode;
    
    printf("%p",pNode);
    while(p1 != NULL)
    {
        if(p1->num == findnum)
        {
            break;
        }
        else
        {
            p2=p1;  //Save the previous node 
            p1=p1->pNext;
            while(p1->pNext == NULL)
            {
                printf("you haven't insert a correct position!\n");
                return pNode;
            }
        }
    }

    node *pNewnode=(node *)malloc(sizeof(node));
    pNewnode->num=newnum;
    pNewnode->data=newdata;
    printf("%p",pNewnode);

    if(pNode == p1)  //insert it on the head
    {
        pNewnode->pNext = pNode;
        pNode=pNewnode; 
    }

    else
    {
        pNewnode->pNext=p1;
        p2->pNext=pNewnode;
    }
    
    return pNode;
}

//inverted sequence :逆序，改变地址，不改变数据

node *inverted(node *pNode)
{
    node *p1,*p2,*p3;
    p1=p2=p3=NULL;
    p1=pNode;
    if(pNode == NULL || pNode->pNext ==NULL)
    {
        return pNode;
    }
    else
    {
        p1=pNode;
        p2=pNode->pNext;
    }
    
    while(p2 != NULL)
    {
        p3 = p2->pNext;  
        p2->pNext=p1;
        p1=p2;
        p2=p3;
    }
    pNode->pNext = NULL;
    pNode=p1;
    return pNode;
}

//link_sort
void link_sort(node *pNode)
{
    node *p1;
    node *p2;
    node tmp_node={0};
    for(p1 = pNode;p1 != NULL;p1=p1->pNext)
    {
        for(p2 = pNode;p2 != NULL;p2=p2->pNext)
        {
            if(p1->num < p2->num)
            {
                tmp_node.num = p1->num;
                p1->num = p2->num;
                p2->num = tmp_node.num;                
            }
        }
    
    }

}



void link_destory(node *pNode)
{
    node *p1;
  //  p1=pNode;
    
    
    while( pNode != NULL)
    {
        p1=pNode->pNext;
        free(p1);
        pNode=p1;
    }
   // printf("");
    shownode(pNode);
    
}


