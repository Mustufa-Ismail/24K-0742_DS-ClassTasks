#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int *array;
    int size;
    int count;

public:
    DynamicArray() : size(10), count(0)
    {
        array = new int[10];
    }

    DynamicArray(int s) : size(s), count(0)
    {
        array = new int[size];
    }

    ~DynamicArray()
    {
        delete[] array;
        cout << "Array Deleted";
    }

    void resize()
    {
        size *= 2;

        int *newArr = new int[size];

        for (int i = 0; i < size / 2; i++)
        {
            newArr[i] = array[i];
        }

        delete[] array;
        array = newArr;
    }

    void push_back(int value)
    {
        if (size == count)
        {
            resize();
        }
        array[count] = value;
        count++;
    }

    void arrayPrinting()
    {
        for (int i = 0; i < count; i++)
        {
            cout << array[i] << endl;
        }
        cout << "Total Size: " << size << endl;
    }
};

int main()
{
    DynamicArray d1;
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);
    d1.push_back(4);
    d1.push_back(5);
    d1.push_back(6);
    d1.push_back(7);
    d1.push_back(8);
    d1.push_back(9);
    d1.push_back(10);
    d1.push_back(11);

    d1.arrayPrinting();

    return 0;
}