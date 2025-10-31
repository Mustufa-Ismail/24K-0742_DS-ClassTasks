#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

bool isFullBinary(Node *root)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        return true;
    }

    if (root->left != nullptr && root->right != nullptr)
    {
        return isFullBinary(root->left) && isFullBinary(root->right);
    }

    return false;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(11);
    root->right = new Node(92);
    root->left->left = new Node(63);
    root->left->right = new Node(54);
    root->right->left = new Node(60);
    root->right->right = new Node(0);

    if (isFullBinary(root))
    {
        cout << "Tree is full binary tree";
    }
    else
    {
        cout << "Tree is not a full binary tree";
    }

    return 0;
}