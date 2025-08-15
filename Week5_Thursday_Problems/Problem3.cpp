#include <iostream>
#include <string>
using namespace std;

// Reads a full string from the user (including spaces)
string readString()
{
    string text;
    cout << "Enter a string: ";
    getline(cin, text); // Use getline so spaces are included
    return text;
}

// Capitalizes the first letter of each word and makes other letters lowercase
string capitalizeWords(string text)
{
    bool newWord = true; // Flag to check if we're at the start of a new word

    // Loop through each character in the string
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ') // If the current character is a space
        {
            newWord = true; // The next character will be the start of a new word
        }
        else
        {
            if (newWord) // If this is the first character of a new word
            {
                // If it's lowercase, convert it to uppercase
                if (text[i] >= 'a' && text[i] <= 'z')
                    text[i] = toupper(text[i]);

                newWord = false; // We are now inside a word
            }
            else // We are inside a word (not the first letter)
            {
                // If it's uppercase, convert it to lowercase
                if (text[i] >= 'A' && text[i] <= 'Z')
                    text[i] = tolower(text[i]);
            }
        }
    }
    return text; // Return the modified string
}

// Prints the result
void printResult(string result)
{
    cout << "Capitalized string: " << result << endl;
}

int main()
{
    // Step 1: Read the input string from the user
    string text = readString();

    // Step 2: Process the string to capitalize each word
    string result = capitalizeWords(text);

    // Step 3: Display the result
    printResult(result);

    return 0; // End of program
}
