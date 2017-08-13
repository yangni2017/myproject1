/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  button_test.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(04/12/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "04/12/2017 03:59:49 AM"
 *                 
 ********************************************************************************/
#include"plat_ioctl.h"
#include<stdio.h>
#include<stdlib.h> 
#include<fcntl.h>
#include<unistd.h>
#include<sys/ioctl.h> 
#include<sys/time.h>
#include<errno.h>

#define PLATDRV_MAGIC             0x60
#define LED_OFF                   _IO (PLATDRV_MAGIC, 0x18)
#define LED_ON                    _IO (PLATDRV_MAGIC, 0x19)

#define KEY1 0x1
#define KEY2 0x2
#define KEY3 0x4
#define KEY4 0x8


/********************************************************************************
 *  Description:
 *   Input Args:
 *  Output Args:
 * Return Value:
 ********************************************************************************/
int main (int argc, char **argv)
{
    int fd_button;
    int fd_led;

    int status;
    int retval;
    fd_set rfds;

    fd_button =open("/dev/button",O_RDWR);
    if(fd_button <0)
        goto err1;
    fd_led =open("/dev/led",O_RDWR);
    if(fd_led <0)
        goto err2;

    FD_ZERO(&rfds);
    FD_SET(fd_button,&rfds);

    for(;;)
    {
        retval =select(fd_button+1,&rfds,NULL,NULL,NULL);

        if(retval <0)
        {
            printf("error!%s\n",strerror(errno));
            break;
        }
        else if(retval ==0)
            continue;
        else
        {
            if(FD_ISSET(fd_button,&rfds) >0)
            {
                read(fd_button, &status, sizeof(status));
            }
        }

        if(status &KEY1)
        {
            ioctl(fd_led, LED_ON, 0);
            printf("led0 on\n");
            sleep(2);
            ioctl(fd_led, LED_OFF, 0);
        }

        if(status &KEY2)
        {
            ioctl(fd_led, LED_ON, 1);
            printf("led1 on\n");
            sleep(2);
            ioctl(fd_led, LED_OFF, 1);
        }

        if(status &KEY3)
        {
            ioctl(fd_led, LED_ON, 2);
            printf("led2 on\n");
            sleep(2);
            ioctl(fd_led, LED_OFF, 2);
        }
        if(status &KEY4)
        {
            ioctl(fd_led, LED_ON, 3);
            printf("led3 on\n");
            sleep(2);
            ioctl(fd_led, LED_OFF, 3);
        }

    }
    close(fd_button);
    close(fd_led);
err1:
    perror("open device buttons error!");
    close(fd_button);
err2:
    perror("open device leds error!");
    close(fd_led); 

    return 0;
} /* ----- End of main() ----- */
