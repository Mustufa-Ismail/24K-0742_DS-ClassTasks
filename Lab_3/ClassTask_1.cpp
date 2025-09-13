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

    LinkedList(Node *head) : head(head) {}

    void insertAtStart(string name)
    {
        Node *nn = new Node(name);
        nn->next = head;
        head = nn;
    }

    void insertAtEnd(string name)
    {
        Node *nn = new Node(name);
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

        return;
    }

    void insertAfterValue(string pos_Name, string name)
    {
        Node *nn = new Node(name);
        if (head == nullptr)
        {
            cout << "Linkedlist does not exist";
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == pos_Name)
            {
                break;
            }
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Book doesnt exist";
            return;
        }

        nn->next = temp->next;
        temp->next = nn;
    }

    void search(string name)
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
                cout << name << "exists in the list" << endl;
                return;
            }
            temp = temp->next;
        }

        cout << name << "does not exists in the list" << endl;
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
        cout << "Null" << endl;
        return;
    }
};

int main()
{
    Node *n1 = new Node("Data Structures");
    LinkedList l1(n1);

    l1.insertAtEnd("Operating Systems");
    l1.insertAtEnd("Computer Networks");
    l1.insertAtEnd("Database Systems");
    l1.displayList();

    l1.insertAtStart("Artificial Intelligence");
    l1.displayList();

    l1.insertAtEnd("Machine learning");
    l1.displayList();

    l1.insertAfterValue("Operating Systems", "Cyber Security");
    l1.displayList();

    l1.search("Database Systems");

    l1.displayList();
}