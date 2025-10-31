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

void display(Node *node, int level)
{
    if (node == nullptr)
    {
        return;
    }
    display(node->right, level + 1);

    for (int i = 0; i < level; i++)
    {
        cout << "\t";
    }

    cout << " " << node->data << endl;

    display(node->left, level + 1);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(11);
    root->right = new Node(92);
    root->left->left = new Node(63);
    root->left->right = new Node(54);
    root->right->left = new Node(60);


    display(root, 0);

    return 0;
}