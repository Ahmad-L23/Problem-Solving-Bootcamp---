#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time() to seed the random generator
using namespace std;

// Function to generate a random number between 'from' and 'to'
int randomNumber(int from, int to) {
    return from + rand() % (to - from + 1);
}

// Function to fill a 2D array (matrix) with random values
void fillArrayWithRandomValues(int arr[][4], int rows, int cols, int from, int to) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arr[i][j] = randomNumber(from, to); // Assign a random number to each element
}

// Function to print the matrix
void printMatrix(int arr[][4], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << "\t"; // Print each element with a tab space
        cout << "\n"; // Move to the next row
    }
    cout << "\n"; // Extra line for better readability
}

// Function to print the boundary elements of a matrix
void printBoundary(int boundary[], int size) {
    cout << "Boundary Elements: ";
    for (int i = 0; i < size; i++)
        cout << boundary[i] << " "; // Print each boundary element
    cout << "\n";
}

// Function to extract boundary elements of the matrix
void getBoundary(int arr[][4], int rows, int cols, int boundary[], int &size) {
    size = 0; // Initialize the size of boundary array
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            // Check if the element is in the first row, last row, first column, or last column
            if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1)
                boundary[size++] = arr[i][j]; // Add to boundary array and increase size
    printBoundary(boundary, size); // Print the boundary elements
}

int main() {
    srand(time(0)); // Seed the random number generator with current time

    const int rows = 4, cols = 4;
    int matrix[rows][cols]; // Matrix to store values
    int boundary[2*rows + 2*cols - 4]; // Maximum number of boundary elements
    int size; // To store actual number of boundary elements

    fillArrayWithRandomValues(matrix, rows, cols, 1, 99); // Fill matrix with random numbers

    cout << "Matrix:\n";
    printMatrix(matrix, rows, cols); // Display the matrix

    getBoundary(matrix, rows, cols, boundary, size); // Extract and print boundary elements
}
