#include <iostream>

using namespace std;

class Node
{
public:
    int rollNo;
    string name;

    Node(string n, int r) : rollNo(r), name(n) {}
};

class HashTable
{
public:
    Node *arr[15];
    int count;

    HashTable() : count(0)
    {
        for (int i = 0; i < 15; i++)
        {
            arr[i] = nullptr;
        }
    }

    int hashing(int rollNo)
    {
        return rollNo % 15;
    }

    void insert(string n, int r)
    {
        if (count >= 15)
        {
            cout << "Table full";
            return;
        }

        Node *nn = new Node(n, r);
        int index = hashing(r);

        if (arr[index] == nullptr)
        {
            arr[index] = nn;
            count++;
            return;
        }

        for (int i = 1; i < 15; i++)
        {
            int curIndex = (index + i * i) % 15;
            if (arr[curIndex] == nullptr)
            {
                arr[curIndex] = nn;
                count++;
                return;
            }
        }
    }

    void searchRecord(int rollNo)
    {
        int index = hashing(rollNo);

        for (int i = 0; i < 15; i++)
        {
            int curIndex = (index + i * i) % 15;

            if (arr[curIndex] == nullptr)
                continue;

            if (arr[curIndex]->rollNo == rollNo)
            {
                cout << "Name: " << arr[curIndex]->name
                     << "\tRoll.No: " << arr[curIndex]->rollNo;
                return;
            }
        }

        cout << "\nRecord not found";
    }

    void display()
    {
        for (int i = 0; i < 15; i++)
        {
            cout << i << ":\t";
            if (arr[i] == nullptr)
            {
                cout << "Empty";
            }
            else
            {
                cout << "Name: " << arr[i]->name
                     << "\tRoll.No: " << arr[i]->rollNo;
            }
            cout << endl;
        }
    }
};

int main()
{
    HashTable h1;
    h1.insert("a", 123);
    h1.insert("b", 124);
    h1.insert("c", 456);

    h1.display();

    h1.searchRecord(124);
    h1.searchRecord(789);
}
