#include <iostream>
using namespace std;

// Enum to represent the possible outcomes of the game series
enum enwinner { Anton, Danik, frienShip };

// Function to read the outcomes of each game from the user
void readGamesOutcome(string &gamesOutcome)
{
    cout << "Enter the outcome of each game as a string (A for Anton win, D for Danik win): ";
    cin >> gamesOutcome;
}

// Function to validate the user input to ensure only 'A' or 'D' are entered
void validateGamesOutcome(const string &gamesOutcome)
{
    for (int i = 0; i < gamesOutcome.length(); i++)
    {
        char ch = toupper(gamesOutcome[i]); // Convert character to uppercase for consistency
        if (ch != 'A' && ch != 'D') // Check if input is invalid
        {
            cout << "Invalid input detected at position " << i + 1
                 << ". Only 'A' or 'D' are allowed.\n";
            exit(1); // Terminate the program if invalid input is detected
        }
    }
}

// Function to determine the winner based on total wins
enwinner whoWins(int A, int D)
{
    if (A < D)
        return Danik; // Danik wins if he has more wins
    else if (A > D)
        return Anton; // Anton wins if he has more wins

    return frienShip; // It's a tie if both have equal wins
}

// Function to count wins and decide who is the winner
enwinner playGame(const string &gamesOutcome)
{
    int A = 0, D = 0; // Counters for Anton's and Danik's wins
    for (int i = 0; i < gamesOutcome.length(); i++)
    {
        if (toupper(gamesOutcome[i]) == 'A')
            A++; // Increment Anton's wins
        else
            D++; // Increment Danik's wins
    }
    return whoWins(A, D); // Determine winner based on counts
}

// Function to print the result in a readable format
void printWinner(enwinner winner)
{
    switch (winner)
    {
        case Anton: cout << "Anton wins!"; break;
        case Danik: cout << "Danik wins!"; break;
        case frienShip: cout << "It's a Friendship!"; break;
    }
}

// Main function: program execution starts here
int main()
{
    string gamesOutcome;

    readGamesOutcome(gamesOutcome); // Get user input
    validateGamesOutcome(gamesOutcome); // Validate input

    enwinner winner = playGame(gamesOutcome); // Determine winner
    printWinner(winner); // Display result

    return 0; // Program ends successfully
}
