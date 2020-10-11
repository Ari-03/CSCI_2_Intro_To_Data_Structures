/*
    Programmer : Aritra Das
    File Name  : lab7.cpp
    Date       : 10-10-2020
    Version    : 1.2
    Description:
    Using the Linked List Data Structure and adding a few values to the structure and displaying it.
*/
#include <iostream>
using namespace std;

//Node Structure that allows for the Linked List to Function
struct Node
{
    double data;
    Node  *next;
};

//List class hodls the functions of a Linked List
class List
{
private:
    //Data members that allows the creation and display of a Linked List
    Node *n;
    Node *head;
    Node *curr;
public:
    //Default constrctor that initilizes that data members to Null
    List()
    {
        n = nullptr;
        head = nullptr;
        curr = nullptr;
    }
    //Function that addes a New Node to the end of the List
    void apped(int val)
    {
        //Creates a New Node and assigns the data to be the input and next to Null
        n = new Node;
        n->data = val;//
        n->next = NULL;

        //If there is no Nodes in the list the head point to the newly created Node else we traverse the list
        if(head != NULL)
        {
            //Curr begins from the beginning of the list
            curr = head;
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
    }//End of Append Function

    //Function that displays all the nodes fromm the List
    void dispaly()
    {
        //Beginning from the start of the list
        curr = head;
        //Traversing the List
        while (curr != NULL)
        {
            //printing out the value of the Node
            cout << curr->data << endl;
            //Going to the next Node
            curr = curr->next;
        }
    }
    
    ~List() // Destructor, need to traverse the Linked List
    {
        curr = head;
        Node *nextNode;
        while(curr != NULL)//Not at the end of the List, Traversing the Linked List
        {
            nextNode = curr->next;
            delete curr;//Delete curr Node
            curr = nextNode;
        }
    }//End of Destructor       
};

int main()
{
    //Creating a new List dynamic object
    List *l = new List();
    //Adding a few Node to the list
    l->apped(1);
    l->apped(6);
    l->apped(3);
    l->apped(123);
    l->apped(98);
    //Displaying the Nodes  
    l->dispaly();
}
