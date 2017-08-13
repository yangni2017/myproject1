/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  uart.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/13/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/13/2017 09:59:04 AM"
 *                 
 ********************************************************************************/

#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


/**************************************************************************************
 *  Description: 串口参数配置
 *  Input Args: fd:open打开的文件描述符 nspeed:波特率 nBits:数据位数 nEvent:奇偶校验 nStop:停止位
 *  Output Argtingzhis: 串口参数设置失败返回-1
 * Return Value:
 *************************************************************************************/
int set_opt(int fd,int nSpeed,int nBits,char nEvent,int nStop)
{
    struct termios newttys1,oldttys1;

    if(tcgetattr(fd,&oldttys1)!=0)         //保存原先串口配置
    {
        perror("Setupserial 1");
        return -1;
    }

bzero(&newttys1,sizeof(newttys1));       //将一段内存区域的内容全清为零
newttys1.c_cflag|=(CLOCAL|CREAD );       //CREAD 开启串行数据接收，CLOCAL并打开本地连接模式   

newttys1.c_cflag &=~CSIZE;              //设置数据位数
switch(nBits)     //选择数据位  
 {
        case 7:
                newttys1.c_cflag |=CS7;
                break;
        case 8:
                newttys1.c_cflag |=CS8;
                break;
 }
switch( nEvent )    //设置校验位  
 {
   case '0':       //奇校验  
           newttys1.c_cflag |= PARENB;             //开启奇偶校验  
           newttys1.c_iflag |= (INPCK | ISTRIP);   //INPCK打开输入奇偶校验；ISTRIP去除字符的第八个比特  
           newttys1.c_cflag |= PARODD;             //启用奇校验(默认为偶校验)  
           break;
  case 'E' :       //偶校验  
           newttys1.c_cflag |= PARENB;             //开启奇偶校验  
           newttys1.c_iflag |= ( INPCK | ISTRIP);  //打开输入奇偶校验并去除字符第八个比特  
           newttys1.c_cflag &= ~PARODD;            //启用偶校验；  
           break;
  case 'N':     //关闭奇偶校验
           newttys1.c_cflag &= ~PARENB;
           break;
   }

     switch( nSpeed )        //设置波特率  
     {
        case 2400:
                 cfsetispeed(&newttys1, B2400);           //设置输入速度
                 cfsetospeed(&newttys1, B2400);           //设置输出速度
                 break;
        case 4800:
                 cfsetispeed(&newttys1, B4800);
                 cfsetospeed(&newttys1, B4800);
                 break;
        case 9600:
                 cfsetispeed(&newttys1, B9600);
                 cfsetospeed(&newttys1, B9600);
                 break;
        case 115200:
                 cfsetispeed(&newttys1, B115200);
                 cfsetospeed(&newttys1, B115200);
                 break;
        default:
                 cfsetispeed(&newttys1, B9600);
                 cfsetospeed(&newttys1, B9600);
                 break;
     }

     if( nStop == 1)                      //设置停止位；若停止位为1，则清除CSTOPB，若停止位为2，则激活CSTOPB。  
     {
        newttys1.c_cflag &= ~CSTOPB;      //默认为送一位停止位；  
     }
     else if( nStop == 2)
     {
        newttys1.c_cflag |= CSTOPB;       //CSTOPB表示送两位停止位；  
     }

     //设置最少字符和等待时间，对于接收字符和等待时间没有特别的要求时
     newttys1.c_cc[VTIME] = 0;        //非规范模式读取时的超时时间；  
     newttys1.c_cc[VMIN]  = 0;        //非规范模式读取时的最小字符数；  

     tcflush(fd ,TCIFLUSH);           //tcflush清空终端未完成的输入/输出请求及数据；TCIFLUSH表示清空正收到的数据，且不读取出来 

     // 在完成配置后，需要激活配置使其生效
     if((tcsetattr( fd, TCSANOW,&newttys1))!=0) //TCSANOW不等数据传输完毕就立即改变属性  
     {
         perror("com set error");
         return -1;
     }
    return 0;
} /* ----- End of if()  ----- */
