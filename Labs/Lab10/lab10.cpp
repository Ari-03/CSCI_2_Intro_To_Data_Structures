/*
    Programmer : Aritra Das
    File Name  : lab10.cpp
    Date       : 10-30-2020
    Version    : 1
    Description:
    This is the math stack program where the math stack class can excutes the Mult, Div, addAll, and multAll commands using dynamic stack
*/
#include "DynamicStack.h"

class MathStack : public DynamicStack<int>//The Math Stack extends from the Dynamic Stack Headder
{
public:
    //Has the same construtor
    MathStack()
    {
        DynamicStack();
    }

    //Mult pops the first two numbers then push the product
    int Mult()
    {
        int num1, num2;
        this->pop(num1);
        this->pop(num2);
        this->push(num1*num2);
    }

    //Div pop the first two numbers then push the quotient of the first divided by the second pop
    int Div()
    {
        int num1, num2;
        this->pop(num1);
        this->pop(num2);
        this->push(num1/num2);
    }

    //Pop all of the elements in the stack and pushes the sum into the stack
    void addAll()
    {
        int sum{};
        while(!this->isEmpty())
        {
            int num;
            this->pop(num);
            sum += num;
        }
        this->push(sum);
    }

    //Pop all of the elements in the stack and pushes the product into the stack
    void multAll()
    {
        int product = 1;
        while(!this->isEmpty())
        {
            int num;
            this->pop(num);
            product *= num;
        }
        this->push(product);
    }
};

int main()
{
    //Creating and populating the stack
    MathStack *mStack = new MathStack();
    mStack->push(12);
    mStack->push(74);
    mStack->push(54);
    mStack->push(37);
    mStack->push(47);
    mStack->display();
    cout << "\n";
    //Using the Mult command 
    mStack->Mult();
    mStack->display();
    cout << "\n";
    //Using the Div command
    mStack->Div();
    mStack->display();
    cout << "\n";
    //Using the add all command
    mStack->addAll();
    mStack->display();
    cout << "\n";
    //Populating the stack somemore and using the multAll command
    mStack->push(64);
    mStack->push(97);
    mStack->push(48);
    mStack->push(27);

    mStack->multAll();
    mStack->display();
    cout << "\n";
}


