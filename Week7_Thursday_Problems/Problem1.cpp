#include <iostream>
using namespace std;

// Enum to represent temperature units
// CELSIUS = 0, FAHRENHEIT = 1, INVALID = 2
enum TempUnit { CELSIUS, FAHRENHEIT, INVALID };

// Function to read a temperature value from the user
void readTemperature(double& temp) {
    cout << "Enter temperature value: ";
    cin >> temp; // store input in the reference variable 'temp'
}

// Function that converts a character (C/F) into the corresponding TempUnit
TempUnit getUnit(char unitChar) {
    if(unitChar == 'C' || unitChar == 'c') return CELSIUS;
    if(unitChar == 'F' || unitChar == 'f') return FAHRENHEIT;
    return INVALID; // if input is neither C nor F
}

// Function to ask the user for a temperature unit and return it as TempUnit
TempUnit readUnit() {
    char unitChar;
    cout << "Enter unit (C/F): ";
    cin >> unitChar;
    return getUnit(unitChar);
}

// Function to convert Celsius → Fahrenheit
double convertToFahrenheit(double celsius) {
    return celsius * 9.0 / 5.0 + 32;
}

// Function to convert Fahrenheit → Celsius
double convertToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

// Function to display the converted result
void printConversion(double temp, TempUnit unit) {
    switch(unit) {
        case CELSIUS: // If input was Celsius, convert to Fahrenheit
            cout << temp << "C = " << convertToFahrenheit(temp) << "F\n";
            break;
        case FAHRENHEIT: // If input was Fahrenheit, convert to Celsius
            cout << temp << "F = " << convertToCelsius(temp) << "C\n";
            break;
        default: // Invalid unit case
            cout << "Invalid unit!\n";
    }
}

int main() {
    double temp;             // variable to store temperature value
    readTemperature(temp);   // ask user for temperature
    TempUnit unit = readUnit(); // ask user for unit (C/F)
    printConversion(temp, unit); // perform conversion and show result
}
