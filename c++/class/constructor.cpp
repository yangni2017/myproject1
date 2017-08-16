/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  constructor.cpp
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/14/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/14/2017 05:06:38 PM"
 *                 
 ********************************************************************************/

#include <iostream>
 
using namespace std;
 
class Line
{
   public:
      void setLength( double len );
      void setWidth( int width );
      double getLength( void );
      int getWidth( void );
      
      Line(double len,int wid);  // 构造函数
 
   private:
      double length;
      int width;
};
 
// 成员函数定义，包括构造函数
Line::Line( double len,int wid):length(len),width(wid)   //使用初始化列表对私有成员进行初始化
{
    cout << "Object is being created, length = " << len <<"\t"<<"width= "<<wid<< endl;
  //  length = len;
  //  width =wid;    
}
 
void Line::setLength( double len )
{
    length = len;
}
 
double Line::getLength( void )
{
    return length;
}
void Line::setWidth( int wid )
{
    width = wid;
}
 
int Line::getWidth(void)
{
    return width;
}
// 程序的主函数
int main( )
{
   Line line(10.0,2);
 
   // 获取默认设置的长度
   cout << "Length of line : " << line.getLength() <<endl;
   cout << "Length of line : " << line.getWidth() <<endl;
   // 再次设置长度
   line.setLength(6.0); 
   line.setWidth(3); 
   cout << "Length of line : " << line.getLength() <<endl;
   cout << "Length of line : " << line.getWidth() <<endl;
 
   return 0;
}
