#include <iostream>
using namespace std;

// Function to read input values: 
// total number of problems in the contest (n)
// and the time reserved for going to the party (k).
void readInput(int &numberOfProblems, int &reservedMinutes) {
    cout << "Enter the total number of problems in the contest (n): ";
    cin >> numberOfProblems;
    cout << "Enter the number of minutes you need to reach the party (k): ";
    cin >> reservedMinutes;
}

// Function to calculate the time required to solve a problem.
// Problem i requires 5 * i minutes.
int problemTime(int problemIndex) {
    return 5 * problemIndex;
}

// Function to check if there is enough time left to solve a problem.
// If yes, it subtracts the time from the remaining time and returns true.
// Otherwise, it returns false.
bool canSolveProblem(int &remainingTime, int problemTime) {
    if (remainingTime >= problemTime) {
        remainingTime -= problemTime;  // Deduct time for this problem
        return true;
    }
    return false;
}

// Function to calculate the maximum number of problems that can be solved
// without being late to the party.
int maxProblemsSolved(int numberOfProblems, int reservedMinutes) {
    int remainingTime = 240 - reservedMinutes; // Total contest time is 240 minutes
    int solved = 0;

    // Try solving problems one by one in order
    for (int i = 1; i <= numberOfProblems; i++) {
        if (canSolveProblem(remainingTime, problemTime(i))) {
            solved++; // If solved, increase the counter
        } else {
            break; // Stop if not enough time for the next problem
        }
    }

    return solved;
}

// Function to print the result in a clear format.
void printResult(int solvedProblems) {
    cout << "Maximum number of problems you can solve and still reach the party: " 
         << solvedProblems << endl;
}

int main() {
    int numberOfProblems, reservedMinutes;

    // Step 1: Read input values from the user
    readInput(numberOfProblems, reservedMinutes);

    // Step 2: Calculate how many problems can be solved
    int solvedProblems = maxProblemsSolved(numberOfProblems, reservedMinutes);

    // Step 3: Print the result
    printResult(solvedProblems);

    return 0;
}
