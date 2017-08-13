/********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  gps.h
 *    Description:  This head file 
 *
 *        Version:  1.0.0(08/13/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/13/2017 10:02:46 AM"
 *                 
 ********************************************************************************/

#ifndef __GPS_H__
#define __GPS_H__

  typedef unsigned int UINT;
  typedef int BYTE;
  typedef long int WORD;

  typedef struct __gprmc__
  {
          UINT time;                  //格林威治时间
          char pos_state;             //定位状态
          float latitude;             //纬度
          float longitude;            //经度
          float speed;                //移动速度
          float direction;            //方向
          UINT date;                  //日期
          float declination;          //磁偏角
          char dd;                    //磁偏角方向
          char mode;
  }GPRMC;

  extern int gps_analysis(char *buff,GPRMC *gps_date);
  extern int print_gps(GPRMC *gps_date);
  extern int set_opt(int fd,int nSpeed, int nBits, char nEvent, int nStop);

  #endif
