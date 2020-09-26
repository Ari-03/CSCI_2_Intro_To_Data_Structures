/*
    Programmer : Aritra Das
    File Name  : lab3.cpp
    Date       : 9-11-2020
    Version    : 1.2
    Description
    This lab is designed to make a class, TestScore, that will keep trake of the test scores and return the average of the test score.
*/

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
using namespace std;

class MortgagePayment
{
private:
    double principal;
    double rate;
    int term;
public:

    MortgagePayment(double P, double R, int T)
    {
        principal = P;
        rate = R/1200.0;
        term = T*12.0;
    }
    //Creating the getters and setters for the class
    double getPrincipal()
    {
        return principal;
    }
    void setPrincipal(double p)
    {
        principal = p;
    }

    double getRate()
    {
        return rate;
    }
    void setRate(double r)
    {
        rate = r/1200.0;
    }

    int getTerm()
    {
        return term;
    }
    void setTerm(double t)
    {
        term = t*12;
    }

    //Finds the Mortgage Payment according to the equation given
    double getMortgagePayment()
    {
        return (principal * rate)/(1.0 - pow((rate+1),-term));
    }
    //Finds the total by multiplying the monthly rate with the term of mortgage
    double getTotalPayment()
    {
        return getMortgagePayment()*term;
    }
};

int main()
{
    double principal{};
    double rate{};
    int years{};

    //Checks for negative number and if found askes person to input the correct input
    do{
        cout << "Enter the Principal of the Mortgage : " << endl;
        cin >> principal;
    }
    while (principal < 0);   

    do {
        cout << "Enter the Rate of the Mortgage : " << endl;
        cin >> rate;
    }
    while (rate < 0);  

    do{
        cout << "Enter the Term of the Mortgage(in Years) : " << endl;
        cin >> years;
    }
    while (years < 0); 

    MortgagePayment Payment(principal, rate, years);
    //Prints out the Monthly and Total Mortgage payments 
    cout << showpoint << setprecision(2) << fixed << "The Monthly Mortgage Payment is : " << Payment.getMortgagePayment() << endl << "The Total Mortgage Payment is : " << Payment.getTotalPayment() << endl; 
}