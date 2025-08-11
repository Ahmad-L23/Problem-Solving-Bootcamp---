#include <iostream>
#include <string>
using namespace std;

// Function to read a Roman numeral from the user
string readRomanNumeral() {
    string roman;
    cout << "Enter a Roman numeral: ";
    cin >> roman;
    return roman;
}

// Function that returns the integer value of a single Roman numeral character
int valueOfRomanChar(char c) {
    // We use a switch statement to match each Roman symbol to its value
    switch (c) {
        case 'I': return 1;    // I = 1
        case 'V': return 5;    // V = 5
        case 'X': return 10;   // X = 10
        case 'L': return 50;   // L = 50
        case 'C': return 100;  // C = 100
        case 'D': return 500;  // D = 500
        case 'M': return 1000; // M = 1000
        default: return 0;     // For invalid characters
    }
}

// Function to convert a Roman numeral string to an integer
int convertRomanToInteger(string roman) {
    int total = 0;

    // Loop through each character of the Roman numeral
    for (size_t i = 0; i < roman.size(); ++i) {
        int current = valueOfRomanChar(roman[i]); // value of current character
        int next = (i + 1 < roman.size()) ? valueOfRomanChar(roman[i + 1]) : 0; // value of next character

        // Roman numeral rule: if current value is smaller than next value, subtract it
        // Example: "IX"
        // I (1) < X (10) → subtract 1 instead of adding
        if (current < next)
            total -= current;
        else
            total += current;
    }
    return total;
}

// Function to display the result
void displayResult(string roman) {
    int value = convertRomanToInteger(roman);
    cout << "The integer value of " << roman << " is: " << value << endl;
    // Example walkthrough:
    // If roman = "MCMIV":
    // M (1000) → total = 1000
    // C (100) < M (1000) → subtract 100 → total = 900
    // M (1000) → add → total = 1900
    // I (1) < V (5) → subtract 1 → total = 1899
    // V (5) → add → total = 1904
}

// Main function
int main() {
    string roman = readRomanNumeral(); // Step 1: Get Roman numeral from user
    displayResult(roman);              // Step 2: Show conversion result
    return 0;
}
