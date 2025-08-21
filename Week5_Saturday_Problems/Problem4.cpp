#include <iostream>
#include <string>
using namespace std;

// Function to read a full line of text from the user
void readInputString(string& Text) {
    cout << "Enter a string: ";
    getline(cin, Text); // reads the entire line including spaces
}

// Function to extract the first and last letters of each word
void getFirstAndLastLetters(string text, string& firstLetters, string& lastLetters) {
    int start = 0; // keeps track of the beginning of each word

    // loop through every character in the string (including one extra step for the end)
    for (int i = 0; i <= text.size(); i++) {
        // A word ends when we hit a space OR reach the end of the string
        if (text[i] == ' ' || i == text.size()) {
            // make sure the word length is greater than 0 (ignore consecutive spaces)
            if (i - start > 0) {
                // take the first letter of the word
                firstLetters += text[start];
                // take the last letter of the word
                lastLetters += text[i - 1];
            }
            // update 'start' to the next word's beginning
            start = i + 1;
        }
    }
}

// Function to print the collected first and last letters side by side
void printFirstAndLastLetters(string firstLetters, string lastLetters) {
    cout << "First and last letters of each word:" << endl;

    // loop through each pair of collected letters
    for (int i = 0; i < firstLetters.size(); i++) {
        cout << firstLetters[i] << " " << lastLetters[i] << endl;
    }
}

int main() {
    string inputString;
    readInputString(inputString); // Step 1: read input from the user

    string firstLetters = "";
    string lastLetters = "";

    getFirstAndLastLetters(inputString, firstLetters, lastLetters); // Step 2: extract first & last letters
    printFirstAndLastLetters(firstLetters, lastLetters); // Step 3: print results

    return 0;
}
