#include <iostream>
using namespace std;

template <class T>
class DynamicStack
{
private:
    struct Node
    {
        T value;
        Node *next;
    };
    Node* top;
public:
    DynamicStack(/* args */);
    ~DynamicStack();
    //Stack operations
    void push(T);
    void pop(T&);
    bool isEmpty();
    void display();

};

template <class T>
DynamicStack<T>::DynamicStack(/* args */)
{
    top = NULL;
}

template <class T>
DynamicStack<T>::~DynamicStack()
{

}

template <class T>
bool DynamicStack<T>::isEmpty()
{
    return(top==NULL);
}

template<class T>
void DynamicStack<T>::pop(T& val)
{
    Node *temp;
    if (isEmpty())
    {
        cout << "The Stack is Empty.\n";  
    }
    else
    {
        val = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }    
} 

template <class T>
void DynamicStack<T>::push(T val)
{
    Node *n;
    n->value = val;
    if(isEmpty())
    {
        top = n;
        n->next = NULL;
    }
    else
    {
        n->next = top;
        top = n;
    }
}

template <class T>
void DynamicStack<T>::display()
{
    Node *curr = top;
    while(curr != NULL)
    {
        cout << curr->value << endl;
        curr = curr->next;
    }
}