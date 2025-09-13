#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *pre;

    Node(int n) : data(n), next(nullptr), pre(nullptr) {}
};

class LinkedList
{
public:
    Node *head;
    LinkedList(Node *head) : head(head) {}

    void insertAtEnd(int val)
    {
        Node *nn = new Node(val);

        if (head == nullptr)
        {
            head = nn;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = nn;
        nn->pre = temp;

        return;
    }

    void deleteFromFront()
    {
        if (head == nullptr)
        {
            cout << "List is empty";
            return;
        }
        Node *temp = head;
        if (head->next == nullptr)
        {
            head = nullptr;
            delete temp;
            return;
        }

        head = head->next;
        head->pre = nullptr;

        delete temp;
    }

    void search(int val)
    {
        if (head == nullptr)
        {
            cout << "List is empty";
            return;
        }
        int pos = 1;
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                cout << "Compartment " << val << " is at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Compartment not found";
        return;
    }

    void displayList()
    {
        Node *temp = head;
        cout << "\nList:" << endl;
        while (temp != nullptr)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "Null" << endl;
        return;
    }
};

int main()
{
    Node *n1 = new Node(1);
    LinkedList l1(n1);

    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    l1.insertAtEnd(4);
    l1.displayList();

    l1.deleteFromFront();
    l1.displayList();

    l1.search(4);

    return 0;
}