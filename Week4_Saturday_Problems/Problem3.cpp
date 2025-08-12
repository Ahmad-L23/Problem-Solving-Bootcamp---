#include <iostream>
using namespace std;

// Function to read a year from the user
int readYear() {
    int year;
    cout << "Enter a year to check if it is a leap year: "; // Prompt user for input
    cin >> year;  // Read the input year
    return year;  // Return the entered year to the caller
}

// Function to check if a given year is a leap year
bool isLeapYear(int year) {

    
    if (year % 400 == 0) {
        return true;  // Divisible by 400 → leap year
    }
    if (year % 4 == 0 && year % 100 != 0) {
        return true;  // Divisible by 4 but NOT by 100 → leap year
    }

    return false;     // Otherwise, NOT a leap year
}

// Function to display the result based on leap year check
void displayResult(int year) {
    if (isLeapYear(year))
        cout << year << " is a leap year." << endl;
    else
        cout << year << " is not a leap year." << endl;
}

int main() {
    int year = readYear();   // Call function to read year from user
    displayResult(year);     // Call function to display if it's leap or not
    return 0;                // Indicate successful program termination
}
