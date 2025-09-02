#include <iostream>
using namespace std;

// Maximum possible number of elements
const int MAX_SIZE = 1000;

// Function to read the number of elements from the user
int readSize() {
    int n;
    cout << "How many elements do you want to enter? ";
    cin >> n;

    // Validate input (must be between 1 and MAX_SIZE)
    while (n <= 0 || n > MAX_SIZE) {
        cout << "Invalid input! Enter a number between 1 and " << MAX_SIZE << ": ";
        cin >> n;
    }
    return n;
}

// Function to read elements from the user
// NOTE: arrays in C++ are passed by reference automatically,
//       so changes here affect the original array in main().
void readElements(int elements[], int n) {
    cout << "Enter " << n << " elements (0 to " << MAX_SIZE-1 << "):\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        // Validate each element (must be within [0, MAX_SIZE-1])
        while (x < 0 || x >= MAX_SIZE) {
            cout << "Element out of range! Enter again: ";
            cin >> x;
        }

        // Store element in array
        elements[i] = x;
    }
}

// Function to count frequency of each element
// NOTE: arrays are passed by reference, so freq[] will be updated directly.
void countFrequency(const int elements[], int n, int freq[]) {
    for (int i = 0; i < n; i++) {
        // Use the element value as an index in freq[]
        freq[elements[i]]++;
    }
}

// Function to print all unique elements and their frequencies
void printUniqueElementsWithCount(const int freq[]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (freq[i] > 0) {
            cout << "Element " << i << " occurs " << freq[i] << " times.\n";
        }
    }
}

int main() {
    // Array to store user input
    int elements[MAX_SIZE];

    // Frequency array initialized with 0
    int freq[MAX_SIZE] = {0};

    // Step 1: Read size of the array
    int n = readSize();

    // Step 2: Read elements from user
    readElements(elements, n);

    // Step 3: Count frequency of each element
    countFrequency(elements, n, freq);

    // Step 4: Display results
    cout << "Unique elements with their repetition count:\n";
    printUniqueElementsWithCount(freq);

    return 0;
}
