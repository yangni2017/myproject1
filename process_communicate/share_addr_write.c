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
#include <string.h>

int main()
{
    int shmid;
    char *ptr;
    char *shm_str = "string in 0X90";

    shmid = shmget(0x90,1024,SHM_W|IPC_CREAT|SHM_R|IPC_EXCL);  //创建共享内存

    if (-1 == shmid)
    {
        perror("create share memory failed!");
    }

    ptr = (char *)shmat(shmid,0,0);   //通过共享内存ID获取共享地址内存

    if ((void *) -1 == ptr)
        perror("get share memory");
    strcpy(ptr,shm_str);
    shmdt(ptr);
    return 0;
}
