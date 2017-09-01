/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  cli_echo.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(09/01/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "09/01/2017 12:48:43 PM"
 *                 
 ********************************************************************************/

#include <stdio.h>
#include <sys/types.h>    /* for socket */
#include <sys/socket.h>
     
#include <netinet/in.h>   //sockaddr_in
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define ECHO_PORT 8080
#define MAX_COMMAND 5

int main()
{
    int sock_fd;
    struct sockaddr_in serv_addr;
    char *buff[MAX_COMMAND] = {"abc","def","test","hello","quit"};
    char tmp_buf[100];
    int n,i;

    //创建socket
    sock_fd = socket(AF_INET,SOCK_STREAM,0);
    if (sock_fd == -1)
    {
        perror("create socket error!\n");
        return 0;
    }
    else 
    {
        printf("Success to create %d\n",sock_fd);
    }

    //设置server地址结构
    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port =htons(ECHO_PORT);
    serv_addr.sin_addr.s_addr = htons(INADDR_ANY);
    bzero(&(serv_addr.sin_zero),8);

    if (-1 == connect(sock_fd, (struct sockaddr *)&serv_addr,sizeof(serv_addr)))
    {
        perror("connect failed!");
        close(sock_fd);
        return 0;
    }
    printf("Success connect to server!\n");

    for (i = 0;i < MAX_COMMAND;i++)
    {
        send(sock_fd,buff[i],100,0);           //发数据给服务器
        n = recv(sock_fd,tmp_buf,100,0);       //接收数据
        tmp_buf[n] = '\0';
        printf("data send :%s receive : %s\n",buff[i],tmp_buf);
        
        if (0 == strncmp(tmp_buf,"quit",4))
        {
            break;
        }
    }
    close(sock_fd);
    return 0;

}
