#include <iostream>
using namespace std;

double readBase() {
    double base;
    cout << "Enter the base (x): ";
    cin >> base;
    return base;
}

int readExponent() {
    int exponent;
    cout << "Enter the exponent (n): ";
    cin >> exponent;
    return exponent;
}

double calculatePower(double base, int exponent) {
    double result = 1.0;
    int absExponent = (exponent < 0) ? -exponent : exponent;

    for (int i = 0; i < absExponent; ++i) {
        result *= base;
    }

    if (exponent < 0)
        return 1.0 / result;
    else
        return result;
}

void displayPower(double base, int exponent) {
    double power = calculatePower(base, exponent);
    cout << base << " raised to the power " << exponent << " is: " << power << endl;
}

int main() {
    double x = readBase();
    int n = readExponent();
    displayPower(x, n);
    return 0;
}
