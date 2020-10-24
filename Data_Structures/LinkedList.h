/*
    Programmer : Aritra Das
    File Name  : lab8.cpp
    Date       : 10-17-2020
    Version    : 1.2
    Description:
    Using the Linked List Data Structure and adding a few values to the structure and displaying it.
*/
#include <iostream>
using namespace std;


//List class hodls the functions of a Linked List
template<class T>
class List
{
private:
    //Data members that allows the creation and display of a Linked List
    struct Node
    {
        T data;
        Node  *next;
    };
    Node *head;
public:
    //Default constrctor that initilizes that data members to Null
    List();

    //Function that addes a New Node to the end of the List
    void append(T val);//End of Append Function

    //Function  that inserts a node in assending order
    void insert(T val);

    //Function maked to reverse a Linked List
    void reverse();


    //Function that displays all the nodes fromm the List
    void dispaly();

    // Destructor, need to traverse the Linked List
    ~List();
};

template <class T>
List<T>::List()
{
    head = nullptr;
}

template <class T>
void List<T>::append(T val)
{
    //Creates a New Node and assigns the data to be the input and next to Null
    Node *n = new Node;
    n->data = val;
    n->next = NULL;

    //If there is no Nodes in the list the head point to the newly created Node else we traverse the list
    if(head != NULL)
    {
        //Curr begins from the beginning of the list
        Node *curr = head;
        //Traversing the whole list
        while (curr->next != NULL)
        {
            curr = curr->next;//Go Forward
        }
        //Assigning the last node of the list to be the newly created node
        curr->next = n;
    }
    else
    {
        head = n;
    }
}

template <class T>
void List<T>::insert(T val)
{
    Node *n = new Node;//Creates a New Node to hold the value of val.
    Node *preNode = NULL;//PreNode is cerated the to connect the Linked List together
    n->data = val;
    n->next = NULL;
    if(head == NULL)//If there is not objects in the Linked list then the head points to the new Node.
    {
        head = n;   
    }
    else
    {
        Node *curr = head;//makes the current node pointer point to the head node
        while(curr != NULL && curr->data < val)//while the current Node is null and the current Node's data is is less than the value passed then we move the current Node and set the previouse Node.
        {
            preNode = curr;
            curr = curr->next;
        }
        if (preNode == NULL)//If the previous Node is Null meaning that the while loop is not excuted once because the first value of the List is bigger than the value passed then head points to the new node and the new nodes next is the previous head node's location
        {
            head = n;
            n->next = curr;
        }
        else// Else the preNode point to the new Node and the new Node points to the Current Node.
        {
            preNode->next = n;
            n->next = curr;
        }
    }
}

template <class T>
void List<T>::reverse()
{
    Node *next = head->next;//The next nPtr so we can traverse the list after we change the next for the current node
    Node *curr = head;//The current nPtr so we can change the node's next to the previous node
    Node *pre = NULL;//The previous nPtr to we can set the current's next to this node
    if(head != NULL)//Reverse only works if the Linked List is not exmpty
    {
        while (next != NULL)//While the next nPtr is not Null
        {
            curr->next = pre;//We set the current's next to the previous node
            //Traverse the Linked List
            pre = curr;
            curr = next;
            next = next->next;
        }
        curr->next = pre;//Connect the currrent's next to the previous node
        head = curr;//We set the head nPtr to the current
    }        
}

template <class T>
void List<T>::dispaly()
{
    //Beginning from the start of the list
    Node *curr = head;
    //Traversing the List
    while (curr != NULL)
    {
        //printing out the value of the Node
        cout << curr->data << "->";
        //Going to the next Node
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

template <class T>
List<T>::~List()
{
    Node *curr = head;
    Node *nextNode;
    while(curr != NULL)//Not at the end of the List, Traversing the Linked List
    {
        nextNode = curr->next;
        delete curr;//Delete curr Node
        curr = nextNode;
    }
}//End of Destructor