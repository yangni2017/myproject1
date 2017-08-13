/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  str1.cpp
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(06/18/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "06/18/2017 11:06:59 PM"
 *                 
 ********************************************************************************/
#include <iostream>
#include <string>

int main()

{
    using namespace std;
    string one("Lottery Winner!");
    cout << one << endl;

    string two(20,'$');
    cout<< two << endl;

    string three(one);
    cout<< three <<endl;

    one+="Opps";
    cout<<one<<endl;

    two = "sorry";
    three[0] ='P';

    string four;
    four=two + three;

    cout << four <<endl;

    char alls[]="All's well that ends well";
    string five(alls,20);
    cout<<five<<"!\n";

    string six(alls+6,alls+10);
    cout<<six<<",";
    string seven(&five[6],&five[10]);
    cout<<seven<<"....\n";
    string eight(four,7,16);
    cout<< eight <<"int motion"<<endl;
    return 0;

}

