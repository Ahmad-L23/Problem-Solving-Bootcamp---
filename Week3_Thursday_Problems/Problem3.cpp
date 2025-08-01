#include <iostream>
using namespace std;

int readNumber() {
    int number;
    cout << "Enter a number to calculate the sum of its digits: ";
    cin >> number;
    return number;
}

int calculateSumOfDigits(int number) {
    int sum = 0;
    number = (number < 0) ? -number : number;

    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

void displaySumOfDigits(int number) {
    int sum = calculateSumOfDigits(number);
    cout << "The sum of the digits of " << number << " is: " << sum << endl;
}


int main() {
    int number = readNumber();
    displaySumOfDigits(number);
    return 0;
}