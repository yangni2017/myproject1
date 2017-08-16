/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  test.cpp
 *    Description:  This file l
 *                 
 *        Version:  1.0.0(08/14/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/14/2017 10:36:43 AM"
 *                 
 ********************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    enum days{one, two, three}day;
    day = one;
    
    switch(day){
        case one:
            cout << "one" << endl;
            break;
        case two:
            cout << "two" << endl;
            break;
        default:
            cout << "three" << endl;
            break;
    }
    return 0;
}
