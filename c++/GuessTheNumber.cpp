#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0)); 
    int secretNumber = rand() % 100 + 1;
    int guess;
    int tries = 0;
    bool playAgain = true;

    cout << "\n-------------------|  Guess the Number Challenge  |-------------------" << endl;
    cout << "\n--->  I'm thinking of a number between 1 and 100. Can you guess what it is?" << endl;
    
    cout << "\n\n-------------------------|  How to Play  |-----------------------" << endl << endl;
    cout << "--> Simply enter a number and try to guess the secret number." << endl;
    cout << "--> You have unlimited attempts. I'll provide hints if your guess is too high or too low." << endl;
    cout << "--> If you guess correctly, I'll congratulate you!" << endl;

    do {
        cout << "\nEnter your guess: ";
        cin >> guess;
        tries++;

        if (guess > secretNumber) 
        {
            cout << "Your guess is too high! Try again." << endl;
        }

        else if (guess < secretNumber) 
        {
            cout << "Your guess is too low! Try again." << endl;
        }

        else 
        {
            cout << "Congratulations! You guessed the number in " << tries << " tries." << endl;
            cout << "\nDo you want to play again? (y/n): ";
            
            char playAgainChoice;
            cin >> playAgainChoice;
            
            if (playAgainChoice == 'y' || playAgainChoice == 'Y') 
            {
                secretNumber = rand() % 100 + 1;
                tries = 0;
            } 
            
            else 
            {
                playAgain = false;
            }
        }
    }

    while (playAgain);
    cout << "\nThanks for playing!" << endl;
    
    system("pause");
    return 0;
}