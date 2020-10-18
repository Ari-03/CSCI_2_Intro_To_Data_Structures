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
	Stack(T); // Constructor takes size of array
	Stack(const Stack&);//Copy Constructor
	~Stack();//Destructor
	void display(); 
	void push(T);
	T pop();
	bool isFull() const;
	bool isEmpty() const;
};

template <class T>
Stack<T>::Stack(T sz)
{
	stackArray = new T[sz];
	size = sz;
	top = -1;
}//end of constuctor

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
	while( t >= 0)
	{
		cout  << stackArray[t] << endl;
		t--;
	}
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