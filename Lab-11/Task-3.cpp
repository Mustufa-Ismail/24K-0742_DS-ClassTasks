#include <iostream>
using namespace std;

class HashTable
{
public:
    int arr[10];
    int count;

    HashTable() : count(0)
    {
        for (int i = 0; i < 10; i++)
        {
            arr[i] = -1;
        }
    }

    int hashing(int n)
    {
        return n % 10;
    }

    void insert(int n)
    {
        if (count >= 10)
        {
            cout << "Table is full";
            return;
        }

        int index = hashing(n);
        if (arr[index] == -1)
        {
            arr[index] = n;
            count++;
            return;
        }
        else
        {
            for (int i = 0; i < 10; i++)
            {
                int curIndex = (index + i) % 10;
                if (arr[index] == -1)
                {
                    arr[curIndex] = n;
                    count++;
                    return;
                }
            }
        }
        return;
    }

    void search(int n)
    {
        int index = hashing(n);
        for (int i = 0; i < 10; i++)
        {
            int curIndex = (index + i) % 10;
            if (arr[curIndex] == n)
            {
                cout << n << " Found" << endl;
                return;
            }
        }
        cout << n << "Not found" << endl;
        return;
    }

    void deleteVal(int n)
    {
        int index = hashing(n);
        for (int i = 0; i < 10; i++)
        {
            int curIndex = (index + i) % 10;
            if (arr[curIndex] == n)
            {
                arr[curIndex] = -1;
            }
        }
        cout << n << " Not found" << endl;
        return;
    }

    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] == -1)
            {
                continue;
            }
            else
            {
                cout << arr[i] << endl;
            }
        }
    }
};

int main()
{
    HashTable h1;

    h1.insert(1);
    h1.insert(3);
    h1.insert(4);
    h1.insert(5);
    h1.insert(7);

    h1.display();

    h1.deleteVal(4);
    h1.display();

    h1.search(5);
    h1.search(6);

    return 0; h1.insert(1);
}