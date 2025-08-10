#include <iostream>
using namespace std;

// Enum to represent whether a number is a palindrome or not
enum enPalindromeStatus { NotPalindrome = 0, Palindrome = 1 };

// Function to read a positive integer from the user
int ReadPositvieNumber(string message)
{
    int number = 0;
    cout << message << endl; // Example: "Enter a positive number:"
    cin >> number;           // User enters: 12321
    return number;           // Returns 12321
}

// Function to reverse the digits of a given number
int ReverseNumber(int number)
{
    int reminder = 0, number2 = 0;

    // Example walkthrough: number = 12321
    while (number > 0)
    {
        reminder = number % 10;              // Step 1: reminder = 12321 % 10 = 1
        number /= 10;                        // Step 1: number = 12321 / 10 = 1232
        number2 = number2 * 10 + reminder;   // Step 1: number2 = 0 * 10 + 1 = 1

        // Step 2: reminder = 1232 % 10 = 2, number = 123, number2 = 1 * 10 + 2 = 12
        // Step 3: reminder = 3, number = 12, number2 = 12 * 10 + 3 = 123
        // Step 4: reminder = 2, number = 1, number2 = 123 * 10 + 2 = 1232
        // Step 5: reminder = 1, number = 0, number2 = 1232 * 10 + 1 = 12321
    }

    // Final reversed number is 12321
    return number2;
}

// Function to check if a number is a palindrome
enPalindromeStatus isPalindrom(int number)
{
    // A number is palindrome if it equals its reverse
    // Example: 12321 == ReverseNumber(12321) → true
    return (number == ReverseNumber(number)) ? Palindrome : NotPalindrome;
}

// Function to print whether the number is palindrome or not
void PrintResult(int Number)
{
    if (isPalindrom(Number) == Palindrome)
        cout << "It's a palindrome number" << endl;  // For 12321 → This will print
    else
        cout << "It's not a palindrome Number" << endl;
}

// Main function: entry point of the program
int main()
{
    // Step-by-step example:
    // 1. User enters 12321
    // 2. ReverseNumber returns 12321
    // 3. Since both are equal → "It's a palindrome number" is printed
    PrintResult(ReadPositvieNumber("Enter a positive number:"));
}
