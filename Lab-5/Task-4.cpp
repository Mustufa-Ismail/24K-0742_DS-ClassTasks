#include <iostream>
using namespace std;

void printMatrix(char **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(char **board, int x, int y, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (board[i][y] == 'Q')
        {
            return false;
        }
    }

    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
    {

        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    for (int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++)
    {

        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

int solveNQueen(char **board, int x, int n)
{
    if (x == n)
    {
        printMatrix(board, n);
        cout << endl;
        return 1;
    }

    int count = 0;
    for (int y = 0; y < n; y++)
    {
        if (isSafe(board, x, y, n))
        {
            board[x][y] = 'Q';
            count += solveNQueen(board, x + 1, n);
            board[x][y] = '.';
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter the size of the board:";
    cin >> n;

    char **arr = new char *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new char[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = '.';
        }
    }

    int solutions = solveNQueen(arr, 0, n);

    if (solutions > 0)
    {
        cout << "Total solutions: " << solutions << endl;
    }
    else
    {
        cout << "No solution" << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}