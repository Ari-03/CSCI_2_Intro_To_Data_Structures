/*
    Programmer : Aritra Das
    File Name  : lab2.cpp
    Date       : 9-2-2020
    Version    : 1.0
    Description
    This lab to rewrite this section with pointers instead of refrences and use the new funciton in a program. Program runs both the doSomthing with the call to reference and the call to pointer to show that they both output the same values 
*/

#include <iostream>

using namespace std;

int doSomething(int &x,  int &y);
int doSomething(int *x,  int *y);

int main()
{
    int x = 2, y = 3,z{},*a = &x,*b = &y,c{}; //Initialization the Varibles
    cout << "X : " << x << endl << "Y : " << y << endl << "A : " << *a << endl << "B : " << *b << endl << endl; //Printing out the values of the variables
    z = doSomething(x,y); //Using the given doSomething function with call to reference
    cout << "X : " << x << endl << "Y : " << y << endl << "Sum of X and Y : " << z << endl ; //Outputing the reponse
    x = 2; //Setting x and y values back to the initial values
    y = 3;
    c = doSomething(a,b); //Using the created doSomething function with call to pointer
    cout << "A : " << *a << endl << "B : " << *b << endl << "Sum of A and B ; " << c << endl; //Printing out the output to compare with the doSomething with the call to reference.

}

int doSomething(int &x,  int &y) //Given doSomething function
{
    int temp = x;

    x = y * 10 ;

    y = temp * 10;

    return x+y;
}

int doSomething(int *x,  int *y )//doSomething function that uses pointers 
{
    int temp = *x;

    *x = *y * 10 ;

    *y = temp * 10;

    return *x+*y;
}
