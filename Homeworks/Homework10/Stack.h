/*
    Programmer : Aritra Das
    File Name  : stack.cpp
    Date       : 10-23-2020
    Version    : 1
    Description:
    Stack Header
*/
#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
	T *stackArray;
	int size;//Size Of Stack
	int top;// Top of stack or array index
public:
	Stack(int sz); // Constructor takes size of array
	Stack(const Stack&);//Copy Constructor
	~Stack();//Destructor
	void display(); //Display stack
	void push(T);//Inserts element into stack
	T pop();//Removes element from the stack
	bool isFull() const;//Checks if the stack is full
	bool isEmpty() const;//Checks if the stack is empty
};

template <class T>
Stack<T>::Stack(int sz)
{
	stackArray = new T[sz];
	size = sz;
	top = -1;
}//end of constuctor

template <class T>
Stack<T>::Stack(const Stack&  stk)
{
	if(stk.size > 0)
	{
		stackArray = new T[stk.size];
	}
	else
	{
		stackArray = NULL;
	}
	//Copying all of the stackArray
	for (size_t i = 0; i < stk.size; i++)
	{
		stackArray[i] = stk.stackArray[i];
	}
	//Set top of stack
	top = stk.top;
}

template <class T>
void Stack<T>::push(T num)
{
	if(isFull())
	{
		cout << "The Stack is Full.\n";
	}
	else
	{
		top++;
		stackArray[top] = num;
	}
}//end push

template <class T>
T Stack<T>::pop()
{
	if(isEmpty())
	{
		cout << "The Stack is Empty.\n";
	}
	else
	{
		cout << stackArray[top] << endl;
		return stackArray[top--];
	}
}//End pop

template <class T>
void Stack<T>::display()
{
	int t = top;
	cout << "[";
	while( t >= 0)
	{
		cout  << stackArray[t] << "|";
		t--;
	}
	cout << "End]\n";
}//End Display

template <class T>
Stack<T>::~Stack()
{
	delete [] stackArray;
}//End Destructor

template <class T>
bool Stack<T>::isFull() const
{
	if(top == size-1)
		return true;
	return false;
}

template <class T>
bool Stack<T>::isEmpty() const
{
	if(top == -1)
		return true;
	return false;
}
