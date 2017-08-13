/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  gps_main.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/13/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/13/2017 10:02:11 AM"
 *                 
 ********************************************************************************/
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

#include "gps.h"
//#include "gps_uart.h"
#define GPS_LEN 512 

int gps_analysis(char *buff,GPRMC *gps_date);
int print_gps(GPRMC *gps_date);
int set_opt(int fd,int nSpeed, int nBits, char nEvent, int nStop);


/********************************************************************************
 *  Description:   main():程序执行的入口
 *   Input Args:    
 *  Output Args:
 * Return Value:
 ********************************************************************************/
int main (int argc, char **argv)
{
     int fd = 0;
     int nread = 0;

     GPRMC gprmc;

     char gps_buff[GPS_LEN];
     char *dev_name = "/dev/ttyUSB0";

     fd=open(dev_name,O_RDWR|O_NOCTTY|O_NDELAY);
     if(fd<0)
     {
         printf("open ttyS1 error!!\n");
         return -1;
     }

     set_opt( fd,9600,8,'N',1); //设置串口信息

     while(1)
     {
         sleep(2);
         nread = read(fd,gps_buff,sizeof(gps_buff));
         if(nread<0)
         {
             printf("read GPS date error!!\n");
             return -2;
         }
         printf("gps_buff: %s\n", gps_buff);

         memset(&gprmc, 0 , sizeof(gprmc));
         gps_analysis(gps_buff,&gprmc);

         print_gps(&gprmc);
     }


    close(fd);
    return 0;
} /* ----- End of main() ----- */

