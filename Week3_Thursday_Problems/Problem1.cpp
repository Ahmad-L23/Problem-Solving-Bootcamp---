#include <iostream>
using namespace std;

int readInput() {
    int number;
    cout << "Enter a positive integer to check if it is a perfect number: ";
    cin >> number;
    return number;
}

int calculateSumOfDivisors(int number) {
    int sum = 0;
    for (int i = 1; i <= number / 2; ++i) { 
        if (number % i == 0)  
            sum = sum + i;    
    }
    return sum;
}

bool isPerfectNumber(int number) {
    
    return calculateSumOfDivisors(number) == number;
}

void displayResult(int number) {
    if (isPerfectNumber(number))
        cout << number << " is a perfect number." << endl;
    else
        cout << number << " is not a perfect number." << endl;
}

int main() {
    int inputNumber = readInput();
    displayResult(inputNumber);
    return 0;
}

// 1 2 4 6 8 12 => 33
