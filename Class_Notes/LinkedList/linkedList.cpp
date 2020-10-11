#include <ostream>
using namespace std;

struct Node
{
    double data;
    Node  *next;
};

class List
{
private:
    Node *n;
    Node *head;
    Node *temp;
    Node *curr;
public:
    void apped(int val)
    {
        n = new Node;
        n->data = val;
        n->next = NULL;
        if(head != NULL)
        {
            curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;//Go Forward
            }
            curr->next = n;
        }
        else
        {
            head = n;
        }
    }
    void insertNode(int val)
    {
        n = new Node;
        Node *preNode;
        n->data = val;
        n->next = NULL;
        if(head == NULL)//If the Linked List is 
        {
            head = n;
        }
        else
        {       
            curr = head;
            preNode = NULL;
            while(curr != NULL && curr->data < val)
            {
                preNode = curr;
                curr = curr->next;
            }
            if(preNode = NULL)//Only 1 Node in a Linked List
            {
                head = n;
                n->next = curr;
            }
            else
            {
                preNode->next = n;
                n->next = curr;
            }     
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
