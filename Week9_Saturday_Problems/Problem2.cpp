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

// Function to print the sum of a single row
void printRowSum(int rowNumber, int sum) {
    cout << "Row " << rowNumber + 1 << " sum = " << sum << "\n";
}

// Function to calculate and print the sum of each row separately
void rowWiseSum(int arr[][4], int rows, int cols) {
    for (int i = 0; i < rows; i++) {         // loop through each row
        int sum = 0;                         // reset sum for each row
        for (int j = 0; j < cols; j++)       // loop through columns of that row
            sum += arr[i][j];                // add each element to the row sum
        printRowSum(i, sum);                 // print the sum of this row
    }
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

    // Calculate and print sum of each row
    rowWiseSum(matrix, rows, cols);
}
