/********************************************************************************
 *      Copyright:  (C) 2017 qicheng
 *                  All rights reserved.
 *
 *       Filename:  brass.h
 *    Description:  This head file 
 *
 *        Version:  1.0.0(04/05/2017)
 *         Author:  yangni <497049229@qq.com>
 *      ChangeLog:  1, Release initial version on "04/05/2017 05:50:06 AM"
 *                 
 ********************************************************************************/

#ifdef BRASS_H_
#define BRASS_H_
#include <string>
class brass
{
private:
    std::string fullname;
    long acctNum;
    double balance;
public:
    Brass (const std::string & s ="Nullbody",long an =-1,double bal=0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt);
    double balance() const;
    virtual void ViewAcct() const;
    virtual ~Brass(){}
};

class BrassPlus:public Brass
{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const std::string & s ="NUllbody",long an =-1,double bal=0.0,double m1 =500,double r=0.11125);
    BrassPlus(const Brass & ba,double m1=500.double r=0.11125);
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m){ maxLoan = m;}
    void ResetRate(double r){ rate = r;}
    void ResetOwes(){ owesBank = 0;}
}
#endif

















