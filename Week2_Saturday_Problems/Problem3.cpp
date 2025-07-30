#include <iostream>  // For input and output
using namespace std;

// This function asks the user to enter their age in days and returns it
int readAgeInDays() {
    int n;
    cout << "Enter your age in total days (0 to 1000000): ";
    cin >> n;
    return n;
}

// This function calculates how many full years are in the given number of days
int getYears(int days) {
    return days / 365;  // 1 year = 365 days
}

// This function calculates how many full months remain after extracting the years
int getMonths(int days) {
    return (days % 365) / 30;  // 1 month = 30 days, after removing the years
}

// This function calculates the remaining days after extracting years and months
int getRemainingDays(int days) {
    return (days % 365) % 30;  // Remaining days after years and months
}

// This function prints the final age in years, months, and days
void printAge(int years, int months, int days) {
    cout << years << " years" << endl;
    cout << months << " months" << endl;
    cout << days << " days" << endl;
}

int main() {
    // Read the total age in days from the user
    int totalDays = readAgeInDays();

    // Convert total days into years, months, and days
    int years = getYears(totalDays);
    int months = getMonths(totalDays);
    int days = getRemainingDays(totalDays);

    // Print the result
    printAge(years, months, days);

    return 0;  // Indicate successful program end
}
