#ifndef GUESS_THE_NUMBER_H
#define GUESS_THE_NUMBER_H

class GuessTheNumber
{
private:
    int secretNumber;
    int attempts;
    int getGuess();
    bool checkGuess(int guess);
public:
    GuessTheNumber();
    void play();
};

#endif