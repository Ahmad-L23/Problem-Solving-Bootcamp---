/*
    Task:
    Write a program that keeps reading integers from the user and computes their sum.
    After entering each number, the user should be asked if they want to continue or stop.
    The program stops when the user enters 'N' or 'n' and then displays the total sum.
*/

#include <iostream>
using namespace std;

// Function to compute the sum of numbers until the user decides to stop
int computeSumUntilNo() {
    int sum = 0;              // Variable to store the running total sum
    int Number = 0;           // Variable to store the current number entered by the user
    char MoreNumbers = 'Y';   // Variable to check if user wants to continue (default to 'Y')

    cout << "Enter integers to sum. After each number, you can decide to continue or stop." << endl;

    // Loop to repeatedly read numbers and update the sum
    do {
        cout << "Enter number: ";
        cin >> Number;        // Read number from user
        sum += Number;        // Add number to the total sum

        cout << "Do You want To Add another number? Y/N: ";
        cin >> MoreNumbers;   // Ask if the user wants to continue
    } while (MoreNumbers != 'N' && MoreNumbers != 'n'); // Continue if not 'N' or 'n'

    return sum; // Return the final total sum
}

// Function to print the total sum
void printSum(int totalSum) {
    cout << "The total sum is: " << totalSum << endl;
}

// Main function: entry point of the program
int main() {
    int total = computeSumUntilNo(); // Call function to compute sum
    printSum(total);                 // Display the result
    return 0;
}
