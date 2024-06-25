#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand() % 100 + 1;
    
    int guess;
    int attempts = 0;
    const int maxAttempts = 5;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have chosen a number between 1 and 100. Try to guess it!" << endl;

    while (attempts < maxAttempts) {
        cout << "Enter your guess (attempt " << attempts + 1 << "/" << maxAttempts << "): ";
        cin >> guess;
        if (guess < 1 || guess > 100) {
            cout << "Invalid guess! Please enter a number between 1 and 100." << endl;
            continue; 
        }
        attempts++;

        if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number " << randomNumber << " correctly!" << endl;
            cout << "Number of attempts: " << attempts << endl;
            return 0; 
        }
    }
    cout << "Sorry, you have run out of attempts!" << endl;
    cout << "The correct number was: " << randomNumber << endl;

    return 0;
}

