/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  mybutton.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(04/17/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "04/17/2017 03:52:48 PM"
 *                 
 ********************************************************************************/
#include <stdio.h>  
#include"plat_ioctl.h"

#include <errno.h>   //for perror()

//for select()
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>

//for open()
#include <sys/stat.h>
#include <fcntl.h>

#define PLATDRV_MAGIC               0x60
#define LED_OFF                     _IO (PLATDRV_MAGIC, 0x18)
#define LED_ON                      _IO (PLATDRV_MAGIC, 0x19)
#define LED_BLINK                   _IO (PLATDRV_MAGIC, 0x1A)

#define KEY1  0x1   
#define KEY2  0x2   
#define KEY3  0x4   
#define KEY4  0x8 

int main(int argc,char **argv)
{
    int fd_button,led_fd;
    int retval;
    int status_button;
    fd_set rfds;
    
    fd_button=open("dev/button",O_RDWR);
    if (fd_button<0)
    {
        perror("open failed!\n");
    }
    
    led_fd=open("dev/led",O_RDWR);
    if (led_fd<0)
    {
        perror("open failed!\n");
    }


    FD_ZERO(&rfds);
    FD_SET(fd_button,&rfds);
    
    while(1)
    {
        retval =select(fd_button+1,&rfds,NULL,NULL,NULL);
        if(retval<0)
        {
            perror("failed!\n");
            break;
        }

        else if(0 == retval)
        {
            printf("timeout!\n");
            continue;
        }
        
        else if(FD_ISSET(fd_button,&rfds)) 
        {
            read(fd_button, &status_button,sizeof(status_button));
        }

        
        if (status_button == KEY1)
        {
            static int i=1;
            switch(i%3)
            {
                case 1:   
                    ioctl(led_fd,LED_ON,0);
                    sleep(2);
                    i++;break;  
                case 2:   
                    ioctl(led_fd,LED_BLINK,0);  
                    i++;break;  
                case 0:   
                    ioctl(led_fd,LED_OFF,0);  
                    i++;break;    
            }
        
        }
        
        if (status_button == KEY2)
        {  
            static int j=1;
            switch(j%3)
            {
                case 1:
                    ioctl(led_fd,LED_ON,1);
                    sleep(2);
                    j++;break;
                case 2:
                    ioctl(led_fd,LED_BLINK,1);
                    j++;break;
                case 0:
                    ioctl(led_fd,LED_OFF,1);
                    j++;break;
             }
         
        }
        
        if (status_button == KEY3)
        {  
         static  int k=1;
            switch(k%3)
            {
                case 1:
                    ioctl(led_fd,LED_ON,2);
                    k++;break;
                case 2:
                    ioctl(led_fd,LED_BLINK,2);
                    k++;break;
                case 0:
                    ioctl(led_fd,LED_OFF,2);
                    k++;break;
            }
          
        }        
 
        if (status_button == KEY4)
        {  
          static int n=1;
            switch(n%3)
            {
                case 1:
                    ioctl(led_fd,LED_ON,3);
                    n++;break;
                case 2:
                    ioctl(led_fd,LED_BLINK,3);
                    n++;break;
                case 0:
                    ioctl(led_fd,LED_OFF,3);
                    n++;break;
            }
         
        }

    }

    close(fd_button);
    close(led_fd);
    return 0;
}
