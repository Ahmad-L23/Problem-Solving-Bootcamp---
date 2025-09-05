#include <iostream>   // For input/output operations (cin, cout)
#include <iomanip>    // For manipulating output formatting (setprecision)
using namespace std;

// Function to read inputs from the user
// We pass the variables by reference (&) so the function can modify them directly
void readInputs(double &baseFare, double &ratePerKm, double &distance) {
    cout << "Enter base fare: ";
    cin >> baseFare; // Read base fare of the taxi ride

    cout << "Enter rate per km: ";
    cin >> ratePerKm; // Read rate per kilometer

    cout << "Enter distance traveled (in km): ";
    cin >> distance; // Read distance traveled
}

// Function to validate that the inputs are not negative
// Returns true if all inputs are valid, false otherwise
bool validateInputs(double baseFare, double ratePerKm, double distance) {
    if (baseFare < 0) { // Check if base fare is negative
        cout << "Base fare cannot be negative." << endl;
        return false;
    }
    if (ratePerKm < 0) { // Check if rate per km is negative
        cout << "Rate per km cannot be negative." << endl;
        return false;
    }
    if (distance < 0) { // Check if distance is negative
        cout << "Distance cannot be negative." << endl;
        return false;
    }
    return true; // All inputs are valid
}

// Function to calculate the total taxi fare
// Formula: fare = base fare + (distance * rate per km)
double calculateFare(double distance, double baseFare, double ratePerKm) {
    return baseFare + (distance * ratePerKm);
}

// Function to print the fare nicely formatted
void printFare(double fare) {
    cout << fixed << setprecision(2); // Show 2 decimal places
    cout << "Estimated Taxi Fare: " << fare << " JOD" << endl;
}

int main() {
    double baseFare, ratePerKm, distance;

    // Step 1: Read inputs from the user
    readInputs(baseFare, ratePerKm, distance);

    // Step 2: Validate the inputs
    // If invalid, exit the program with an error code (1)
    if (!validateInputs(baseFare, ratePerKm, distance)) {
        return 1;
    }

    // Step 3: Calculate the total fare
    double fare = calculateFare(distance, baseFare, ratePerKm);

    // Step 4: Print the calculated fare
    printFare(fare);

    return 0; // Program ended successfully
}
