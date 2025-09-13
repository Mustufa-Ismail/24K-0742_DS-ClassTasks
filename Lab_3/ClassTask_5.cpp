#include <iostream>
using namespace std;

class Node
{
public:
    string data;
    Node *next;

    Node(string name) : data(name), next(nullptr) {}
};

class CircularLinkedList
{
public:
    Node *head;
    Node *tail;

    CircularLinkedList(Node *head) : head(head)
    {
        head->next = head;
        tail = head;
    }

    void addSongs(string name)
    {
        Node *nn = new Node(name);
        if (head == nullptr)
        {
            head = nn;
            head->next = nn;
            tail = head;
            return;
        }

        tail->next = nn;
        nn->next = head;
        tail = nn;
    }

    void display()
    {
        cout << "List:" << endl;
        Node *temp = head;
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl;
    }

    void play()
    {
        if (head == nullptr)
        {
            cout << "list is empty";
            return;
        }
        int count = 0;
        cout << "How many songs you want to play: ";
        cin >> count;
        Node *temp = head;
        for (int i = 0; i < count; i++)
        {
            cout << "Now Playing: " << temp->data << endl;
            temp = temp->next;
        }
    }

    void deleteSong(string name)
    {
        if (head == nullptr)
        {
            cout << "list is empty";
            return;
        }

        if (head->data == name)
        {
            Node *temp = head;
            if (head == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                tail->next = temp->next;
                head = tail->next;
            }
            delete temp;
            return;
        }

        Node *temp = head;
        do
        {
            if (temp->next->data == name)
            {
                Node *temp2 = temp->next;
                temp->next = temp2->next;

                if (temp2 == tail)
                {
                    tail = temp;
                }

                delete temp2;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Song not found" << endl;
    }
};

int main()
{
    Node *n1 = new Node("a");
    CircularLinkedList l1(n1);
    l1.addSongs("b");
    l1.addSongs("c");
    l1.addSongs("d");
    l1.display();

    l1.play();

    l1.deleteSong("c");
    l1.display();

    return 0;
}