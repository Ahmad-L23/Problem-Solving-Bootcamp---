#include <iostream>     // For input and output
#include <algorithm>    // For using the max() function
using namespace std;

// Function to read input values from the user
void ReadInputs(int& FirstBananaCost, int& InitialDollars, int& NumberOFBananas)
{
    cout << "Enter the cost of the first banana, the initial dollars you have, and the number of bananas you want to buy:\n";
    cin >> FirstBananaCost >> InitialDollars >> NumberOFBananas;
}

// Function to calculate the total cost of buying the bananas
// 1st banana = 1 * price
// 2nd banana = 2 * price
// 3rd banana = 3 * price
// and so on...
int totalCost(int FirstBananaCost, int NumberOFBananas) {
    int Sum = 0;
    for (int i = 1; i <= NumberOFBananas; i++) {
        Sum += i * FirstBananaCost;
    }
    return Sum;
}

// Function to calculate how much money the soldier needs to borrow
int amountToBorrow(int FirstBananaCost, int InitialDollars, int NumberOFBananas) {
    int Cost = totalCost(FirstBananaCost, NumberOFBananas);
    // If the cost is more than the dollars he has, return the difference
    // Otherwise, return 0 (no need to borrow)
    return max(0, Cost - InitialDollars);
}

// Function to print the result
void PrintBorrowedAmount(int BorrowedAmount)
{
    cout << "The soldier needs to borrow: " << BorrowedAmount << " dollars.\n";
}

// Main function
int main() {
    int FirstBananaCost = 0, InitialDollars = 0, NumberOFBananas = 0;

    // Read inputs from the user
    ReadInputs(FirstBananaCost, InitialDollars, NumberOFBananas);

    // Calculate and print how much needs to be borrowed
    int Borrowed = amountToBorrow(FirstBananaCost, InitialDollars, NumberOFBananas);
    PrintBorrowedAmount(Borrowed);

    return 0;
}
