#include <iostream>   // For input/output (cin, cout)
#include <vector>     // For using dynamic arrays (vector)
using namespace std;

// Function to read the user's monthly income
double readIncome() {
    double income;
    cout << "Enter your monthly income: ";
    cin >> income;   // Store the user input into the variable income
    return income;   // Return the income to the main function
}

// Function to read the number of expenses the user has
int readNumberOfExpenses() {
    int n;
    cout << "Enter the number of expenses you have: ";
    cin >> n;        // Store the number of expenses
    return n;        // Return it to main
}

// Function to read each expense amount
// It returns a vector containing all the expenses
vector<double> readExpenses(int n) {
    vector<double> expenses(n); // Create a vector of size n to store expenses
    cout << "Enter each expense amount one by one:\n";
    for (int i = 0; i < n; i++) {          // Loop from 0 to n-1
        cout << "Expense " << (i + 1) << ": ";
        cin >> expenses[i];                 // Store each expense in the vector
    }
    return expenses;                        // Return the filled vector
}

// Function to calculate the total of all expenses
double calculateTotalExpenses(const vector<double>& expenses) {
    double total = 0;                       // Initialize total to 0
    for (int i = 0; i < expenses.size(); i++) { // Loop through the vector
        total += expenses[i];               // Add each expense to total
    }
    return total;                           // Return the sum of expenses
}

// Function to calculate savings
double calculateSavings(double income, double totalExpenses) {
    return income - totalExpenses;          // Savings = income - expenses
}

// Function to display a summary of income, expenses, and savings
void displaySummary(double income, double totalExpenses, double savings) {
    cout << "\n----- Monthly Summary -----\n";
    cout << "Total Income: " << income << endl;         // Show income
    cout << "Total Expenses: " << totalExpenses << endl; // Show total expenses
    cout << "Savings: " << savings << endl;           // Show remaining savings
    cout << "---------------------------\n";
}

int main() {
    // Step 1: Read user's income
    double income = readIncome();

    // Step 2: Read the number of expenses
    int n = readNumberOfExpenses();

    // Step 3: Read each individual expense
    vector<double> expenses = readExpenses(n);

    // Step 4: Calculate total expenses
    double totalExpenses = calculateTotalExpenses(expenses);

    // Step 5: Calculate savings
    double savings = calculateSavings(income, totalExpenses);

    // Step 6: Display the summary to the user
    displaySummary(income, totalExpenses, savings);

    return 0;   // End of program
}
