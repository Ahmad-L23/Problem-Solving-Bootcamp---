#include <iostream>
#include <string>
using namespace std;

// Reads a full string (including spaces) from the user
void readString(string& Text)
{
    cout << "Enter a string with uppercase letters: ";
    getline(cin, Text); // Use getline so spaces are included in the input
}

// Converts all uppercase letters in the string to lowercase
string toLowerCaseString(string text)
{
    // Loop through each character in the string
    for (int i = 0; i < text.length(); i++)
    {
        // ASCII codes: 'A' = 65, 'Z' = 90
        if (text[i] >= 65 && text[i] <= 90) // Check if the character is uppercase
            text[i] = tolower(text[i]); // Convert to lowercase
    }
    return text; // Return the modified string
}

// Prints the lowercase result
void printResult(string lowerText)
{
    cout << "Lowercase string: " << lowerText << endl;
}

int main()
{
    string Text; // Variable to store the original user input
    
    readString(Text); // Step 1: Read the string from the user
    
    // Step 2: Convert the string to lowercase
    // Step 3: Print the lowercase string
    printResult(toLowerCaseString(Text));

    return 0; 
}
