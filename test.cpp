#include <iostream>
using namespace std;
using ItemType = int;
class LinkedList {
private:
    struct Node 
    {
        ItemType value;
        Node* next;
    };
    Node* head = nullptr;
public:
    void printList() 
    {
        for (Node*& p = head; p !=nullptr; p=p->next)
        {
        cout << p->value << " ";
        cout << endl;
    }
    }
};