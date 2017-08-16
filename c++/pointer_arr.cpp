/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  pointer_arr.cpp
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/14/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/14/2017 09:35:43 AM"
 *                 
 ********************************************************************************/

#include <iostream>
class A
{
    public:
        int func(int p){};
    private:
        int m;
};

int func(int p)
{
    using namespace std;
    A::m=p;
    cout<<m<<endl;
}

int main()
{
    using namespace std;
   // int m;
    A a;
    func(3);
    cout<<a.m<<endl;
    
    return 0;
}
