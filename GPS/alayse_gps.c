/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  alayse_gps.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/13/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/13/2017 10:00:47 AM"
 *                 
 ********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "gps.h"
int gps_analysis(char *buff,GPRMC *gps_date)
{
    char *ptr=NULL;

    if(gps_date==NULL)
      return -1;

    if(strlen(buff)<10)
      return -1;

    if(NULL==(ptr=strstr(buff,"$GPRMC")))
     return -1;

    sscanf(ptr,"$GPRMC,%d.000,%c,%f,N,%f,E,%f,%f,%d,,,%c*",&(gps_date->time),&(gps_date->pos_state),&(gps_date->latitude),&(gps_date->longitude),&(gps_date->speed),&(gps_date->direction),&(gps_date->date),&(gps_date->mode));

   return 0;
} /* ----- End of if()  ----- */

float caculate(float *x)  //用于经纬度转换
{   
    int a;   
    float b,c,d,e,f;   
    a=*x/100;           //30   
    b=(int)((*x/100-a)*100);   //29   
    c=((*x/100-a)*100-b)*60;   
    d=b/60;       
    e=c/3600; 

    f=a+d+e;   
    return f;   
}


int print_gps(GPRMC *gps_date)
{

    float mylatitude,mylongitude;
    mylatitude = caculate(&gps_date->latitude);
    mylongitude = caculate(&gps_date->longitude);
    printf("                                                           \n");
    printf("                                                           \n");
    printf("===========================================================\n");
    printf("==                 全球定位系统                         ==\n");
    printf("==       作者：     杨泥                                ==\n");
    printf("==       邮箱:      497049229@qq.com                    ==\n");
    printf("==       开发平台： fl2440                              ==\n");
    printf("===========================================================\n");
    printf("                                                         \n");
    printf("                                                         \n");
    printf("===========================================================\n");
    printf("==                                                       \n");
    printf("==   GPS 状态   : %c  [A:有效         V:无效       ]      \n",gps_date->pos_state);
    printf("==   GPS 模式   : %c  [A:自主定位     D:差分定位   ]             \n", gps_date->mode);
    printf("==   日期 : 20%02d-%02d-%02d                             \n",gps_date->date%100,(gps_date->date%10000)/100,gps_date->date/10000);
    printf("==   当前时间: %02d:%02d:%02d                               \n",(gps_date->time/10000+8)%24,(gps_date->time%10000)/100,gps_date->time%100);
    printf("==   经度: %.9f  N                                    \n",mylatitude);
    printf("==   纬度：%.9f  E                                    \n",mylongitude);
    printf("==   速度: %.3f m/s                                         \n",gps_date->speed);
    printf("==                                                       \n");
    printf("===========================================================\n");
    return 0;

}  /* ----- End of print_gps()  ----- */

