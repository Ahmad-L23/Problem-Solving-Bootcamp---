#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to read desired password length from user
int ReadLength() {
    int length;
    cout << "Enter password length: ";
    cin >> length;
    return length;
}

// Function to read user's yes/no option
// NOTE: the string parameter is passed by reference (const &),
//       which avoids making a copy and is more efficient.
bool ReadOption(const string &message) {
    char choice;
    cout << message << " (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

// Function to build a character set (charset) based on user choices
// It concatenates lowercase, uppercase, digits, and symbols if selected.
string BuildCharset(bool lower, bool upper, bool digits, bool symbols) {
    string charset = "";
    if (lower)
        charset += "abcdefghijklmnopqrstuvwxyz";
    if (upper)
        charset += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (digits)
        charset += "0123456789";
    if (symbols)
        charset += "!@#$%^&*()_+-=[]{}|;:,.<>?/";
    return charset;
}

// Function to return one random character from the charset
// NOTE: the string is passed by reference (const &).
char GetRandomChar(const string &charset) {
    return charset[rand() % charset.size()];
}

// Function to generate a password of given length
// by repeatedly selecting random characters from charset.
string GeneratePassword(int length, const string &charset) {
    string password = "";
    for (int i = 0; i < length; i++) {
        password += GetRandomChar(charset);
    }
    return password;
}

// Function to print the generated password
void PrintPassword(const string &password) {
    cout << "\nGenerated Password: " << password << endl;
}

int main() {
    // Initialize random number generator with current time
    srand(time(0));

    // Step 1: Read user inputs
    int length = ReadLength();
    bool lower = ReadOption("Include lowercase letters?");
    bool upper = ReadOption("Include uppercase letters?");
    bool digits = ReadOption("Include digits?");
    bool symbols = ReadOption("Include symbols?");

    // Step 2: Build the charset based on options
    string charset = BuildCharset(lower, upper, digits, symbols);

    // Step 3: Check if charset is empty (user didn't select any option)
    if (charset.empty()) {
        cout << "Error: No character types selected!" << endl;
        return 0;
    }

    // Step 4: Generate password and print it
    string password = GeneratePassword(length, charset);
    PrintPassword(password);

    return 0;
}
