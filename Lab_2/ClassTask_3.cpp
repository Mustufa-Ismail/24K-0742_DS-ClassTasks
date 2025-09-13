#include <iostream>
using namespace std;

int main()
{
    int no_team;
    cout << "Enter the number of teams:";
    cin >> no_team;

    int **score = new int *[no_team];
    int *sizes = new int[no_team];

    for (int i = 0; i < no_team; i++)
    {
        cout << "Enter the size of team " << i + 1 << ":";
        cin >> sizes[i];
    }

    for (int i = 0; i < no_team; i++)
    {
        score[i] = new int[sizes[i]];
    }

    for (int i = 0; i < no_team; i++)
    {
        cout << "Enter the scores of team " << i + 1 << ":";
        for (int j = 0; j < sizes[i]; j++)
        {
            cin >> score[i][j];
        }
    }

    for (int i = 0; i < no_team; i++)
    {
        cout << "Team " << i + 1 << ": \n";
        int sum = 0;
        for (int j = 0; j < sizes[i]; j++)
        {
            cout << score[i][j] << "\t";
            sum += score[i][j];
        }
        cout << "\n Total score: " << sum << endl;
    }

    for (int i = 0; i < no_team; i++)
    {
        delete[] score[i];
    }
    delete[] score;
    delete[] sizes;

    return 0;
}