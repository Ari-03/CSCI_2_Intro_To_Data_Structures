/*
    Programmer : Aritra Das
    File Name  : lab11.cpp
    Date       : 11-15-2020
    Version    : 1.2
    Description: This program uses queues to make the string input to upper case
    
*/
#include "DynamicQueue.h"

int main()
{
    //Creating the strings for input and output into Charecter Dynamic Queue
    string input, output;
    DynamicQueue<char> *in = new DynamicQueue<char>;

    //This section gets the input from the user
    cout << "Enter the string you want to change to UpperCase.\n";
    getline(cin, input);

    //For each loop that enqueue the input from the string to the queue
    for(char c : input)
    {
        in->enqueue(c);
    }
    
    //We add the upper case of the string into the string output
    while (!in->isEmpty())
    {
        char c;
        in->dequeue(c);
        output += toupper(c);
    }   
    //Returns the capitilized output
    cout << "The input to upper case is : " << output << endl;
}