#include "GuessTheNumber.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>

using namespace std;

GuessTheNumber::GuessTheNumber()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    secretNumber = rand() % 100 + 1;
    attempts = 0;
}

int GuessTheNumber::getGuess()
{
    string line;
    int guess;
    char extra;

    while (true)
    {
        cout << "Enter your guess (1-100): ";

        if (!getline(cin, line))
        {
            return 0;
        }

        stringstream input(line);

        if (input >> guess && !(input >> extra))
        {
            if (guess >= 1 && guess <= 100)
            {
                return guess;
            }
        }

        cout << "Please enter a whole number from 1 to 100.\n";
    }
}

bool GuessTheNumber::checkGuess(int guess)
{
    if (guess < secretNumber)
    {
        cout << "Too low! Try again.\n";
        return false;
    }

    if (guess > secretNumber)
    {
        cout << "Too high! Try again.\n";
        return false;
    }

    cout << "Correct!\n";
    return true;
}

void GuessTheNumber::play()
{
    cout << "Welcome to Guess the Number!\n";
    cout << "I picked a number from 1 to 100.\n";

    while (true)
    {
        int guess = getGuess();

        if (guess == 0)
        {
            cout << "\nGame ended.\n";
            return;
        }

        attempts++;

        if (checkGuess(guess))
        {
            cout << "You guessed the number in "
                 << attempts << " attempts.\n";
            return;
        }
    }
}