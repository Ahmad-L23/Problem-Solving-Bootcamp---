#include <iostream>
#include <vector>
using namespace std;

// Function to read a full sentence (can contain spaces) from the user
string readInput() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence); // read full line including spaces
    return sentence;
}

// Function to split the input sentence into words based on spaces
vector<string> splitWords(const string& sentence) {
    vector<string> words; // container for words
    string word = "";

    // Loop through each character in the sentence
    for (char ch : sentence) {
        if (ch == ' ') {
            // If space found, push the current word into the vector
            words.push_back(word);
            word = ""; // reset for the next word
        } else {
            // Otherwise keep building the current word
            word += ch;
        }
    }

    // Push the last word into the vector (important!)
    words.push_back(word);

    return words;
}

// Function to reverse the order of words and rebuild the sentence
string reverseWords(const vector<string>& words) {
    string reversed;

    // Traverse the words vector in reverse order
    for (int i = words.size() - 1; i >= 0; i--) {
        reversed += words[i]; // add current word
        if (i != 0) reversed += " "; // add space except after the last word
    }

    return reversed;
}

// Function to print the final reversed sentence
void printResult(const string& result) {
    cout << "Reversed sentence: " << result << endl;
}

int main() {
    // Step 1: Read the input sentence
    string sentence = readInput();

    // Step 2: Split the sentence into words
    vector<string> words = splitWords(sentence);

    // Step 3: Reverse the order of the words
    string reversedSentence = reverseWords(words);

    // Step 4: Print the reversed sentence
    printResult(reversedSentence);

    return 0; // end of program
}
