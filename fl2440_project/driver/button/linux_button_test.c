#include <stdio.h>
#include<stdint.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<linux/input.h>
#include<unistd.h>


#include <stdlib.h>

#include <linux/input.h>

int main(void)

{

	int fd_button;
    int fd_led;

	struct input_event ev_key;

	fd_button= open("/dev/event0", 666);

	if(fd_button < 0)

    {

		perror("open device buttons");

		exit(1);

    }
    
while(1) 
{
	read(fd_button,&ev_key,sizeof(struct input_event));
    switch(ev_key.code)
    {
        case 116:
            fd_led = open("/sys/class/leds/led4/brightness", O_RDWR);
            write(fd_led,"1",1);
            sleep(1);
            write(fd_led,"0",1);
            break;
        case 63:
            fd_led = open("/sys/class/leds/led5/brightness", O_RDWR);
            write(fd_led,"1",1);
            sleep(1);
            write(fd_led,"0",1);
            break;
        case 59:
            fd_led = open("/sys/class/leds/led6/brightness", O_RDWR);
            write(fd_led,"1",1);
            sleep(1);
            write(fd_led,"0",1);
            break;
        case 60:
            fd_led = open("/sys/class/leds/led7/brightness", O_RDWR);
            write(fd_led,"1",1);
            sleep(1);
            write(fd_led,"0",1);
            break;
        default:
            break;    
        
    }

    if(fd_led<0)
    {        
        printf("can not open file.\n");        
        return -1;    
    }
}


 close(fd_button);
 close(fd_led);

 return 0;

}
