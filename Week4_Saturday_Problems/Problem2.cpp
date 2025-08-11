#include <iostream>
#include <string>
using namespace std;

string readRomanNumeral() {
    string roman;
    cout << "Enter a Roman numeral: ";
    cin >> roman;
    return roman;
}

int valueOfRomanChar(char c) {
    if (c == 'I') return 1;
    if (c == 'V') return 5;
    if (c == 'X') return 10;
    if (c == 'L') return 50;
    if (c == 'C') return 100;
    if (c == 'D') return 500;
    if (c == 'M') return 1000;
    return 0;
}

int convertRomanToInteger(string roman) {
    int total = 0;
    for (size_t i = 0; i < roman.size(); ++i) {
        int current = valueOfRomanChar(roman[i]);
        int next = (i + 1 < roman.size()) ? valueOfRomanChar(roman[i + 1]) : 0;

        if (current < next)
            total -= current;
        else
            total += current;
    }
    return total;
}

void displayResult(string roman) {
    int value = convertRomanToInteger(roman);
    cout << "The integer value of " << roman << " is: " << value << endl;
}

int main() {
    string roman = readRomanNumeral();
    displayResult(roman);
    return 0;
}
