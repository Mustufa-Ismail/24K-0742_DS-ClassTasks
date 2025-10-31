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

int countNode(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    else
    {
        return 1 + countNode(root->left) + countNode(root->right);
    }
}

int countleaves(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else if (root->right == nullptr && root->left == nullptr)
    {
        return 1;
    }
    else
    {
        return countleaves(root->left) + countleaves(root->right);
    }
}

int height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

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


    cout << "Nodes: " << countNode(root) << endl;
    cout << "Leaves: " << countleaves(root) << endl;
    cout << "Height: " << height(root) << endl;

    return 0;
}
