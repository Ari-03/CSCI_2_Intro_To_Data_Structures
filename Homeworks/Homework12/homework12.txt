/*
    Programmer : Aritra Das
    File Name  : homework12.cpp
    Date       : 11-22-2020
    Version    : 1.
    Description: This program has a Date class that catches if the day or month is not inputed correctlu and has a function and can display the date in 3 different manners.
*/

#include <iostream>

using namespace std;


class Date
{
private:
   int day, month, year;
public:
    class InvalidDay{};//Class that is thrown as an exception for invalid day
    class InvalidMonth{};//Class that is thrown as an exception for invalid month
    Date(int,int,int);//Constructor that initilizes the testArray and throw exception if invalid input is given
    void printDate();
};

int main()
{
    //Stores the input for the days month and year
    int day{}, month{}, year{};

    //Gets the input for day month and year
    cout << "Enter the Day : ";
    cin >> day;//input
    cout << "Enter the Month : ";
    cin >> month;//input
    cout << "Enter the Year : ";
    cin >> year;//input

    //We use try block to catch the exception
    try
    {
        //Will throw an exception if then not 1 <= day <= 31 or 1 <= month <= 12  
        Date dt(day, month, year);
        //Prints the date in three differnt styles
        dt.printDate();
    }
    //Catches if the excpetion is invalid day and returns an message saying the day is wrong
    catch(Date::InvalidDay)
    {
        cout << "The Day that you have entered is invalid." << endl;
    }
    //Cates if the excpetion is invalid month and returns an message saying the month is wrong
    catch(Date::InvalidMonth)
    {
        cout << "The Month that you have entered is invalid" << endl;
    }
    return 0;
}

//Checks if the days and months are correct
Date::Date(int d, int m, int y)
{
    if(d < 1 || d > 31)
    {
        throw InvalidDay();
    }
    if(m < 1 || m > 12)
    {
        throw InvalidMonth();
    }
    day = d;
    month = m;
    year = y;
}

//prints the dates in three different ways
void Date::printDate()
{
    const char * months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    cout << month << '/' << day << '/' << year << endl <<
            months[month-1] << ' ' << day << ',' << year << endl <<
            day << ' ' << months[month-1] << ' ' << year << endl;
}