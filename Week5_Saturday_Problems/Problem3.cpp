#include <iostream>
#include <string>
using namespace std;

// Function to read a full line of text from the user
string readInput() {
    string text;
    cout << "Enter a string: ";
    getline(cin, text); // reads the entire line including spaces
    return text;
}

// Function to extract numbers (sequences of digits) from the input string
// Numbers are separated by spaces in the returned string
string extractNumbers(string text) {
    string numbers = "";  // to store all extracted numbers
    bool inNumber = false; // flag to check if we are currently inside a number

    for (char ch : text) {
        if (ch >= '0' && ch <= '9') {   // check if character is a digit
            numbers += ch;              // add digit to the result string
            inNumber = true;            // mark that we are inside a number
        }
        else {
            if (inNumber) {             // if we just finished a number
                numbers += ' ';         // add a space to separate numbers
                inNumber = false;       // reset the flag
            }
        }
    }

    // Remove the last space if it exists
    if (!numbers.empty() && numbers[numbers.size() - 1] == ' ')
        numbers.pop_back();

    return numbers;
}

// Function to print the extracted numbers or a message if none were found
void printNumbers(string numbers) {
    if (numbers.empty()) {
        cout << "No numbers found in the string." << endl;
    }
    else {
        cout << "Numbers in the string: " << numbers << endl;
    }
}

int main() {
    // Read input, extract numbers, and print them
    printNumbers(extractNumbers(readInput()));
    return 0;
}
