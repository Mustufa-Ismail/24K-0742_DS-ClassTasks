#include <iostream>
using namespace std;

class Matrix
{
private:
    int **data;
    int rows;
    int cols;

public:
    Matrix(int r, int c) : rows(r), cols(c)
    {
        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete data[i];
        }
        delete data;
    }

    void resize(int r, int c)
    {
        int newRows = r;
        int newCols = c;

        int **Newdata = new int *[newRows];
        for (int i = 0; i < newRows; i++)
        {
            Newdata[i] = new int[newCols];
        }

        for (int i = 0; i < newRows; i++)
        {
            for (int j = 0; j < newCols; j++)
            {
                Newdata[i][j] = 0;
            }
        }

        if (newRows >= rows && newCols >= rows)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    Newdata[i][j] = data[i][j];
                }
            }
        }
        else
        {
            for (int i = 0; i < newRows; i++)
            {
                for (int j = 0; j < newCols; j++)
                {
                    Newdata[i][j] = data[i][j];
                }
            }
        }
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete data;

        data = Newdata;
        rows = newRows;
        cols = newCols;
    }

    void printMatrix()
    {
        for (int i = 0; i < rows; i++)
        {
            cout << endl;
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] + 2 << " \t";
            }
        }
    }

    void inputMatrix()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "Input value at " << i + 1 << "," << j + 1 << ":";
                cin >> data[i][j];
            }
        }
    }

    void transpose()
    {
        for (int i = 0; i < rows; i++)
        {
            cout << endl;
            for (int j = 0; j < cols; j++)
            {
                cout << data[j][i] << " \t";
            }
        }
    }
};

int main()
{
    Matrix m1(2, 2);
    m1.inputMatrix();
    m1.resize(3, 3);
    m1.printMatrix();
    cout << "\n\n resize bigger:";
    m1.transpose();
    cout << "\n\n transpose:";
    m1.printMatrix();
    cout << "\n\n resize smaller:";
    m1.resize(1, 2);
    m1.printMatrix();

    return 0;
}
