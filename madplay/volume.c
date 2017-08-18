/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  volume.c
 *    Description:  控制音量函数
 *                 
 *        Version:  1.0.0(08/18/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/18/2017 04:55:02 PM"
 *                 
 ********************************************************************************/

void volume(int voice)  
{  
    int MIX_FD;             //定义文件描述符  
    int iLeft = voice;      //左声道增益  
    int iRight = voice;     //右声道增益  
    int iLevel;  
    iLevel = (iRight << 8) + iLeft;   //  
  
    MIX_FD= open("/dev/mixer", O_WRONLY);   //只写方式打开混音器  
    if (MIX_FD == -1) {  
        perror("Error:open /dev/mixer error");  
        exit(1);  
    }  
      
    /*设置混音通道增益*/  
    if (ioctl(MIX_FD, MIXER_WRITE(SOUND_MIXER_VOLUME), &iLevel) == -1) {    
        perror("Error:MIXER_WRITE ioctl failed");  
        exit(1);  
    }  
      
    /*读取混音通道增益*/  
    if (ioctl(MIX_FD, MIXER_READ(SOUND_MIXER_VOLUME), &iLevel) == -1) {     
        perror("Error:MIXER_WRITE ioctl failed");  
        exit(1);  
    }   
    close(MIX_FD);  
}  
