/*
    Programmer : Aritra Das
    File Name  : homework10.cpp
    Date       : 10-30-2020
    Version    : 1
    Description:
    This is a inventory stack program where you can add and remove inventory objects to and from a stack.
*/

#include "Stack.h"
//The Date Structure holds the day, month, and year
struct Date
{
    int year;
    int month;
    int day;

    //The friend functions allow to input and output from cout and cin without using functions
    friend istream & operator >>(istream&i, Date &d);
    friend ostream & operator <<(ostream&o, Date &d);

    //The = operator sets the Date equal to a passed data
    void operator=(const Date & d)
    {
        year = d.year;
        month = d.month;
        day = d.day;
    }
};

//cin formating to get inputs into Date sturcture
istream & operator>>(istream&i,Date&d)
{
    char slash;
    i >> d.month >> slash >> d.day >> slash >> d.year;
    return i;
}
//cout formating to display the date
ostream & operator <<(ostream&o, Date &d)
{
    o << d.month << '/' << d.day << '/' << d.year;
    return o;
}

//Class that holds the serialNumber, lotNumber, and manufacturing date for inventory products
class Inventory
{
private:
    int serialNumber;
    int lotNumber;
    Date manufactDate;    
public:
    //Sets the value of an Inventory object
    Inventory(int,int, Date);
    //Is needed for the the creationg of Inventory Stack
    Inventory();
    //Makes it easier to output the values of the Inventory with a cout.
    friend ostream & operator << (ostream&o, Inventory&i);  
};

ostream & operator << (ostream&o, Inventory&i)
{
    o <<"The Serial Number : " << i.serialNumber << endl <<
        "The Lot Number : " << i.lotNumber << endl <<
        "The Manufactured Date : " << i.manufactDate << endl;
}

Inventory::Inventory(int sNum, int lNum, Date mDate)
{
    serialNumber = sNum;
    lotNumber = lNum;
    manufactDate = mDate;
}

Inventory::Inventory()
{
    serialNumber = 0;
    lotNumber = 0;
    manufactDate = {0,0,0};
}


int main()
{
    //The charecter the holds the user response for what they want to do
    char responce;
    //Loop switch that keeps the while looping 
    bool lSwitch = true;
    //Inventory Stack
    Stack<Inventory> *invertoryStack = new Stack<Inventory>(50);
    while (lSwitch)
    {
        //Prompting the user what they want to do
        cout << "If you want to Add Items Press(A).\nIf you want to Remove the Top Item Press(R).\nIf you want to Stop Press(S).\n";
        //Gets response
        cin >> responce;
        responce = toupper(responce);
        switch (responce)
        {
        //If user wants to add items then prompts user for the needed information
        case 'A':
            {
                int sNum, lNum;
                Date mDate;
                cout << "Enter the Serial Number : \n";
                cin >> sNum;
                cout << "Enter the Lot Number : \n";
                cin >> lNum;
                cout << "Enter the Manufactured Date(MM/DD/YYYY) : \n";
                cin >> mDate;

                Inventory temp(sNum,lNum,mDate);
                invertoryStack->push(temp);
                break;
            }
        //If user wants to remove item, pops item on top of Stack
        case 'R':
            {
                invertoryStack->pop();
                break;
            }
        //If user wants to stop, the loop switch set to false
        case 'S':
            {
                lSwitch = false;
                break;
            }
        //The user has entered an incorrect reponse
        default:
            {
                cout << "Please enter a valid responce\n";
                break;
            }
        }
    }
}