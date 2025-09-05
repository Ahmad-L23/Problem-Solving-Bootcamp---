#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Define a structure to represent a bank client
// Each client has a name, password, and account balance
struct Client {
    string name;
    string password;
    double balance;
};

// Function to read the client's name
string readName() {
    string name;
    cout << "Enter your name: ";
    cin >> name;    // Input from user
    return name;    // Return the name to the caller
}

// Function to read the client's password
string readPassword() {
    string password;
    cout << "Enter your password: ";
    cin >> password; // Input from user
    return password; // Return the password to the caller
}

// Function to find the index of a client in the vector
// Returns -1 if client not found
int findClient(vector<Client> clients, string name, string password) {
    for (int i = 0; i < clients.size(); i++) { // Loop through all clients
        if (clients[i].name == name && clients[i].password == password) {
            return i; // Return index if credentials match
        }
    }
    return -1; // Client not found
}

// Function to read the withdrawal amount
double readAmount() {
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount; // Input from user
    return amount; // Return the amount
}

// Function to check if withdrawal is possible
bool canWithdraw(double balance, double amount) {
    return amount <= balance; // True if balance is enough
}

// Function to perform the withdrawal and update balance
// Note: In this version, client is passed by value, so balance won't update outside
void performWithdrawal(Client client, double amount) {
    client.balance -= amount; // Deduct the amount
    cout << "Withdrawal successful! New balance: " << client.balance << endl;
}

// Function to handle the withdrawal process
void processWithdrawal(vector<Client> clients) {
    string name = readName();        // Step 1: Read client name
    string password = readPassword();// Step 2: Read client password

    int index = findClient(clients, name, password); // Step 3: Find client

    if (index != -1) { // Client found
        double amount = readAmount(); // Step 4: Read withdrawal amount

        if (canWithdraw(clients[index].balance, amount)) { // Check balance
            performWithdrawal(clients[index], amount);     // Perform withdrawal
        }
        else {
            cout << "Insufficient balance." << endl;
        }
    }
    else { // Client not found
        cout << "Invalid name or password." << endl;
    }
}

// Main function
int main() {
    // Initialize a list of clients
    vector<Client> clients = {
        {"Ahmad", "1234", 500.0},
        {"Sajeda", "abcd", 1000.0},
        {"Adnan", "pass", 300.0}
    };

    // Start the withdrawal process
    processWithdrawal(clients);

    return 0; // Program ends successfully
}
