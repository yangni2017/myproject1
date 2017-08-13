/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  mytest.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(03/24/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "03/24/2017 09:41:35 PM"
 *                 
 ********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>


#include <asm/ioctl.h>      /*  Linux kernel space head file for macro _IO() to generate ioctl command  */
#ifndef __KERNEL__
#include <sys/ioctl.h>      /*  User space head file for macro _IO() to generate ioctl command */
#endif


#define PLATDRV_MAGIC             0x60
#define LED_OFF                   _IO (PLATDRV_MAGIC, 0x18)
#define LED_ON                    _IO (PLATDRV_MAGIC, 0x19)


int main(int argc, char **argv)
{
    int on;
    int led_no;
    int fd1,fd2,fd3,fd4;

while(1)
{ 
    fd1 = open("/dev/led0", 0);
    if (fd1 < 0) {
        perror("open device failed");
        exit(1);
    }
    ioctl(fd1, LED_ON, 0);
    sleep(1);
    ioctl(fd1, LED_OFF, 0);
    

    fd2 = open("/dev/led1", 1);
    if (fd2 < 0) {
        perror("open device failed");
        exit(1);
    }
    ioctl(fd2, LED_ON, 1);
    sleep(1);
    ioctl(fd2, LED_OFF, 1);
 


    fd3 = open("/dev/led2", 2);
    if (fd3 < 0) {
        perror("open device failed");
        exit(1);
    }
    ioctl(fd3, LED_ON, 2);
    sleep(1);
    ioctl(fd3, LED_OFF, 2);
    

    fd4 = open("/dev/led3", 3);
    if (fd4 < 0) {
        perror("open device failed");
        exit(1);
    }
    ioctl(fd4, LED_ON, 3);
    sleep(1);
    ioctl(fd4, LED_OFF, 3);
    
    
   
    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);
}
    return 0;

}
