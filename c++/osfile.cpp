/*********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  osfile.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/14/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "08/14/2017 02:49:15 PM"
 *                 
 ********************************************************************************/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    char data[100];
    ofstream outfile;   //只写方式打开
    outfile.open("test",ios::out | ios::trunc);  //文件不存在，创建文件并写入
    cout << "Writing to the file" <<endl;
    cout << "Enter your name:";

    cin.getline(data,100);     //向data中写入数据 
    outfile << data << endl;   //把数据写入流
    cout << "please input your age:";
    cin >> data;
    cin.ignore();  //忽略掉之前读语句留下的多余字符

    outfile << data  <<endl;
    outfile.close();

//read
    ifstream infile;   //以读的方式打开
    infile.open("test");

    cout << "Reading from the file"<<endl;
    infile >> data;    //把数据传入data(一次只读一行)
    cout << data <<endl;
 
    infile >>data;
    cout << data <<endl;

    infile.close();
}


