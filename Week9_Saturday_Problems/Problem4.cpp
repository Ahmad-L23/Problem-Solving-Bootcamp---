#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
using namespace std;

// Enum to represent symmetric status
enum SymmetricStatus {
    SYMMETRIC,
    NOT_SYMMETRIC
};

// Function to generate a random number between 'from' and 'to'
int randomNumber(int from, int to) {
    return from + rand() % (to - from + 1);
}

// Function to fill a 2D array (matrix) with random numbers
void fillArrayWithRandomValues(int arr[][4], int rows, int cols, int from, int to) {
    for (int i = 0; i < rows; i++)           // loop through rows
        for (int j = 0; j < cols; j++)       // loop through columns
            arr[i][j] = randomNumber(from, to); // assign random value
}

// Function to print the matrix in tabular form
void printMatrix(int arr[][4], int rows, int cols) {
    for (int i = 0; i < rows; i++) {         // loop through rows
        for (int j = 0; j < cols; j++)       // loop through columns
            cout << arr[i][j] << "\t";       // print each element with tab space
        cout << "\n";                        // move to the next row
    }
    cout << "\n";
}

// Function to check if the matrix is symmetric
SymmetricStatus checkSymmetric(int arr[][4], int rows, int cols) {
    // A symmetric matrix must satisfy arr[i][j] == arr[j][i]
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] != arr[j][i])      // compare element with its transpose
                return NOT_SYMMETRIC;        // mismatch → not symmetric
    return SYMMETRIC;                        // all matched → symmetric
}

// Function to print the result (symmetric or not)
void printSymmetricStatus(SymmetricStatus status) {
    if (status == SYMMETRIC)
        cout << "Matrix is Symmetric\n";
    else
        cout << "Matrix is NOT Symmetric\n";
}

int main() {
    srand(time(0));  // seed random generator with current time

    const int rows = 4, cols = 4;   // define matrix size
    int matrix[rows][cols];         // declare a 4x4 matrix

    // Fill the matrix with random numbers between 1 and 99
    fillArrayWithRandomValues(matrix, rows, cols, 1, 99);

    // Print the generated matrix
    cout << "Matrix:\n";
    printMatrix(matrix, rows, cols);

    // Check and print if the matrix is symmetric
    SymmetricStatus status = checkSymmetric(matrix, rows, cols);
    printSymmetricStatus(status);
}
