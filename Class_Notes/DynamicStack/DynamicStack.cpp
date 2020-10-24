#include "DynamicStack.h"
#include <iostream>
using namespace std;

int main()
{
    DynamicStack<char> st1;
    char ch;
    char input = 'f';
    do
    {
        cout << "Stack Menu:\nP for push\nO for pop\nD for display\nQ for quit";
        cin >> ch;
        tolower(ch);
        switch (ch)
        {
        case 'p':
            st1.push(input);
            break;
        case 'o':
            st1.pop(input);
            break;
        case 'd':
            st1.display();
            break;
        
        default:
            cout << "Invaild Selection\n";
            break;
        }
    } while (ch != 'q');
}