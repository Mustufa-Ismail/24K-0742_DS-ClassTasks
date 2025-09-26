#include <iostream>
using namespace std;

int sumDigits(int n)
{
    if (n == 0)
    {
        return n;
    }

    return (n % 10) + sumDigits(n / 10);
}

int nestedSumDigit(int n)
{
    if (n < 10)
    {
        return n;
    }
    else
    {
        return nestedSumDigit(sumDigits(n));
    }
}

int main()
{
    int n = 15;
    cout << nestedSumDigit(n);
}