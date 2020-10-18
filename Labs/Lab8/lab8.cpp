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
    struct Node
    {
        double data;
        Node  *next;
    };
    Node *head;
public:
    //Default constrctor that initilizes that data members to Null
    List()
    {
        head = nullptr;
    }

    //Function that addes a New Node to the end of the List
    void apped(int val)
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
    }//End of Append Function

    //Function  that inserts a node in assending order
    void insert(int val)
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
            while(curr->data < val && curr != NULL)//while the current Node is null and the current Node's data is is less than the value passed then we move the current Node and set the previouse Node.
            {
                preNode = curr;
                curr = curr->next;
            }
            if (preNode == NULL)//If the previous Node is Null meaning that the while loop is not excuted once because the first value of the List is bigger than the value passed then head points to the new node and the new nodes next is the previous head node's location
            {
                head->next = n;
                n->next = curr;
            }
            else// Else the preNode point to the new Node and the new Node points to the Current Node.
            {
                preNode->next = n;
                n->next = curr;
            }
        }
    }

    //Function that displays all the nodes fromm the List
    void dispaly()
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
        cout << endl;
    }

    // Destructor, need to traverse the Linked List
    ~List() 
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
};

int main()
{
    //Creating a new List dynamic object
    List *l = new List();
    //Adding a few Node to the list
    l->insert(12);
    l->insert(1);
    l->insert(72);
    l->insert(7);
    l->insert(54);
    l->insert(63);
    //Displaying the Nodes  
    l->dispaly();
}
