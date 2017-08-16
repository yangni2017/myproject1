/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  cp_constructor.cpp
 *    Description:  拷贝构造函数
 *                 
 *        Version:  1.0.0(08/14/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/14/2017 07:57:34 PM"
 *                 
 ********************************************************************************/

#include <iostream>  
using namespace std;  
  
class CExample {  
private:  
    int a;  
public:  
    //构造函数  
    CExample(int b)  
    { 
        a = b;
    }  
      
    //拷贝构造函数  
    CExample(const CExample& C)  
    {  
        a = C.a;  
    }  
  
    //一般函数  
    void Show ()  
    {  
        cout<<a<<endl;  
    }  
};  
  
int main()  
{  
    CExample A(100);  
    CExample B = A; // CExample B(A); 也是一样的  
    B.Show ();  
    return 0;  
}   
