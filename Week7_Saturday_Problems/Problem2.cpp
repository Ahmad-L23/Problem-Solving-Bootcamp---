#include <iostream>
#include <string>
using namespace std;

// Enum to represent supported currencies
enum Currency { JOD = 1, USD = 2, JPY = 3 };

// Function to read a positive number from the user
double ReadPositiveNumber(const string& message) {
    double num;
    do {
        cout << message << ": ";
        cin >> num;
    } while (num <= 0); // Keep asking until a positive number is entered
    return num;
}

// Function to select a currency from the user
Currency SelectCurrency(const string& prompt) {
    int choice;
    do {
        cout << prompt << " (1=JOD, 2=USD, 3=JPY): ";
        cin >> choice;
    } while (choice < 1 || choice > 3); // Keep asking until a valid choice
    return Currency(choice);
}

// Function to convert amount from one currency to another
double Convert(double amount, Currency from, Currency to) {
    if (from == to) return amount; // If currencies are same, no conversion needed

    // Conversion rates are hard-coded for simplicity
    if (from == Currency::JOD && to == Currency::USD)
        return amount * 0.71;

    if (from == Currency::JOD && to == Currency::JPY)
        return amount * 158.0;

    if (from == Currency::USD && to == Currency::JOD)
        return amount * 1.41;

    if (from == Currency::USD && to == Currency::JPY)
        return amount * 222.0;

    if (from == Currency::JPY && to == Currency::JOD)
        return amount * 0.0063;

    if (from == Currency::JPY && to == Currency::USD)
        return amount * 0.0045;

    return amount; // Default fallback
}

// Function to get currency name as string for printing
string CurrencyName(Currency c) {
    string names[] = { "JOD", "USD", "JPY" };
    return names[c - 1]; // Array index starts at 0, enum starts at 1
}

// Function to print conversion result in readable format
void PrintResult(double amount, Currency from, double result, Currency to) {
    cout << amount << " " << CurrencyName(from) << " = "
         << result << " " << CurrencyName(to) << endl;
}

// Main function: program execution starts here
int main() {
    double amount = ReadPositiveNumber("Enter the amount to convert"); // Input amount
    Currency from = SelectCurrency("Select currency to convert from"); // Input source currency
    Currency to = SelectCurrency("Select currency to convert to");     // Input target currency

    double result = Convert(amount, from, to); // Perform conversion
    PrintResult(amount, from, result, to);     // Show result

    return 0; // Program ends successfully
}
