#include <iostream>
using namespace std;

template<class T>
class DynamicQueue
{
private:
    struct Node
    {
        T value;
        Node *next;
    };
    Node* front;
    Node* rear;
    int numItems;    
public:
    DynamicQueue();
    ~DynamicQueue();
    //Queue Operations
    void enqueue(T);
    void dequeue(T&);
    bool isEmpty();
    void clear();
    void display();
    
};

template<class T>
DynamicQueue<T>::DynamicQueue() 
{
    front = NULL;
    rear = NULL;
    numItems = 0;
}

template<class T>
DynamicQueue<T>::~DynamicQueue()
{
    clear();
}

template<class T>
void DynamicQueue<T>::enqueue(T val)
{
    Node *n = new Node();
    n->value = val;
    n->next = NULL;
    if(isEmpty())
    {
        front = n;
        rear = n;
    }
    else
    {
        rear->next = n;
        rear = n;
    }
    numItems++;
}

template<class T>
void DynamicQueue<T>::dequeue(T& val)
{
    if(isEmpty())
    {
        cout << "The Queue is Empty.\n";
    }
    else
    {
        val = front->value;
        Node *temp = front;
        front = front->next;
        delete temp;
        numItems--;
    }
}

template<class T>
bool DynamicQueue<T>::isEmpty()
{
    return (numItems == 0);
}

template<class T>
void DynamicQueue<T>::clear()
{
    int values;
    while (!isEmpty())
    {
        dequeue(values);
    }
}

template<class T>
void DynamicQueue<T>::display()
{
    Node * curr = front;
    while (curr != NULL)
    {
        cout << curr->value << endl;
        curr = curr->next;
    }
}