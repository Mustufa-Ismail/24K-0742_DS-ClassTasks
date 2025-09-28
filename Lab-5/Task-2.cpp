#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool findingPath(int **arr, int x, int y, int n, int **sol)
{
    if (x == (n - 1) && y == (n - 1))
    {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n))
    {
        sol[x][y] = 1;
        if (findingPath(arr, x + 1, y, n, sol))
        {
            return true;
        }

        if (findingPath(arr, x, y + 1, n, sol))
        {
            return true;
        }

        sol[x][y] = 0;
        return false;
    }
    return false;
}

void printMatrix(int **mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << " " << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 5;
    int **arr = new int *[n];
    int **sol = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        sol[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sol[i][j] = 0;
        }
    }

    int maze[5][5] = {{1, 0, 1, 0, 1},
                      {1, 1, 1, 1, 1},
                      {0, 1, 0, 1, 1},
                      {1, 0, 0, 1, 1},
                      {1, 1, 1, 0, 1}};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = maze[i][j];
        }
    }

    if (findingPath(arr, 0, 0, n, sol))
    {
        cout << "Solution:" << endl;
        printMatrix(sol, n);
    }
    else
    {
        cout << "No solution found";
    }
    return 0;
}