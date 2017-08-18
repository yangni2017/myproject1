/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  share_addr.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/18/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/18/2017 02:04:09 PM"
 *                 
 ********************************************************************************/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int shmid;
    char *ptr;

    shmid = shmget(0x90,1024,SHM_W|SHM_R|IPC_EXCL);  //创建共享内存

    if (-1 == shmid)
    {
        perror("create share memory!");
    }

    ptr = (char *)shmat(shmid,0,0);   //通过共享内存ID获取共享地址内存

    if ((void*) -1 == ptr)
        perror("get share memory failed");
    
    printf("string int share memeory : %s\n",ptr);
    shmdt(ptr);
    return 0;
}
