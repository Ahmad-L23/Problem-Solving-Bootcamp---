#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
using namespace std;

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

// Function to print the main diagonal values
void printMainDiagonal(int diag[], int size) {
    cout << "Main Diagonal: ";
    for (int i = 0; i < size; i++)           // loop through diagonal elements
        cout << diag[i] << " ";              // print each diagonal element
    cout << "\n";
}

// Function to extract the main diagonal of the matrix
void mainDiagonal(int arr[][4], int diag[], int rows) {
    for (int i = 0; i < rows; i++)           // diagonal elements are arr[i][i]
        diag[i] = arr[i][i];                 // copy diagonal element to diag array
    printMainDiagonal(diag, rows);           // print the diagonal
}

int main() {
    srand(time(0));  // seed random generator with current time

    const int rows = 4, cols = 4;   // define matrix size
    int matrix[rows][cols], diag[rows];  // declare a 4x4 matrix and diagonal array

    // Fill the matrix with random numbers between 1 and 99
    fillArrayWithRandomValues(matrix, rows, cols, 1, 99);

    // Print the generated matrix
    cout << "Matrix:\n";
    printMatrix(matrix, rows, cols);

    // Extract and print the main diagonal
    mainDiagonal(matrix, diag, rows);
}
