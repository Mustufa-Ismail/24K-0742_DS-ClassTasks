#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int n) : data(n), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;
    LinkedList(Node *n) : head(n) {}

    void insert(int n)
    {
        Node *nn = new Node(n);
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

    void sort()
    {
        if (head == nullptr)
        {
            cout << "List does not exist";
            return;
        }

        if (head->next == nullptr)
        {
            return;
        }

        bool swapped = false;

        do
        {
            swapped = false;
            Node *temp = head;
            while (temp->next != nullptr)
            {
                if (temp->data > temp->next->data)
                {
                    int t = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = t;

                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }

    void concatenate(LinkedList &other)
    {
        if (head == nullptr)
        {
            head = other.head;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = other.head;
    }

    void findMiddle()
    {
        if (head == nullptr)
        {
            cout << "List does not exist";
            return;
        }

        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle value:" << slow->data;
    }

    void removeDuplicates()
    {
        sort();
        Node *temp = head;

        while (temp != nullptr && temp->next != nullptr)
        {
            if (temp->data == temp->next->data)
            {
                Node *temp2 = temp->next;
                temp->next = temp->next->next;
                delete temp2;
            }
            else
            {
                temp = temp->next;
            }
        }
    }

    void mergeSortedList(LinkedList &other)
    {
        Node *head1 = this->head;
        Node *head2 = other.head;

        if (head1 == nullptr)
        {
            head = head2;
            head2 = nullptr;
            return;
        }
        if (head2 == nullptr)
        {
            return;
        }

        Node *dummy = new Node(0);
        Node *temp = dummy;

        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->data <= head2->data)
            {
                temp->next = head1;
                head1 = head1->next;
            }
            else
            {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }

        if (head1 == nullptr)
        {
            temp->next = head2;
        }
        else
        {
            temp->next = head1;
        }

        this->head = dummy->next;
        delete dummy;
        other.head = nullptr;

        return;
    }
};

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    LinkedList l1(n1);
    LinkedList l2(n2);

    l1.insert(5);
    l1.insert(9);
    l1.insert(3);
    l1.insert(7);

    l2.insert(4);
    l2.insert(6);
    l2.insert(8);
    l2.insert(10);

    cout << "Initial Lists:" << endl;
    l1.displayList();
    l2.displayList();

    cout << "\nSorting l1:" << endl;
    l1.sort();
    l1.displayList();

    cout << "\nSorting l2:" << endl;
    l2.sort();
    l2.displayList();

    cout << "\nFinding middle of l1:" << endl;
    l1.findMiddle();
    cout << endl;

    cout << "\nInserting duplicates into l1 and removing them:" << endl;
    l1.insert(7);
    l1.insert(7);
    l1.displayList();

    l1.removeDuplicates();
    cout << "After removing duplicates:" << endl;
    l1.displayList();

    cout << "\nMerging two sorted lists:" << endl;
    l1.displayList();
    l2.displayList();

    l1.mergeSortedList(l2);
    cout << "After merging:" << endl;
    l1.displayList();

    return 0;
}
