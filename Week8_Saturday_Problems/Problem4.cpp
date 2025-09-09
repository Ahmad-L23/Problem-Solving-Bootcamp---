#include <iostream>
using namespace std;

// Function to read the amount of cash the user wants to withdraw
int readCashAmount() {
    int cash;
    cout << "Enter the amount of cash you want to withdraw: ";
    cin >> cash;
    return cash;
}

// Function to calculate how many bills of a given denomination can fit into the cash
int billsForDenomination(int cash, int denomination) {
    return cash / denomination;
}

// Function to calculate the remaining cash after using as many bills 
// of the current denomination as possible
int remainingCash(int cash, int denomination) {
    return cash % denomination;
}

// Function to calculate the minimum number of bills required 
// using available denominations {100, 20, 10, 5, 1}
int calculateMinimumBills(int cash) {
    int bills = 0;  // Counter for total bills
    int denominations[] = {100, 20, 10, 5, 1};  // Available bill values

    int i = 0;
    // Process each denomination starting from the largest (greedy approach)
    while (i < 5 && cash > 0) {
        // Count how many bills of the current denomination are needed
        bills += billsForDenomination(cash, denominations[i]);

        // Update remaining cash after using those bills
        cash = remainingCash(cash, denominations[i]);

        // Move to the next smaller denomination
        i++;
    }

    return bills;
}

// Function to print the result
void printResult(int bills) {
    cout << "Minimum number of bills needed: " << bills << endl;
}

int main() {
    // Step 1: Read the amount of cash from the user
    int cash = readCashAmount();

    // Step 2: Calculate the minimum number of bills required
    int bills = calculateMinimumBills(cash);

    // Step 3: Print the result
    printResult(bills);

    return 0;
}
