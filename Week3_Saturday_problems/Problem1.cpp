#include <iostream>
using namespace std;

// This function reads a positive number from the user
// Example: If the user types 123, it will return 123
int ReadPositvieNumber() {
    int number = 0;
    cout << "Please enter a number to reverse it:" << endl;
    cin >> number;  // User enters a number like 456
    return number;  // Returns 456
}

// This function takes an integer and returns its reverse
// Example: If input is 456 -> Output will be 654
int ReverseNumber(int number) {
    int reminder = 0;
    int reversedNumber = 0;

    // Let's assume number = 456
    // First iteration:
    //   reminder = 456 % 10 = 6
    //   reversedNumber = 0 * 10 + 6 = 6
    //   number = 456 / 10 = 45
    // Second iteration:
    //   reminder = 45 % 10 = 5
    //   reversedNumber = 6 * 10 + 5 = 65
    //   number = 45 / 10 = 4
    // Third iteration:
    //   reminder = 4 % 10 = 4
    //   reversedNumber = 65 * 10 + 4 = 654
    //   number = 4 / 10 = 0 (loop stops)

    while (number > 0) {
        reminder = number % 10;  // Get the last digit
        reversedNumber = reversedNumber * 10 + reminder;  // Build the reversed number
        number = number / 10;  // Remove the last digit
    }

    return reversedNumber;  // Final result: 654
}

// This function prints the reversed number to the screen
// Example: Input 456 -> Output: "Number after reversing: 654"
void PrintReversedNumber(int ReversedNumber) {
    cout << "Number after reversing: " << ReversedNumber << endl;
}

int main() {
    // We are combining all steps in one line:
    // 1. Ask user for input: e.g., 1234
    // 2. Reverse the number: 4321
    // 3. Print the result: "Number after reversing: 4321"
    PrintReversedNumber(ReverseNumber(ReadPositvieNumber()));

    return 0;
}
