#include <iostream>
using namespace std;

// Enum to represent different eligibility states
enum EligibilityStatus {
    Eligible,       // Eligible for a loan
    NotEligible,    // Not eligible for a loan
    InvalidInput    // Input is invalid (e.g., negative values)
};

// Function to read salary and age from the user
void readInputs(double &salary, int &age) {
    cout << "Enter monthly salary: ";
    cin >> salary;
    cout << "Enter age: ";
    cin >> age;
}

// Function to validate inputs (salary and age cannot be negative)
EligibilityStatus validateInputs(double salary, int age) {
    if (salary < 0) {
        cout << "Salary cannot be negative." << endl;
        return EligibilityStatus::InvalidInput;
    }
    if (age < 0) {
        cout << "Age cannot be negative." << endl;
        return EligibilityStatus::InvalidInput;
    }
    return EligibilityStatus::Eligible; // Inputs are valid
}

// Function to check eligibility based on rules
EligibilityStatus checkEligibility(double salary, int age) {
    const double minSalary = 500.0; // Minimum required salary
    const int minAge = 21;          // Minimum age requirement
    const int maxAge = 60;          // Maximum age limit

    // Check conditions for eligibility
    if (salary >= minSalary && age >= minAge && age <= maxAge)
        return EligibilityStatus::Eligible;
    else
        return EligibilityStatus::NotEligible;
}

// Function to print result message based on eligibility status
void printResult(EligibilityStatus status) {
    switch (status) {
        case EligibilityStatus::Eligible:
            cout << "Congratulations! You are eligible for a loan." << endl;
            break;
        case EligibilityStatus::NotEligible:
            cout << "Sorry, you are not eligible for a loan." << endl;
            break;
        case EligibilityStatus::InvalidInput:
            cout << "Invalid input provided. Cannot determine eligibility." << endl;
            break;
    }
}

int main() {
    double salary;
    int age;

    // Step 1: Read inputs from the user
    readInputs(salary, age);

    // Step 2: Validate inputs
    EligibilityStatus inputStatus = validateInputs(salary, age);
    if (inputStatus == EligibilityStatus::InvalidInput) {
        printResult(inputStatus);
        return 1; // Stop program if inputs are invalid
    }

    // Step 3: Check loan eligibility
    EligibilityStatus eligibility = checkEligibility(salary, age);

    // Step 4: Print the result
    printResult(eligibility);

    return 0; // End of program
}
