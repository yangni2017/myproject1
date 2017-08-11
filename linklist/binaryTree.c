/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  binary.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/04/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/04/2017 09:45:49 PM"
 *                 
 ********************************************************************************/

#include <stdio.h>
#include <stdlib.h>  //for malloc 
typedef struct BTree
{
    char data;
    struct BTree *lChild;
    struct BTree *rChild;
}BinTree;

BinTree *CreateTree(BinTree *p)
{
    char ch;
    scanf("%c",&ch);
    if (ch == '#')  //# standard for the leaf node
    {
        return NULL;   
    }

    p=(BinTree *)malloc(sizeof(BinTree));
    p->data = ch;
    p->lChild = CreateTree(p->lChild);
    p->rChild = CreateTree(p->rChild);
    
    return p;
}

#if 1
void DestoryTree(BinTree *B)
{
    //printf("0");
    if(B == NULL)
    {
        return;
    }    
    
   // printf("%p",B->lChild);
    DestoryTree(B->lChild);
   // printf("2");
    DestoryTree(B->rChild);
   // printf("3");
    free(B);
    B=NULL;
}
#endif

int Sumleaf(BinTree *T)
{
    int sum=0,m,n;
    if (T)
    {
        if ((!T->lChild) && (!T->rChild))
        {
            sum++;
        }
        m=Sumleaf(T->lChild);
        sum+=m;
        n=Sumleaf(T->rChild);
        sum+=n;
    }
    return sum;
}

int Depth(BinTree *T)
{
    int dep=0,dep1,depr;
    if (!T)
    {
        dep=0;
    }
    else
    {
        dep1=Depth(T->lChild);
        depr=Depth(T->rChild);
        dep=1+(dep1>depr ? dep1:depr);
    }
    return dep;
}

void PreOrder(BinTree *T)
{
    if(T)
    {
        printf("%c",T->data);
        PreOrder(T->lChild);
        PreOrder(T->rChild);
    }
}

void MidOrder(BinTree *T)
{
    if (T)
    {
        MidOrder(T->lChild);
        printf("%c",T->data);
        MidOrder(T->rChild);
    }
}

void LastOrder(BinTree *T)
{
    if(T)
    {
        LastOrder(T->lChild);
        LastOrder(T->rChild);
        printf("%c",T->data);
    }
}

void Copy(BinTree *T,BinTree **newTree) 
{
    if(T == NULL)
    {
        *newTree = NULL;
        return ;
    }

    else
    {
        *newTree = (BinTree *)malloc(sizeof(BinTree));
        (*newTree)->data=T->data;
        Copy(T->lChild,&(*newTree)->lChild);
        Copy(T->rChild,&(*newTree)->rChild);
    }
}

int main()
{
    BinTree *Tree;
    BinTree *newtree;
    printf("请以前序遍历的方式输入扩展二叉树，用“#”表示空结点：\n");
    Tree=CreateTree(Tree);
    
    printf("前序遍历:\n");
    PreOrder(Tree);

    printf("\n中序遍历:\n");
    MidOrder(Tree);
    
    printf("\n后序遍历:\n");
    LastOrder(Tree);

    printf("\n叶结点总数：%d\n",Sumleaf(Tree));
    printf("\n树的层数：%d\n",Depth(Tree));
    
    Copy(Tree,&newtree);
    
    printf("\n复制树后序遍历:\n");
    LastOrder(newtree);
    printf("\n");
   // LastOrder(mytree);
    printf("%p\n",Tree);    
    
    DestoryTree(Tree);
    
    //printf("%p",Tree);
    LastOrder(Tree);
    return 0;
}




