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

int subtreeSum(Node *root)
{
    if (root == nullptr)
        return 0;
    return root->data + subtreeSum(root->left) + subtreeSum(root->right);
}

void display(Node *root, int level)
{
    if (root == nullptr)
    {
        return;
    }
    display(root->right, level + 1);

    for (int i = 0; i < level; i++)
    {
        cout << "\t";
    }

    cout << " " << root->data << endl;

    display(root->left, level + 1);
}

bool findSubtree(Node *root, int target)
{
    if (root == nullptr)
        return false;
    int sum = subtreeSum(root);
    if (sum == target)
    {
        display(root, 0);
        return true;
    }
    return findSubtree(root->left, target) || findSubtree(root->right, target);
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

    int target = 90;
    if (!findSubtree(root, target))
        cout << "No subtree found with sum " << target << "." << endl;
}
