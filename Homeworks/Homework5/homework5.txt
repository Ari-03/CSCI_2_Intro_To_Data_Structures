/*
    Programmer : Aritra Das
    File Name  : homework5.cpp
    Date       : 9-25-2020
    Version    : 1.2
    Description
    Using virtual and abstract function to create many classes. Creates Shape, Point, Circle, and Cylinder class and uses inheritance to write effictive code.
*/

#include <iostream>
#include <math.h>
using namespace std;

const double PI = 2*acos(0.0);

class Shape
{
public:
    //Creates the virtual functions that will use used by sub classes

    //Prints the values of sub-class varialbes 
    virtual void print() = 0;
    //Prints the name of the sub-class shape
    virtual void printShapeName() = 0;
    virtual double area()
    {
        return 0;
    }
    virtual double volume()
    {
        return 0;
    }
};//End class Point

class Point : public Shape
{
protected:
    //Creates x, y variables to keep track of position
    double x;
    double y;
public:
    //Public constructor used to initilize x and y if no argument are passed
    Point()
    {
        x=0;
        y=0;
    }
    //Constructor that Assigns the value of x and y
    Point(double X, double Y)
    {
       x = X;
       y = Y;
    }
    void print()
    {
        cout << "x : " << x << endl <<
                "y : " << y << endl;
    }

    void printShapeName()
    {
        cout << "Point." << endl;
    }
};//End class Point


class Circle : public Point
{
protected:
    //Created radius to keep track of radius of a Circle
    double radius;
public:
    //Public constructor used to initilize x and y if no argument are passed
    Circle() : Point()
    {
        radius = 0;
    }
    //Constructor that Assigns the value of x, y, and radius 
    Circle(double X, double Y, double R) : Point(X, Y)
    {
        radius = R;
    }
    
    void print()
    {
        cout << "x : " << x << endl <<
                "y : " << y << endl <<
                "radius : " << radius << endl;
    }
    
    void printShapeName()
    {
        cout << "Cirlce." << endl;
    }
    //Calculates and returns the area of the Circle according to the radius
    double area()
    {
        return (PI * pow(radius,2.0));
    }
};//End class Circle

class Cylinder : public Circle
{
protected:
    double height;
public: 
    //Created radius to keep track of radius of a Circle
    Cylinder() : Circle()
    {
        height = 0;
    }
    //Public constructor used to initilize x and y if no argument are passed
    Cylinder(double X, double Y, double R, double H) : Circle(X,Y,R)
    {
        height = H;
    }
    void print()
    {
        cout << "X : " << x << endl <<
                "Y : " << y << endl <<
                "Radius : " << radius << endl <<
                "Height : " << height << endl;
    }
    void printShapeName()
    {
        cout << "Cylinder." << endl;
    }
    //Calculates the voulume of the Cylinder with radius and height
    double volume()
    {
        return (area()*height);
    }
};//End class Cylinder

//Driver of the All of the Classes
int main()
{
    //Creates a Point object and executes the its function
    Shape *sPtr = new Point(2,5);
    sPtr->printShapeName();
    sPtr->print();
    cout << endl;
    delete(sPtr);
    //Deletes the Point object the pointer was pointing to

    //Creates a Circle object and executes the its function
    sPtr = new Circle(5,2,5.3);
    sPtr->printShapeName();
    sPtr->print();
    double area = sPtr->area();
    cout << "Area of the Circle : " << area << endl ;
    cout << endl;
    delete(sPtr); 
    //Deletes the Circle object the pointer was pointing to

    //Creates a Cylinder object and executes the its function
    sPtr = new Cylinder(9,12,8.3,4.7);
    sPtr->printShapeName();
    sPtr->print();
    area = sPtr->area();
    cout << "Area of the Circle cross section: " << area << endl ;
    double volume = sPtr->volume();
    cout << "Volume of the Cylinder : " << volume << endl;
    delete(sPtr);
    //Deletes the Cylinder object the pointer was pointing to
}//end Main