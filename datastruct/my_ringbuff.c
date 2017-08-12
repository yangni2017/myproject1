/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  my_ringbuff.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/11/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/11/2017 06:45:06 PM"
 *                 
 ********************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ring_buff
{
    u_char *buff;
    int wr_pointer;
    int rd_pointer;
    int size;
};
typedef struct ring_buff Ringbuff;

int rb_data_size (Ringbuff *rb)
{
    return ( (rb->wr_pointer - rb->rd_pointer) & (rb->size -1));
}

int rb_free_size (Ringbuff *rb)
{
    return ( rb->size - 1 - rb_data_size(rb));
}

void rb_init (Ringbuff *rb,u_char *buf,int size)
{
   memset(rb,0,sizeof(Ringbuff)); 
   rb->rd_pointer = 0;
   rb->wr_pointer = 0;
   rb->buff = buf;
   rb->size = size;
}

void clear (Ringbuff *rb)
{
    memset(rb->buff,0,rb->size);
    rb->rd_pointer = 0;
    rb->wr_pointer = 0;
}

int rb_write (Ringbuff *rb, u_char *buf, int len)
{
    int rb_freesize = rb_free_size(rb);
    int pos = 0;

    if (len > rb_freesize)
    {
        len = rb_freesize;
    }
    else
    {
        rb_freesize = len;
    }

    pos = rb->wr_pointer;

    if (pos + len > rb->size)
    {
        memcpy(rb->buff + pos, buf, rb->size - pos);
        buf += rb->size-pos;
        len -= rb->size-pos;
        pos = 0;
    }
    
    memcpy(rb->buff + pos,buf,len);
    rb->wr_pointer = pos + len;
    return rb_freesize;
}

int rb_read (Ringbuff *rb, u_char * buf, int max)
{
    int datasize=rb_data_size(rb);
    int pos = 0;
    
    if (max > datasize)
    {
        max = datasize;
    }
    else 
    {
        datasize = max;
    }
    
    pos = rb->rd_pointer;

    if (pos + max > rb->size)
    {
        memcpy(buf,rb->buff + pos,rb->size - pos);
        buf +=rb->size;
        max -=rb->size;
        pos = 0;
    }
    
    memcpy(buf,rb->buff + pos,max);
    rb->rd_pointer = pos + max;
    
    return datasize;
}

int main()
{
    Ringbuff *ring=(Ringbuff *)malloc(sizeof(Ringbuff));
    u_char a[20]="abcdefghijklmno";
    u_char buff[8]={0};
    u_char mybuff[12]={0};
    
    rb_init (ring, buff, sizeof(buff));   //8

    int w_res=0,r_res=0;
    int i=0;
       
    w_res = rb_write (ring, a, 4);
    printf("写指针所在位置：%d\n",ring->wr_pointer); 
    
    printf("当前空余空间：%d\n",rb_free_size(ring));
    printf("当前数据所占空间：%d\n",rb_data_size(ring));
    r_res = rb_read (ring, mybuff, 3);
   
    printf("---------------------------\n");
    w_res = rb_write (ring, &a[4], 6);
    printf("写指针所在位置：%d\n",ring->wr_pointer); 
    printf("写读指针所在位置:%d\n",ring->rd_pointer); 

    printf("当前空余空间：%d\n",rb_free_size(ring));
    printf("当前数据所占空间：%d\n",rb_data_size(ring));
    
    // printf("%d\n",ring->wr_pointer);    
    r_res = rb_read (ring, &mybuff[3], 2);
    
    
   // printf("%d \t %d\n",w_res,r_res);
    printf("%s\n",mybuff);
    
    return 0; 

}





