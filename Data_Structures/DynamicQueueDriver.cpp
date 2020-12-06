#include "DynamicQueue.h"

int main()
{
    const int Max_Value = 5;
    DynamicQueue<int> *iQueue =  new DynamicQueue<int>();
    cout << "Enqueueing " << Max_Value << " items...\n";
    for (size_t i = 0; i < Max_Value; i++)
    {
        iQueue->enqueue(i);
    }
    cout << "Now Enqueuing again...\n";
    iQueue->enqueue(Max_Value);
    while(!iQueue->isEmpty())
    {
        int value;
        iQueue->dequeue(value);
        cout << value << endl;
    }
}