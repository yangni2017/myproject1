/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  test_led.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(03/24/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "03/24/2017 06:49:47 PM"
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
    int fd;


    fd = open("/dev/led", 0);
    if (fd < 0) {
        fd = open("/dev/led", 0);
    }
    if (fd < 0) {
        perror("open device led");
        exit(1);
    }
  while(1)
  {  
    ioctl(fd, LED_ON, 0);
    sleep(1);
    ioctl(fd, LED_OFF, 0);
  }
    close(fd);
    return 0;
}
