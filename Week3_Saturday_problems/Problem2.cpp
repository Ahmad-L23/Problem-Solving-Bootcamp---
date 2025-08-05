#include <iostream>
using namespace std;

// Enum to represent whether a number is prime or not
enum enPrimeNotPrime { prime = 1, notPrime = 2 };

// Function to read a positive number from the user
int ReadPositiveNumber()
{
    int number = 0;

    cout << "Please enter a positive number: ";
    cin >> number;

    return number;
}

// Function to check if a number is prime or not
enPrimeNotPrime CheckPrime(int& number)
{
    // We only need to check divisibility up to number / 2
    // Here's why:
    // If a number n is not prime, then it must be divisible by another number a such that:
    //     n = a * b
    // If both a and b were greater than n/2, then a * b would be greater than n, which is impossible.
    // Therefore, at least one of them must be ≤ n/2.
    // So, if no number from 2 to n/2 divides n, it means n has no other divisors and is prime.

    int m = round(number / 2);

    // Loop through all numbers from 2 to number/2
    for (int i = 2; i <= m; i++)
    {
        if (number % i == 0) // If divisible, then it's not a prime number
            return enPrimeNotPrime::notPrime;
    }

    return enPrimeNotPrime::prime; // If no divisor found, it's a prime number
}

// Function to print all prime numbers from 1 to the given number
void PrintPrimeNumbersForm1ToN(int number)
{
    cout << "\n";

    cout << "Prime Numbers from " << 1 << " To " << number;
    cout << " are : " << endl;

    // Loop from 1 to the given number
    for (int i = 1; i <= number; i++)
    {
        // Check if the current number is prime
        if (CheckPrime(i) == enPrimeNotPrime::prime)
        {
            cout << i << endl; // Print it if it's prime
        }
    }
}

// Main function
int main()
{
    // Read a positive number from the user and print all prime numbers up to that number
    PrintPrimeNumbersForm1ToN(ReadPositiveNumber());
}
