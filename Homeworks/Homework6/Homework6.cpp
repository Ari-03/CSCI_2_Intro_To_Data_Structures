/*
    Programmer : Aritra Das
    File Name  : lab6.cpp
    Date       : 10-3-2020
    Version    : 1.2
    Description
    Making a NumDay class with overloaded operators
*/
#include <iostream>
using namespace std;

//Clas NumDay to find the Number of work days someone has worked
class NumDays
{
private:
    double hours, numDay;
public:
    //Basic constructor
    NumDays()
    {
        hours = 0;
        setNumDay();
    }
    //Constructor that inputs hours and sets hours and NumDay
    NumDays(double H)
    {
        hours = H;
        setNumDay();
    }

    //Helper function to display work in day-hour format
    void getWorkTime()
    {
        int workDays = hours/8;
        cout << "Work Days : " << workDays << endl <<
                "Work Hours : " << hours - workDays*8 << endl;
    }
    //Helper function to set the NumDay var to hours/8
    void setNumDay()
    {
        numDay = hours/8;
    }
    //Setter function to set hours and NumDay
    void setHours(double H)
    {
        hours = H;
        setNumDay();
    }
    //Getter for hour
    double getHours()
    {
        return hours;
    }
    //Friedn functions
    friend NumDays operator+(NumDays D1, NumDays D2);
    friend NumDays operator-(NumDays D1, NumDays D2);
    friend void operator++(NumDays& D);
    friend void operator--(NumDays& D);
};
//Overloading + operator for two NumDay Class. Adds together the hours of both clases
NumDays operator+(NumDays D1, NumDays D2)
{
    NumDays temp;
    temp.hours = D1.hours + D2.hours;
    temp.setNumDay();
    return temp;
}
//Overloading + operator for two NumDay Class. Subtract first hour with the second hour
NumDays operator-(NumDays D1, NumDays D2)
{
    NumDays temp;
    temp.hours = D1.hours + D2.hours;
    temp.setNumDay();
    return temp;
}
//Overloads ++ operator. Increses hour for NumDay class by 1
void operator++(NumDays& D)
{
    D.hours++;
    D.setNumDay();
}
//Overloads -- operator. Decreases hour for NumDay class by 1
void operator--(NumDays& D)
{
   D.hours--;
   D.setNumDay();
}