#include <iostream>
using namespace std;

template<class T>
class BST
{
private:
    struct TreeNode
    {
        T data;
        TreeNode *left;
        TreeNode *right;
    };
    TreeNode *root;
public:
    BST(/* args */);
    ~BST();
};

template<class T>
BST<T>::BST(/* args */)
{
}

template<class T>
BST<T>::~BST()
{
}
