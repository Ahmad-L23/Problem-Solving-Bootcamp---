#include <iostream>
#include <iomanip>
using namespace std;

// Function to read inputs (unit price and quantity) from the user
void readInputs(double &price, int &quantity) {
    cout << "Enter unit price: ";
    cin >> price;
    cout << "Enter quantity: ";
    cin >> quantity;
}

// Function to validate inputs (checks if price and quantity are not negative)
bool validateInputs(double price, int quantity) {
    if (price < 0) {
        cout << "Price cannot be negative." << endl;
        return false;
    }
    if (quantity < 0) {
        cout << "Quantity cannot be negative." << endl;
        return false;
    }
    return true; // valid inputs
}

// Function to calculate total cost before discount
double calculateTotal(double price, int quantity) {
    return price * quantity;
}

// Function to apply a bulk discount if quantity > threshold
double applyBulkDiscount(double total, int quantity) {
    const int threshold = 10;       // minimum quantity for discount
    const double discountRate = 0.15; // 15% discount
    return (quantity > threshold) ? total * (1 - discountRate) : total;
}

// Function to print the final total with 2 decimal places
void printTotal(double total) {
    cout << fixed << setprecision(2); // format output to 2 decimal places
    cout << "Total price after discount (if any): " << total << " JOD" << endl;
}

int main() {
    double price;
    int quantity;

    // Step 1: Read inputs from the user
    readInputs(price, quantity);

    // Step 2: Validate inputs
    if (!validateInputs(price, quantity)) {
        return 1; // exit program if invalid
    }

    // Step 3: Calculate the total before discount
    double total = calculateTotal(price, quantity);

    // Step 4: Apply bulk discount if applicable
    double finalTotal = applyBulkDiscount(total, quantity);

    // Step 5: Print the final total
    printTotal(finalTotal);

    return 0; // program ends successfully
}
