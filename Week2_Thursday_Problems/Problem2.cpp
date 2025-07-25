#include <iostream>     // For input and output
#include <vector>       // For using vector to store multiple statements
#include <string>       // For using string data type
using namespace std;

// Function to read how many statements the user wants to enter
int readNumberOfStatements() {
    int numberOfStatements;
    cout << "Enter the number of statements: ";
    cin >> numberOfStatements;
    return numberOfStatements;
}

// Function to read all statements like ++X, X++, --X, X-- and store them in a vector
vector<string> readStatements(int numberOfStatements) {
    vector<string> statements(numberOfStatements);
    cout << "Enter each statement (like ++X, X++, --X, or X--):" << endl;

    for (int i = 0; i < numberOfStatements; ++i) {
        cout << "Statement " << i + 1 << ": ";
        cin >> statements[i];
    }

    return statements;
}

// Function to evaluate a single statement
// If it contains "++" → return +1
// If it contains "--" → return -1
int evaluateStatement(const string& statement) {
    // Check if it starts or ends with '+'
    if (statement[0] == '+' || statement[statement.size() - 1] == '+')
        return 1;
    // Otherwise, it's a '--' operation
    return -1;
}

// Function to compute the final result by applying all the statements
int computeFinalValue(const vector<string>& statements, int numberOfStatements) {
    int result = 0;

    for (int i = 0; i < numberOfStatements; ++i) {
        result += evaluateStatement(statements[i]);
    }

    return result;
}

// Function to print the final result
void printFinalValue(int finalValue) {
    cout << "The Final Result is: " << finalValue << endl;
}

// Main function that brings everything together
int main() {
    // Step 1: Read how many statements the user will enter
    int numberOfStatements = readNumberOfStatements();

    // Step 2: Read all the statements into a vector
    vector<string> statements = readStatements(numberOfStatements);

    // Step 3: Compute the final result after processing all statements
    int finalResult = computeFinalValue(statements, numberOfStatements);

    // Step 4: Print the final value
    printFinalValue(finalResult);

    return 0;
}
