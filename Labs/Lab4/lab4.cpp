/*
    Programmer : Aritra Das
    File Name  : lab4.cpp
    Date       : 9-18-2020
    Version    : 1.2
    Description
    Testing mastery of inheritance.
*/

#include <iostream>
using namespace std;

class Employee
{
protected:
    string employeeName;
    int employeeNumber;
    int hireDate;
public:
    Employee(string E, int n, int h) //Constructor of Employee
    {
        employeeName = E;
        employeeNumber = n;
        hireDate = h;
    }
    //Getter and Setter for Employee
    void setEmployeeName(string E)
    {
        employeeName = E;
    }
    void setEmployeeNumber(int n)
    {
        employeeNumber = n;
    }
    void setHireDate(int h)
    {
        hireDate = h;
    }
    string getEmployeeName()
    {
        return employeeName;
    }
    int getEmployeeNumber()
    {
        return employeeNumber;
    }
    int getHireDate()
    {
        return hireDate;
    }
};

class ProductionWorker : public Employee
{
protected:
    int shift;
    double hourlyPayRate;
public:
   ProductionWorker(string E, int n, int h, double HPR, int S) : Employee(E,n,h) //Using inheritance to intilize Employee
   {
       shift = S;
       hourlyPayRate = HPR;
   }
   //Getter and Setter for Production Worker
   void setShift(int S)
   {
       shift = S;
   }
   void setHourlyPayRate(double HPR)
   {
       hourlyPayRate = HPR;
   }
   int getShift()
   {
       return shift;
   }
   double getHourlyPayRate()
   {
       return hourlyPayRate;
   }
};

int main()
{
    ProductionWorker worker("Bob the Builder", 1, 01122003, 30.25, 1);
    cout << "Hello " << worker.getEmployeeName() << " you are Employee Number " << worker.getEmployeeNumber() << ". You were hired on " << worker.getHireDate() << ", and get paid $" << worker.getHourlyPayRate() << " an hour. You are working the "; 
    if(worker.getShift() == 1)
    {
        cout << "day shift." << endl;
    }
    else if(worker.getShift() == 2)
    {
        cout << "night shift." << endl;
    }
    else
    {
        cout << "no shift." << endl;
    }
}