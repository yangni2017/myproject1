/********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  linklist.h
 *    Description:  This head file 
 *
 *        Version:  1.0.0(07/30/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "07/30/2017 02:15:13 AM"
 *                 
 ********************************************************************************/

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


#if 0
void shownode(node *pNode)
{
    printf("\n打印：");
    while(pNode != NULL)
    {
        printf("%d,%d\n",pNode->num,pNode->data);
    }
    
    pNode=pNode->pNext;

}
#endif
