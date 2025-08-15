#include <iostream>
using namespace std;

// Reads a single uppercase character from the user
char readCharacter()
{
    char ch;
    cout << "Enter an uppercase letter: ";
    cin >> ch; // Input a single character
    return ch; // Return the entered character
}

// Converts an uppercase character to lowercase using ASCII values
char toLowerCase(char ch)
{
    // ASCII codes: 'A' = 65, 'Z' = 90
    // The difference between uppercase and lowercase letters is 32
    if (ch >= 65 && ch <= 90) // Check if the character is uppercase
        return ch + 32; // Convert to lowercase by adding 32
    return ch; // If it's not uppercase, return it unchanged
}

// Prints the lowercase letter
void printResult(char lower)
{
    cout << "Lowercase letter: " << lower << endl;
}

int main()
{
    // Step 1: Read the uppercase letter from the user
    char ch = readCharacter();
    
    // Step 2: Convert the letter to lowercase
    char lower = toLowerCase(ch);
    
    // Step 3: Display the result
    printResult(lower);

    return 0; // End of program
}
