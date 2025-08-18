#include <iostream>
#include <string>
using namespace std;

// Function to read a string input from the user
void readString(string& text)
{
    cout << "Enter a string: ";
    getline(cin, text);  // reads the whole line including spaces
}

// Custom function to convert lowercase letters to uppercase
char toUpperCustom(char ch)
{
    // if the character is between 'a' and 'z' in ASCII
    if (ch >= 'a' && ch <= 'z')
        return ch - 32;  // convert to uppercase by subtracting 32
    return ch;           // if not lowercase, return it unchanged
}

// Function to filter text: keep only letters and spaces, convert letters to uppercase
// NOTE: YOU CAN IMPROVE THIS LOGIC, BUT KEEP IT AS IT IS FOR NOW
string keepLettersSpacesAndUpper(string text)
{
    string result = "";

    // loop through each character in the input string
    for (int i = 0; i < text.length(); i++)
    {
        // if character is already uppercase A-Z
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            result += text[i];  // keep it
        }
        // if character is lowercase a-z
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            result += toUpperCustom(text[i]);  // convert to uppercase
        }
        // if character is a space
        else if (text[i] == ' ')
        {
            result += text[i];  // keep the space
        }
        // any other character (numbers, symbols, punctuation) is ignored
    }
    return result;
}

// Function to display the final result
void printResult(string result)
{
    cout << "Filtered and uppercase string: " << result << endl;
}

int main()
{
    string text;

    // Step 1: Read input from user
    readString(text);

    // Step 2: Process input (filter + uppercase)
    string filtered = keepLettersSpacesAndUpper(text);

    // Step 3: Print the processed result
    printResult(filtered);

    return 0;
}
