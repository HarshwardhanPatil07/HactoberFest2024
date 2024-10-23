/**/

#include <iostream>
#include <cstdlib>
#include <ctime>

void guessTheNumber() { 

    while (true) {
        int numberToGuess = std::rand() % 1000 + 1;
        int guess;
        bool correct = false;

        std::cout << "I have a number between 1 and 1000.\n";
        std::cout << "Can you guess my number?\n";

        while (!correct) {
            std::cout << "Please type your guess: ";
            std::cin >> guess;

            if (guess < numberToGuess) {
                std::cout << "Too low. Try again.\n";
            } else if (guess > numberToGuess) {
                std::cout << "Too high. Try again.\n";
            } else {
                std::cout << "Excellent! You guessed the number!\n";
                correct = true;
            }
        }

        char playAgain;
        std::cout << "Would you like to play again (y or n)? ";
        std::cin >> playAgain;

        if (playAgain == 'n' || playAgain == 'N') {
            std::cout << "Thank you for playing! Goodbye!\n";
            break;
        }
    }    
}

int main() {
    guessTheNumber();
    return 0;
}
