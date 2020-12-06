#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:
    T *qArray;
    int qSize;
    int front;
    int rear;
    int numItems;
public:
    Queue(int);//Constructor
    Queue(const Queue&);//Copy Constructor
    ~Queue();//Destructor
    void enqueue(T);//Adding a value to the rear
    void dequeue(T&);//Removing a value from the front
    bool isEmpty() const;//See if the Queue is empty
    bool isFull() const;//See if the Queue is full
    void clear();//Clears the values of the Queues
};

template <class T>
Queue<T>::Queue(int size)
{
    qSize = size;
    numItems = 0;
    qArray = new T[size];
    front = -1;
    rear = -1;
}

template <class T>
Queue<T>::Queue(const Queue& Q)
{
    
    
}

template <class T>
Queue<T>::~Queue()
{
    delete[] qArray;
}

template <class T>
void Queue<T>::enqueue(T val)
{
    if(isFull())
    {
        cout << "The Queue is Full.\n";
    }
    else
    {
        rear = (rear+1)%qSize;
        qArray[rear] = val;
        numItems++;
    }
}

template <class T>
void Queue<T>::dequeue(T& val)
{
    if(isEmpty())
    {
        cout << "The Queue is Empty.\n";
    }
    else if(front == rear)
    {
        val = qArray[front];
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front +1) % qSize; 
        val = qArray[front];
        numItems--;
    }
}

template <class T>
bool Queue<T>::isEmpty() const
{
    return (numItems == 0);
}

template <class T>
bool Queue<T>::isFull() const
{
    return numItems == qSize;
}

template <class T>
void Queue<T>::clear()
{
    front = qSize-1;
    rear = qSize-1;
    numItems = 0;
}