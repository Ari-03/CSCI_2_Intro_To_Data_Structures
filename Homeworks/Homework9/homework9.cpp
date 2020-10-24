/*
    Programmer : Aritra Das
    File Name  : homework9.cpp
    Date       : 10-23-2020
    Version    : 1
    Description:
    Balancing parentheses from a given input string
*/
#include "Stack.h"//includes the Stack header with the Stack Data Type

#include <iostream>
using namespace std;

bool parenthesesCheck(string input)
{
    Stack<char> *ptr = new Stack<char>(25);//Creates Stack with a size of 25 as that seems like the max amount of '(' in a typical input
    for (size_t i = 0; i < input.size(); i++)//Iterates over the entire string input
    {
        if(input[i] == '(')//If the char is '(' we add to the stack
            ptr->push(input[i]);
        if(input[i] == ')')//If the char is ')'
        {
            if(ptr->isEmpty())//See if the stack is empty to see if there is a open parenthesis '(' infront of the ')' If one does not exist then the parentheses is not balanced
            {
                return false;
            }
            ptr->pop();//Remove one '(' form the stack
        }
    }
    return (ptr->isEmpty());//If nothing remains in the stack and the function has not terminated before reaching here then the parenthesis is balanced.
}

int main()
{
    cout << "Enter the string that you want to balance parentheses :" << endl;
    string input;
    getline(cin,input);//Gets the input
    
    //if the function returns true the parentheses are balanced else not balanced.
    if(parenthesesCheck(input))
    {
        cout << "The Parentheses are Balanced.\n";
    }
    else
    {
        cout << "The parentheses are Not Balanced.\n";
    }
    
}