/*
    Programmer : Aritra Das
    File Name  : lab11.cpp
    Date       : 11-14-2020
    Version    : 1.2
    Description: This program uses queues to check if the strings that are inputed are the same
    
*/
#include "DynamicQueue.h"

int main()
{
    //Creating the strings to input into Charecter Dynamic Queue
    string input1, input2;
    DynamicQueue<char> *in1 = new DynamicQueue<char>;
    DynamicQueue<char> *in2 = new DynamicQueue<char>;
    bool flag = false;

    //This section gets the input from the user
    cout << "Enter two string that you want to compare.\nEnter the first string.\n";
    getline(cin, input1);
    cout << "Enter the second string.\n";
    getline(cin, input2);

    //For each loop that loads the input from the string to the queue
    for(char c : input1)
    {
        in1->enqueue(c);
    }
    for(char c : input2)
    {
        in2->enqueue(c);
    }
    
    //Checks if all of the data in the queue are the same flip flag if they are not
    while (!in1->isEmpty() && !in2->isEmpty())
    {
        char c1, c2;
        in1->dequeue(c1);
        in2->dequeue(c2);
        
        if(c1 != c2)
        {
            flag = true;
            break;
        }
    }   
    //If the flag is triggerd the program respose that strings are not the same else says they are the same
    if(flag)
    {
        cout << "The strings are not the same.\n";
    }
    else
    {
        cout << "The string are the same.\n";
    }
}