#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
using namespace std;

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    // rand() % (range) gives a number between 0 and (range-1)
    // adding 'min' shifts the range to [min, max]
    return rand() % (max - min + 1) + min;
}

// Function to read the user's guess
int getUserGuess(int min, int max) {
    int guess;
    cout << "Guess a number between " << min << " and " << max << ": ";
    cin >> guess;
    return guess;
}

// Function to check if the guess is correct
bool isCorrectGuess(int guess, int number) {
    return guess == number;
}

// Function to print the result (correct or wrong)
void printResult(int guess, int number) {
    if(isCorrectGuess(guess, number))
        cout << "Correct! You guessed the number.\n";
    else
        cout << "Wrong! The number was " << number << ".\n";
}

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate a random number between 1 and 10
    int number = generateRandomNumber(1, 10);

    // Ask the user for their guess
    int guess = getUserGuess(1, 10);

    // Show whether the guess was correct or not
    printResult(guess, number);
}
