/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  beer_test.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(04/19/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "04/19/2017 11:44:58 AM"
 *                 
 ********************************************************************************/

#include<stdint.h>

#include<string.h>

#include<fcntl.h>

#include<unistd.h>

#include<stdio.h>

#include<linux/input.h>

#include<unistd.h>

 

int main(int argc, char *argv[])

{

    int fd, version, ret;
    int i;

    struct input_event event;

 

if ((fd = open("/dev/event1", O_RDWR)) < 0) {

    perror("beep test");

    return 1;

}

              

    event.type = EV_SND;
    event.code = SND_TONE;
   
    if(!strcmp (argv[1],"1")) 
    {     
        for(i=0;i<=7;i++)
        {    
            event.value = 2000;
            ret = write(fd, &event, sizeof(struct input_event));
            sleep(0.5);
            event.value = 0;
            ret = write(fd, &event, sizeof(struct input_event));
        }
    }
   
    else if(!strcmp (argv[1],"0"))
    {
        
            event.value = 0;
            ret = write(fd, &event, sizeof(struct input_event));
    }

   close(fd);

       return 0;

}

 
