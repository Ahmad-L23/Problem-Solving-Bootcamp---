// Count_Vowels : This program reads a sentence from the user,
// then counts and prints the number of vowels in each word.

#include <iostream>
#include <string>
using namespace std;

// Function to read a full line of text from the user
string readString()
{
    string Text = "";
    getline(cin, Text); // read entire line including spaces
    return Text;
}

// Function to check if a character is a vowel (a, e, i, o, u)
bool isVowel(char C)
{
    C = tolower(C); // convert character to lowercase for easier comparison
    if (C == 'a' || C == 'o' || C == 'u' || C == 'i' || C == 'e')
        return true;

    return false;
}

// Function to print a word and its vowel count
void print(string Word, int Counter)
{
    cout << Word << "  " << Counter << endl;
}

// Function to count vowels in each word of a sentence
void countVowel(string Text)
{
    int counter = 0;      // counts vowels in the current word
    string Word = "";     // holds the current word

    // Loop through each character in the text
    for (int i = 0; i < Text.size(); i++)
    {
        if (Text[i] != ' ') // if not a space, we are still inside a word
        {
            Word += Text[i];      // add character to current word
            if (isVowel(Text[i])) // check if it's a vowel
                counter++;        // increase vowel count
        }
        else // space found → word ended
        {
            print(Word, counter); // print word and its vowel count
            Word = "";            // reset for next word
            counter = 0;          // reset vowel counter
        }
    }

    // After the loop, check if last word exists (not followed by space)
    if (Word.size() != 0)
        print(Word, counter);
}

int main()
{
    string Text = readString(); // read input from user
    countVowel(Text);           // process and display results
}
