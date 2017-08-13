/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  led.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(04/30/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "04/30/2017 11:44:03 AM"
 *                 
 ********************************************************************************/

#include <stdio.h>  
#include<stdint.h>  
#include<string.h>  
#include<fcntl.h>  
#include<unistd.h>  
#include<linux/input.h>  
#include<unistd.h>  
  
  
#include <stdlib.h>  
  
#include <linux/input.h>  
  
#define EV_PRESS     1
#define EV_RELEASE   0
int main(void)  
  
{  
    char buf[50]; 
    int fd_button;  
    int fd_led[4];  
    int i;

    struct input_event ev_key;  
  
    fd_button= open("/dev/event0", 666);  
  
    if(fd_button < 0)  
  
    {  
  
        perror("open device buttons");  
  
        exit(1);  
  
    }  
      
    for(i=1;i<=4;i++)
        {
            snprintf((char *)buf,sizeof(buf),"/sys/class/leds/led%d/brightness",i);
            fd_led[i] = open(buf, O_RDWR);
            if(fd_led[i]<0)
            {
                printf("can't open the file led%d",i);
                return -1;
            }
        } 
    
    while(1)
    {
        read(fd_button,&ev_key,sizeof(struct input_event));
        if(EV_KEY==ev_key.type && EV_PRESS==ev_key.value)
        {
            switch(ev_key.code)    //通过对code传值来确定是哪个按键  
            {   static int i=0;
                case KEY_1:
                    if(i%2==0)
                    {   
                        write(fd_led[1],"1",1);  
                        i++;
                    }
                    else
                    {
                        write(fd_led[1],"0",1);
                        i++;
                    } 
                    break;  
                case KEY_2:  
                    write(fd_led[2],"1",1);  
                    sleep(1);  
                    write(fd_led[2],"0",1);  
                    break;  
                case KEY_3:  
                    write(fd_led[3],"1",1);  
                    sleep(1);  
                    write(fd_led[3],"0",1);  
                    break;  
                case KEY_4:  
                    write(fd_led[4],"1",1);  
                    sleep(1);  
                    write(fd_led[4],"0",1);  
                    break;  
                default:  
                    break;      
          
            }  
        }
        else if(EV_KEY==ev_key.type && EV_RELEASE==ev_key.value)
        {
            printf("relase the key!\n");
        }
        
    }    
        
        for(i=1;i<=4;i++)
        {
            close(fd_led[i]);
        }
    
  
    close(fd_button);  
    return 0;  
  
}  
