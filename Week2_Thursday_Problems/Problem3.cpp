#include <iostream>     // For input and output
using namespace std;

// Function to read two numbers from the user
void readInputNumbers(int& number1, int& number2) {
    cout << "Enter two numbers separated by space: ";
    cin >> number1 >> number2;
}

// Function to add two numbers
int addNumbers(int number1, int number2) {
    return number1 + number2;
}

// Function to multiply two numbers
int multiplyNumbers(int number1, int number2) {
    return number1 * number2;
}

// Function to subtract second number from the first
int subtractNumbers(int number1, int number2) {
    return number1 - number2;
}

// Function to print all the results
void printResults(int number1, int number2) {
    cout << number1 << " + " << number2 << " = " << addNumbers(number1, number2) << endl;
    cout << number1 << " * " << number2 << " = " << multiplyNumbers(number1, number2) << endl;
    cout << number1 << " - " << number2 << " = " << subtractNumbers(number1, number2) << endl;
}

// Main function
int main() {
    int number1, number2;

    // Step 1: Read inputs from the user
    readInputNumbers(number1, number2);

    // Step 2: Perform and display calculations
    printResults(number1, number2);

    return 0;
}
