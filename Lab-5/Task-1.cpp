#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void recursiveGuessing(int number, int player)
{
    int guess;
    cout << "Guess the number (player " << player << "  ):";
    cin >> guess;

    if (guess == number)
    {
        cout << "Player " << player << " wins the game";
        return;
    }

    if (guess > number)
    {
        cout << "Number is high\n";
    }
    else if (guess < number)
    {
        cout << "Number is low\n";
    }

    if (player == 1)
    {
        recursiveGuessing(number, 2);
    }
    else if (player == 2)
    {
        recursiveGuessing(number, 1);
    }
}

int main()
{
    srand(time(0));

    int n = rand() % 100;

    int player = 1;

    recursiveGuessing(n, player);

    return 0;
}