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
    numItems = size;
}

template <class T>
Queue<T>::Queue(const Queue& Q)
{

}

template <class T>
Queue<T>::~Queue()
{
}

template <class T>
void Queue<T>::enqueue(T val)
{

}

template <class T>
void Queue<T>::dequeue(T& val)
{
    
}

template <class T>
bool Queue<T>::isEmpty() const
{

}

template <class T>
bool Queue<T>::isFull() const
{

}

template <class T>
void Queue<T>::clear()
{
    
}