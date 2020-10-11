/*
    Programmer : Aritra Das
    File Name  : lab6.cpp
    Date       : 10-3-2020
    Version    : 1.2
    Description
    Overloading the division operator for a class called fraction
*/
#include <iostream>
using namespace std;

class Fraction
{
private:
    double Num, Dnum; // Numerator and Denominator for Fraction Class
public:
   Fraction()//Basic Constructor
   {
       Num = 0.0;
       Dnum = 0.0;
   }
   Fraction(double N, double D)//Constructor if value are inputed
   {
       Num = N;
       Dnum = D;
   }
   //Friend function for all the overrloaded functions
   friend Fraction operator *(Fraction f1, Fraction f2); 
   friend Fraction operator /(Fraction f1, Fraction f2);
   friend bool operator >(Fraction f1, Fraction f2);
   friend bool operator <(Fraction f1, Fraction f2);
   friend ostream& operator << (ostream& o, const Fraction& f);
   friend istream& operator >> (istream& i, Fraction& f);
};//End Fraction

//Overloaded * for Fraction
Fraction operator *(Fraction f1, Fraction f2)
{
	Fraction temp; //Temp Num and Denum are are the product of f1 and f2
	temp.Num = f1.Num * f2.Num;
    temp.Dnum = f1.Dnum * f2.Dnum;
    return temp;
}

//Overloaded / for Fraction
Fraction operator /(Fraction f1, Fraction f2)
{
    Fraction temp;//Temp Num and Denum are are the product of f1 and reciprocal f2
    temp.Num = f1.Num * f2.Dnum;
    temp.Dnum = f1.Dnum * f2.Num;
    return temp;
}
//Overloadec < for Fraction
bool operator <(Fraction f1, Fraction f2)
{
    //Reutrn true is the product of f1 num/dnum is greater than f2
    if((f1.Num/f1.Dnum) < (f2.Num/f2.Dnum))
    {
        return true;
    }
    return false;
}
//Overloadec > for Fraction
bool operator >(Fraction f1, Fraction f2)
{
    //Reutrn true is the product of f1 num/dnum is less than f2
    if((f1.Num/f1.Dnum) > (f2.Num/f2.Dnum))
    {
        return true;
    }
    return false;
}

ostream& operator <<(ostream& o, const Fraction& f)
{
    o << f.Num << "/" << f.Dnum << endl;
}

istream& operator >> (istream& i, Fraction& f)
{
    char slash = '/';
    i >> f.Num >> slash >> f.Dnum;
}