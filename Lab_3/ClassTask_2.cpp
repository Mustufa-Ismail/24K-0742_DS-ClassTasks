#include <iostream>
using namespace std;

class Node
{
public:
    string data;
    Node *next;

    Node(string name) : data(name), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList(Node *head) : head(head), tail(head) {}

    void insertAtTail(string name)
    {
        Node *nn = new Node(name);
        if (head == nullptr)
        {
            head = nn;
            tail = nn;
        }
        tail->next = nn;
        tail = nn;
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
            tail = nullptr;
        }
        else
        {
            head = head->next;
        }
        delete temp;
    }

    void searchByName(string name)
    {
        if (head == nullptr)
        {
            cout << "Linkedlist does not exist";
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == name)
            {
                cout << name << " exists in the list" << endl;
                return;
            }
            temp = temp->next;
        }

        cout << name << " does not exists in the list" << endl;
        return;
    }

    void searchByPosition(int pos)
    {
        if (head == nullptr)
        {
            cout << "Linkedlist does not exist";
            return;
        }

        int cur_pos = 1;
        Node *temp = head;
        while (temp != nullptr)
        {
            if (cur_pos == pos)
            {
                cout << "At position " << pos << ": " << temp->data << " exists" << endl;
                return;
            }
            temp = temp->next;
            cur_pos++;
        }

        cout << pos << "does not exists in the list" << endl;
        return;
    }

    void displayList()
    {
        Node *temp = head;
        cout << "\nList:" << endl;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "Null \n" << endl;
        return;
    }
};

int main()
{
    Node *n1 = new Node("Data Structures");
    LinkedList l1(n1);

    l1.insertAtTail("Operating Systems");
    l1.insertAtTail("Computer Networks");
    l1.insertAtTail("Database Systems");
    l1.displayList();

    l1.deleteFromFront();
    l1.displayList();

    l1.searchByName("Computer Networks");
    l1.searchByPosition(3);

    return 0;
}