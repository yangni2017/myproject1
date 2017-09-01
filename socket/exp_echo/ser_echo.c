/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  ser_echo.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(09/01/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "09/01/2017 10:34:12 AM"
 *                 
 ********************************************************************************/

#include <stdio.h>

#include <sys/types.h>    /*for socket */
#include <sys/socket.h>

#include <netinet/in.h>   //sockaddr_in
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define EHCO_PORT 8080
#define MAX_CLIENT_NUM  10

int main()
{
    int sock_fd;        
    struct sockaddr_in serv_addr;   //定义服务器指向服务器的结构体
    int clientfd;
    struct sockaddr_in clientAdd;
    char buff[101];
    socklen_t len;       //socklen_t和int具有相同长度（类似int）
    int n;

    sock_fd = socket(AF_INET,SOCK_STREAM,0); //IPV4,面向连接、字节流
    if ( sock_fd == -1)
    {
        perror("create socket error!");
        return 0;
    }
    else
    {
        printf("Sucess to create socket %d\n",sock_fd);
    }
    
    bzero(&serv_addr,sizeof(serv_addr));   //初始化结构体
    serv_addr.sin_family = AF_INET;        //设置传输层类型
    serv_addr.sin_port = htons(EHCO_PORT);  //host to net short  ：主机字节序（小端）转换为网络字节序（大端）
    serv_addr.sin_addr.s_addr = htons (INADDR_ANY);  //INADDR_ANY表示所以ip,也就是服务器要监听所有IP地址
    bzero(&(serv_addr.sin_zero),0);  //让sockaddr与sockaddr_in两个数据结构保持大小相同(16字节)而保留的空字节

    //把地址和套接字绑定
    if ( bind(sock_fd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) != 0) 
    {
        perror("bind address failed!\n");
        close(sock_fd);
        return 0;
    }
    
    //设置套接字监听
    if (listen(sock_fd,MAX_CLIENT_NUM) != 0)
    {
        perror("listen socket failed\n");
        close(sock_fd);
        return 0;
    }
    
    //创建新连接对应的套接字
    len = sizeof(clientAdd);
    clientfd = accept (sock_fd, (struct sockaddr *)&clientAdd,&len);
    if (clientfd <= 0)
    {
        perror("accept error!\n");
        close(sock_fd);
        return 0;
    }

    //接收用户发来的数据
    while ( (n = recv(clientfd,buff,100,0)) > 0)
    {
        buff[n] ='\0';     //给字符串添加结束符
        printf("number of receive bytes = %d data = %s \n",n,buff);

        fflush(stdout);   //刷新标准输出缓冲区，把输出缓冲区里的东西打印到标准输出设备上
        send(clientfd,buff,n,0);        //发送字符串内容给客户端
        if (strncmp(buff,"quit",4) == 0)
        {
            break;
        }
    }
    
    close(clientfd);
    close(sock_fd);
    return 0;
}
