/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  usetime.cpp
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(01/25/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "01/25/2017 01:31:32 PM"
 *                 
 ********************************************************************************/

#include <iostream>
#include "mytime.h"

int main()
{
   using std::cout;
   using std::endl;
   Time planning;
   Time coding(2,40);
   Time fixing(5,55);
   Time total;

   cout<< "planning time= ";
   planning.Show();
   cout<<endl;

   cout<<"coding time=";
   coding.Show();
   cout<<endl;

   cout <<"fixing time=";
   fixing.Show();
   cout<<endl;

   total=coding.Sum(fixing);
   cout<<"coding.Sum(fixing)=";
   total.Show();

   cout<<endl;

   return 0;


}

