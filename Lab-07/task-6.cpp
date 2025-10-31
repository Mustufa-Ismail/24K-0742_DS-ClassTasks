#include <iostream>
using namespace std;

class Employee
{
public:
    string name;
    int id;
    double salary;

    Employee() : name(""), id(0), salary(0.0) {}
    Employee(string n, int i, double s) : name(n), id(i), salary(s) {}
};

void merge(Employee arr[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    Employee left[100];
    Employee right[100];

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[start + i];
    }

    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2)
    {
        if (left[i].salary >= right[j].salary)
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(Employee arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;
    mergesort(arr, start, mid);
    mergesort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{
    Employee employees[12] = {
        Employee("John Doe", 101, 75000),
        Employee("Jane Smith", 102, 82000),
        Employee("Bob Johnson", 103, 68000),
        Employee("Alice Brown", 104, 95000),
        Employee("Charlie Wilson", 105, 72000),
        Employee("Diana Lee", 106, 88000),
        Employee("Mike Davis", 107, 79000),
        Employee("Sarah Miller", 108, 91000),
        Employee("Tom Anderson", 109, 65000),
        Employee("Emily Clark", 110, 105000),
        Employee("David Taylor", 111, 83000),
        Employee("Lisa White", 112, 78000)};

    mergesort(employees, 0, 11);

    cout << "\nTop 3 Highest-Paid Employees:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". Name: " << employees[i].name << ", ID: " << employees[i].id
             << ", Salary: $" << employees[i].salary << endl;
    }

    return 0;
}