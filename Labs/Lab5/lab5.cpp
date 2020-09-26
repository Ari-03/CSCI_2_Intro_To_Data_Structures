/*
    Programmer : Aritra Das
    File Name  : lab4.cpp
    Date       : 9-18-2020
    Version    : 1.2
    Description
    Testing mastery of virtual and abstract functions and the use of inheritance.
*/

#include <iostream>
using namespace std;

class Student
{
//Creating protected variables that will be accessble by derived functions    
protected:
    double GPA;
    int StudentID;
    int NumClasses;
public:
    //Creating a constructor to initilize a the member varibles
    Student(double gpa, int classes, int ID)
    {
        GPA = gpa;
        NumClasses = classes;
        StudentID = ID;
    }

    //Making virtual function so we can access children class functions froom the parent class
    virtual void CreditsRemaining()=0; 
    virtual string getMajor()= 0;

    //Prints out the Student ID, GPA, and Number of Classes
    virtual void print()
    {
        cout << "Student ID : " << StudentID << endl <<
                "Studen GPA : " << GPA << endl <<
                "Number of Classes : " << NumClasses << endl;
    }
};//End Student Class

//Undergraduates derives from Student 
class Undergraduate : public Student
{
//Adds Major and Credit that are unique to the undergraduate class
private:
   string ChosenMajor;
   int CreditsTaken;
public:
    //Uses Students Constructor to initilize gpa, number of class, and id, and then assigning major and credit taken
    Undergraduate(double gpa, int classes, int ID, string major, int credits) : Student(gpa, classes, ID)
    {
        ChosenMajor = major;
        CreditsTaken = credits;
    }
    //Mkaes the CreditRemaining and getMajor function to not make this class an abstract classs
    void CreditsRemaining()
    {
        cout << "Credits remaining until graduation : " << 120-CreditsTaken << endl;
    }
    string getMajor()
    {
        return ChosenMajor;
    }
    //Changes the print to output the new information
    void print()
    {
        cout << "Student ID : " << StudentID << endl <<
                "Studen GPA : " << GPA << endl <<
                "Student Major : " << ChosenMajor << endl <<
                "Number of Classes : " << NumClasses << endl <<
                "Credits Taken : " << CreditsTaken << endl;
    }
};//End Undergraduate Class


//Driver of the Undergraduate class
int main()
{
    //Creates an Undergraduate Object
    Student *bob = new Undergraduate(4.0, 6, 1056832, "Computer Science", 20);
    //Prints the Student Information and Credits that are remaining to graduate
    bob->print();
    bob->CreditsRemaining();
}