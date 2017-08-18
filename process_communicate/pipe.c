/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  pipe.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/18/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/18/2017 01:18:28 PM"
 *                 
 ********************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <string.h>
int main()
{
    int fd[2];
    pid_t pid;
    char buf[64] = "i'm parent process!!\n";   //父进程要写入管道的内容
    char line[64];

    if (0 != pipe(fd))    //创建管道
    {
        fprintf(stderr,"Fail to create pipe!");
        return 0;      
    }

    pid = fork();
    if (pid < 0)
    {
        printf("fork failed!");
        return 0 ;
    }
    
    else if(0 == pid)   
    {
        close(fd[0]);   //关闭读管道，使父进程只能写
        write(fd[1],buf,strlen(buf));
        close(fd[1]);   //关闭写管道
    }
    
    else
    {
        close(fd[1]);   //关闭写管道
        read(fd[0],line,64);    //只能读
        printf("DATA From Parents:%s",line);
        close(fd[0]);
    }
    return 0;

}
