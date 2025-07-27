/*
    Task:
    Write a program that checks if a given number is "lucky".
    A number is considered lucky if it consists of exactly two digits (a and b),
    and either digit divides the other evenly.

    Example:
    Input: 42  → Output: YES (because 4 % 2 == 0)
    Input: 35  → Output: NO  (3 % 5 != 0 and 5 % 3 != 0)
*/

#include <iostream>
using namespace std;

// Function to read an integer from user
int readNumber() {
    int n;
    cout << "Enter a two-digit number to check if it's lucky: ";
    cin >> n;
    return n;
}

// Function to check if the number is "lucky" based on divisibility of its digits
bool isLucky(int n) {
    int a = n / 10; // First digit (tens place)
    int b = n % 10; // Second digit (units place)

    // If any digit is zero, not lucky (to avoid division by zero)
    if (a == 0 || b == 0)
        return false;

    // Check if one digit divides the other
    return (a % b == 0 || b % a == 0);
}

// Function to print the result
void printResult(bool result) {
    if (result)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

// Main function: entry point of the program
int main() {
    int n = readNumber();           // Read number from user
    bool result = isLucky(n);      // Determine if number is lucky
    printResult(result);           // Display result
    return 0;
}
