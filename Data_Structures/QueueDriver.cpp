#include "Queue.h"

int main()
{
    int const Max_Size = 5;
    Queue<int> *iQueue = new Queue<int>(Max_Size);
    cout << "Enqueueing " << Max_Size << " items...\n";
    for (size_t i = 0; i < Max_Size; i++)
    {
        iQueue->enqueue(i);
    }
    cout << "Now Enqueuing again...\n";
    iQueue->enqueue(Max_Size);
    while(!iQueue->isEmpty())
    {
        int value;
        iQueue->dequeue(value);
        cout << value << endl;
    }
}